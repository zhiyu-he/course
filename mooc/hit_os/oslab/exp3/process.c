#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <sys/times.h>

#define HZ	100

void cpuio_bound(int last, int cpu_time, int io_time);
static int p_amount = 5;

int main(int argc, char * argv[])
{	
	pid_t childs[p_amount];
	int i = 0, status =0;
	for(i = 0; i < p_amount; i++)
	{
		childs[i] = fork();
		if (childs[i] == 0)
		{
			int delta = (i+1)*2;
			printf("last: %d cpu: %d io: %d pid: %d\n", 10, 10-delta, delta, getpid());
			cpuio_bound(10, 10-delta, delta);
			printf("cpuio_bound done\n");
			return 0;
		}
		else if (childs[i] == -1)
		{
			printf("fork() failed\n");
			return -1;
		} else {

		}
	}
	for(i = 0; i < p_amount; i++)
	{
		pid_t cpid = waitpid(childs[i], &status, 0);
		printf("child %d status: %d \n", cpid, status);
	}
	return 0;
}

/*
 * 此函数按照参数占用CPU和I/O时间
 * last: 函数实际占用CPU和I/O的总时间，不含在就绪队列中的时间，>=0是必须的
 * cpu_time: 一次连续占用CPU的时间，>=0是必须的
 * io_time: 一次I/O消耗的时间，>=0是必须的
 * 如果last > cpu_time + io_time，则往复多次占用CPU和I/O
 * 所有时间的单位为秒
 */
void cpuio_bound(int last, int cpu_time, int io_time)
{
	struct tms start_time, current_time;
	clock_t utime, stime;
	int sleep_time;

	while (last > 0)
	{
		/* CPU Burst */
		times(&start_time);
		/* 其实只有t.tms_utime才是真正的CPU时间。但我们是在模拟一个
		 * 只在用户状态运行的CPU大户，就像“for(;;);”。所以把t.tms_stime
		 * 加上很合理。*/
		do
		{
			times(&current_time);
			utime = current_time.tms_utime - start_time.tms_utime;
			stime = current_time.tms_stime - start_time.tms_stime;
		} while ( ( (utime + stime) / HZ )  < cpu_time );
		last -= cpu_time;

		if (last <= 0 )
			break;

		/* IO Burst */
		/* 用sleep(1)模拟1秒钟的I/O操作 */
		sleep_time=0;
		while (sleep_time < io_time)
		{
			sleep(1);
			sleep_time++;
		}
		last -= sleep_time;
	}
}

