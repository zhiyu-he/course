### ChangeLog
* 2010-05-04
	* 补充进程运行轨迹与统计的相关源文件
* 2019-04-30
	* 完成进程运行轨迹与统计实验
* 2019-01-28
	* 完成系统调用实验
* 2019-01-23
	* 完成计算机启动实验

### 实验内容

1. 修改steup.s的需要重新指定es寄存器, 比较奇怪为什么指定ds不可以,而是一定要指定es？ ~~@2019-01-23~~
	* 因为在显示的时候,bp的寻址是通过`es:bp`来定位字符串的, 这个可以参考`BIOS中断,0x10,功能号13` @2019-1-27

2. 汇编中的call调用, 涉及哪些寄存器, 是如何协同工作的? @2019-01-28
3. syscall是如何实现的? ~~@2019-01-28~~
	* 需要做的修改
		* linux/include/unistd.h,    添加函数定义
		* linux/include/linux/sys.h, 修改sys_call_table
		* linux/kernal/system_call.s 修改nr_system_calls
		* linux/kernal/who.c         syscall的实现
	* 相关的知识点
		* 如何做将用户态的字符串,保存到内核态?
		* 用户态和内核态数据的双向传递,如何实现?

4. 进程运行轨迹的跟踪与统计 ~~@2019-04-30~~
    * 核心的文件
    	* init/main.c
    	* kernal/fork.c
    	* kernal/exit.c
    	* kernal/sched.c
    	* include/linux/sched.h
    * 相关的知识点
    	* 进程的结构、进程的状态、进程的调度
    * 相关数据文件
    	* process.log
    		* 对于process.log中的关键进程描述如下`pid-cpu时间-io时间, 单位s`
    		* 13-8-2
    		* 14-6-4
    		* 15-3-6
    		* 16-2-8
    		* 17-0-10
    		
    	* process.c
