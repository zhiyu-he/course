extern int whoami();
extern int iamis();

fn_ptr sys_call_table[] = {
    whoami, iamis
};
