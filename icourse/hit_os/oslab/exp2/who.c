#define __LIBRARY__
#include <unistd.h>

_syscall1(int, iamis, const char*, name);        /* iamis()在用户空间的接口函数 */
_syscall2(int, whoami,char*,name,unsigned int,size);    /* whoami()在用户空间的接口函数 */


char msg[24];

int sys_iamis(const char *name) {
    int idx = 0;
    char c;
    while(c=get_fs_byte(name)) {
        if (c == '/') {
            break;
        }
        msg[idx++]=c;
    }
    msg[idx] = '\0';
    return 0;
}

int sys_whoami(char *name, unsigned int size) {
    unsigned int s = size;
    if (s > sizeof(msg)) {
        s = sizeof(msg);
    }
    for(int i = 0; i < s; i++) {
        put_fs_byte(msg[i], name++);
    }
    return 0;
}
