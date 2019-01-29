1. 修改steup.s的需要重新指定es寄存器, 比较奇怪为什么指定ds不可以,而是一定要指定es？ ~~@2019-01-23~~
	* 因为在显示的时候,bp的寻址是通过`es:bp`来定位字符串的, 这个可以参考`BIOS中断,0x10,功能号13` @2019-1-27

2. 汇编中的call调用, 涉及哪些寄存器, 是如何协同工作的? @2019-01-28
3. syscall是如何实现的? @2019-01-28
	* 需要做的修改
		* linux/include/unistd.h, 添加函数定义, 是否要宏展开呢?
		* linux/include/linux/sys.h extern
		* linux/kernal/system_call.s 修改nr_system_calls
		* linux/kernal/who.c ?? 为什么不放到lib里呢？
	* 相关的知识点
		* 如何做将用户态的字符串,保存到内核态?
		* 用户态和内核态数据的双向传递,如何实现?