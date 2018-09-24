### LiveOverflow Binary Hacking

> [Video-Link-Address](https://www.youtube.com/watch?v=iyAyN3GFM7A&list=PLhixgUqwRTjxglIswKp9mpkfPNfHkzyeN)


#### 0x00--Introduction and Backstory 

讲述了作者的故事, 一名真正的Geek, 执着, 保持好奇, 保持行动


#### 0x01--Installation and the Terminal

一些基础的命令: ls, cd, mkdir, touch, man, hexdump

e.g. `cat README.md | hexdump`


#### 0x02--Writing a simple Program in C

讨论了关于`PATH`, `C`, `vim`的概念

#### 0x03--Introduction to programming in Python

1. 简单的`python`小程序
2. 以及一个[`#!`的来源](https://en.wikipedia.org/wiki/Shebang_(Unix)) 

#### 0x04--How a CPU works and Introduction to Assembler

1. `CPU`以及`Registers`的概念
    * `program counter (PC)`, 被称为`instruction pointer (IP)`
    * `SI`, 数据索引, 从string中读取数据; `esi` may be 常量?
    * `DI`, 
2. 一些指令`Moves`, `Jumps`, `Branches` 以及 `Calls`
3. `Stack` with `PUSH/POP`
4. [请读至少3遍, 亦可赛艇](https://sockpuppet.org/issue-79-file-0xb-foxport-hht-hacking.txt.html)
5. [Memory Hierarchy: Of Registers, Cache & Memory](https://software.intel.com/en-us/blogs/2015/06/11/advanced-computer-concepts-for-the-not-so-common-chef-memory-hierarchy-of-registers)
6. [Software Techniques for Shared-Cache Multi-Core Systems](https://software.intel.com/en-us/articles/software-techniques-for-shared-cache-multi-core-systems)


#### 0x05--Reversing and Cracking first simple Program

1. `install gdb  // brew install gdb or; yum install gdb`
    * gdb binary_name
    * set disassembly-flavor intel
    * break // e.g. break *main
    * run
    * info registers
2. [X86架构,可以读读,重要的是write more and more](https://en.wikibooks.org/wiki/X86_Assembly/X86_Architecture)


#### 0x06--Simple Tools and Techniques to analyse a Program

1. tools `string`, `objdump`, `stract, ltrace`, `Hopper DIsassembler`, `radare2`, `hexdump`
    * `hexdump`, e.g. hexdump -C binary_name
    * `strings`, e.g. strings binary_name, 用于输出二进制中可打印的字符.
    * `objdump`, e.g. objdump -x binary_name
    * `strace/lstrace`, 所有调用/lib调用
    * `radare2`, [clone && install ./sys/install.sh](https://github.com/radare/radare2)

