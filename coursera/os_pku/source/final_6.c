#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>


static int a = 0;
int main() {
    pid_t processID1, processID2;

    processID1 = fork();
    a++;

    if (processID1 == 0) {
        // child
        processID2 = fork();
        a++;
        if (processID2 == 0) {
            printf("child's child a=%d\n", a);
        } else {
            printf("child a=%d\n", a);
        }
    } else {
        printf("father a=%d\n", a);
    }
    int t = 1<<20;
    while(t--) {}
    return 0;
}
