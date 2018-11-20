#include <stdio.h>


int main(int argc, char **argv) {
    
    while(1) {
        printf("myval: %d %p\n", argc, &argc);
    }
    return 0;
}
