/*代码段、数据段和BSS段存储变量类型*/
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
const int g_A = 10;  // 代码段
int g_B = 20;        // 数据段
static int g_C = 30; // 数据段
static int g_D;      // BSS段
int g_E;             // BSS段
char *p1;            // BSS段
void main()
{
    int local_A;            // 栈
    static int local_C = 0; // 数据段
    static int local_D;     // 数据段

    char *p3 = "123456";     // 123456在代码段，p3在栈上
    p1 = (char *)malloc(10); // 堆，分配得来得10字节的区域在堆区
    strcpy(p1, "123456");    // 123456{post.content}放在常量区，编译器可能会将它与p3所指向 的"123456"优化成一块
    printf("\n");
    printf("代码段,全局初始化变量, 只读const,  g_A,     addr:0x%08x\n", &g_A);
    printf("\n");
    printf("数据段,全局变量,       初始化      g_B,     addr:0x%08x\n", &g_B);
    printf("数据段,静态全局变量,   初始化,     g_C,     addr:0x%08x\n", &g_C);
    printf("\n");
    printf("BSS段, 全局变量,       未初始化    g_E,     addr:0x%08x\n", &g_E, g_E);
    printf("BSS段, 静态全局变量,   未初始化,   g_D,     addr:0x%08x\n", &g_D);
    printf("BSS段, 静态局部变量,   初始化,     local_C, addr:0x%08x\n", &local_C);
    printf("BSS段, 静态局部变量,   未初始化,   local_D, addr:0x%08x\n", &local_D);
    printf("\n");
    printf("栈,    局部变量,                   local_A, addr:0x%08x\n", &local_A);
    printf("\n");
    printf("堆,    malloc分配内存,             p1,      addr:0x%08x\n", p1);
}
