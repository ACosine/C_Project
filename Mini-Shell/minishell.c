#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>

char g_command[1024];

//*******获取命令行数据*********//
char GetCommand()
{
    printf("[minishell@localhost minishell]$ ");  // 提示符
    fflush(stdout); //强制刷新缓冲区

    memset(g_command,'\0',sizeof(g_command));

    if(fgets(g_command,sizeof(g_command)-1,stdin) == NULL)
    {
        perror("fgets error");
        return -1;
    }
    return 0;
}
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
            //进程程序替换成功，那么它就执行替换后的程序去了
            //替换失败，则顺序执行，此时让没有替换成功的子进程终止掉
            exit(0);
        }
        else
        {
            //父进程 ---> 进程等待，防止子进程变成僵尸进程
            waitpid(pid,NULL,0);   //不关心提出状态信息 
        }
}

//*******解析命令行数据*********//
int DealCommand(char * command)
{
    //字符串切割，以空格为切割符，切分出来的第一个是可执行程序，后面的若干个都是命令行参数
    //比如：ls -l .. ,ls 是可执行程序 -l 和.. 是命令行参数，它们以空格分隔开来
    int argc = 0;
    char * argv[1024] = {0};
    while(*command)
    {
        if(!isspace(*command) && *command != '\0')
        {
            argv[argc] = command;   //标记每个字符串首地址
            argc++;
            
            //大 while 循环是查找每个子串的头部，小 while 循环是查找每个子串后面的空格，查找到并替换为\0
            //寻找分隔符
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

int main()
{

    while(1)
    {
        //1. 获取用户输入的命令
        if(GetCommand() == -1)
        {
            continue;
        }

        //2. 解析命令行(拆分字符串) DealCommand
        //3. 创建子进程 ExecCommand
        //4. 子进程进程程序替换 excevp
        //5. 父进程进程等待 waitpid
        DealCommand(g_command);

   }
    return 0;
}
