#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>


int main() {
    char* path = "/tmp/hzy_dir";
    int status = mkdir(path, S_IRWXU| S_IRWXG);
    printf("%d\n", status);
    return 0;
}
