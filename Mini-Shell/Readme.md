# 【Program】 Mini Shell

[toc]

## 一、项目描述

​		结合进程控制的知识，完成一个简易的命令行解释器 (shell)，我们在这里成为 Mini Shell

## 二、技术特点

​		进程创建、进程终止、进程等待、进程程序替换

## 三、项目原理

​		首先，我们需要理解 bash 命令行解释器其本质也是一个可执行程序，在命令行解释器当中键入 ls、pwd、cd、mv、cp …… 这些命令时，其实 bash 也是创建一个子进程，让子进程去进程程序替换执行相应的命令程序。

​		我们要完成的这个 Mini Shell 类似于 Shell，它需要循环去做以下四个过程：

​		(1) 从标准输入当中获取输入的命令，即获取命令行

​		(2) 解析命令行 (拆分字符串)

​		(3) 创建子进程 (fork)

​		(4) 让子进程进程程序替换接收到的命令 (execvp)

​		(5) 父进程等待子进程的退出 (wait)

![image-20210713085507457](https://raw.githubusercontent.com/ACosine/PicGo/master/img/20210713085507.png)



## 四、项目思路

​		**实现1：从标准输入中获取用户输入的命令**

​		这里采用的是 fgets  从标准输入流 stdin 中读取数据，只要 fgets 的返回值不为 NULL 就表示从标准输入流中获取用户输入的命令成功。

```c
#include <stdio.h>
char *fgets(char *s, int size, FILE *stream);
```

​		参数 ：

​				*s: 字符型指针，指向用来存储所得数据的地址。

​				size: 整型数据，指明存储数据的大小。

​				*stream: 文件结构体指针，将要读取的文件流。

​		返回值：

​				 当 size <= 0 时返回NULL，即空指针。

​     		    当 size = 1 时，返回空串""。

​     			如果读入成功，则返回缓冲区的地址。

​     			如果读入错误或遇到文件结尾(EOF)，则返回NULL。

```c
//*******获取命令行数据*********//
char GetCommand()
{
    printf("[minishell@localhost minishell]$ ");  // 提示符
    fflush(stdout);                               //强制刷新缓冲区

    memset(g_command,'\0',sizeof(g_command));

    if(fgets(g_command,sizeof(g_command)-1,stdin) == NULL)
    {
        perror("fgets error");
        return -1;
    }
    return 0;
}
```

---

​		**实现2：解析命令行数据（字符串分割）**

​			我们拿最常用的命令 `ls -l .. ` 为例，`ls` 是可执行程序 `-l` 和 `..` 是命令行参数，它们以空格分隔开来的。那么我们就需要将 `ls -l .. ` 分割为 `ls`、`-l` 和 `..` 三个部分。切分出来的第一个是可执行程序，后面的若干个都是命令行参数。

​		分割的原理就是让 `\0` 替换 **空格** 分隔符，我们采用嵌套的两个 while 循环来遍历，大 while 循环查找并标记每一个子串的首地址，小 while 循环查找每个子串后面的空格，查找到并替换成 `\0`。

![image-20210713232930999](https://raw.githubusercontent.com/ACosine/PicGo/master/img/20210713232931.png)

```c
#include <ctype.h>
int isspace(int c); 
//若c为空白符，则返回非零值（true），若c不是空白符，则返回0（false）
```

```c
//*******解析命令行数据*********//
int DealCommand(char * command)
{
    int argc = 0;
    char * argv[1024] = {0};
    while(*command)
    {
        if(!isspace(*command) && *command != '\0')
        {
            argv[argc] = command;   //标记每个字符串首地址
            argc++;
            
            //大 while 循环是查找每个子串的头部
            //小 while 循环是查找每个子串后面的空格，查找到并替换为\0
            while(!isspace(*command) && *command != '\0')
            {
                command++;
            }
            *command = '\0';        
        }
        command++;
    }
    //方便后面给进程程序替换传递参数，可变参数列表
    argv[argc] = NULL;
    ExecCommand(argv);
    return 0;
}
```

---

​		**实现3：创建子进程，让子进程进程程序替换，执行刚刚从标准输入读进来的命令，父进程进行进程等待，防止子进程变成僵尸进程**

​		在这里需要特别注意两点：①子进程在进程替换成功时，会执行替换后的程序，替换失败的话一定一定得将替换失败的进程终止掉。②父进程需要进程等待，防止子进程变成僵尸进程。

```c
//********执行命令行************//
int ExecCommand(char* argv[])
{
        if(argv[0] == NULL)
        {
            printf("ExecCommand failed\n");
            return -1;
        }
        //创建子进程
        pid_t pid = fork();
        if(pid < 0)
        {
            perror("fork failed\n");
        }
        else if(pid ==0)
        {
            //子进程 ---> 进程程序替换
            execvp(argv[0],argv);
            //替换失败，进程终止
            exit(0);
        }
        else
        {
            //父进程 ---> 进程等待
            waitpid(pid,NULL,0);   //不关心退出状态信息，status=NULL 
        }
}
```

​		编译运行 minishell 可执行程序，看一下最终的效果。

![](https://raw.githubusercontent.com/ACosine/PicGo/master/img/20210713194245.gif)

## 五、项目源码

​		[Mini-Shell.zip](https://download.csdn.net/download/Sunnyside_/20256373)

## 六、项目心得

​		理论结合实践，才是学习的根本。学习完进程控制，并没有深刻理解到为什么要进程程序替换，什么时候要进程终止，什么地方进程进程等待。通过这个简易的 Mini Shell 才深刻理解。

​		



