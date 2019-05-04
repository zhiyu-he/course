#define __LIBRARY__
#include <unistd.h>

char msg[24];

int sys_iamis(const char *name) {
    // todo to protect msg buffer
    int idx = 0;
    char c;
    while(c=get_fs_byte(name)) {
        msg[idx++]=c;
        if (c == '\0') {
            break;
        }
    }
    return 0;
}

int sys_whoami(char *name, unsigned int size) {
    // todo need param check!
    unsigned int s = size;
    if (s > sizeof(msg)) {
        s = sizeof(msg);
    }
    int i = 0;
    while(msg[i]) {
        put_fs_byte(msg[i], name++);
        i++;
    }
    return 0;
}
