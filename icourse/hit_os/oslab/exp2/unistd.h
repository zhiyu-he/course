#define __NR_whoami	72
#define __NR_iamis  73

int whoami(char *name, unsigned int size);
int iamis(const char *name);

