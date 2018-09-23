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

