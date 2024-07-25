# class_Z_linux
>  Z班linux作业

## /code记录代码
## /docx保存文档（知识点、题目）



# 补充

### 2024/7/25

for循环中声明变量需要C99或C11.

```C
for(int i = 0;i < n;i ++ ){...}
```

此处声明变量`i`.





### 2024/7/26

Dev C++的中文编码是GB2312，github默认是utf-8，所以中文会出现乱码。

code/指针和数组的中文代码全部改成英文。



目录下放`.vscode`可以统一代码格式？（不确定）

后续使用vscode格式化代码，风格会从K&R风格变成微软风格。

```C
//K&R风格
if ( a > 100 ) {
//do somthing…
}

//微软风格
if ( a > 100 ) 
{
//do somthing…
}

```

