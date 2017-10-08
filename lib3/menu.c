#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "linklist.h"

void help();
int add();
int sub();
int mul();
void quit();

#define CMD_MAX_LEN 128
#define DESC_LEN 1024
#define CMD_NUM 10

static tDataNode head[]=
{
    {"help", "This is help cmd", help, &head[1]},
    {"version", "menu program v2.0", NULL, &head[2]},
    {"add", "add cmd", add, &head[3]},
    {"sub", "sub cmd", sub, &head[4]},
    {"mul", "mul cmd", mul, &head[5]},
    {"quit", "exit from menu", quit, NULL}
};

int main()
{
    while(1)
    {
        char cmd[CMD_MAX_LEN];
        printf("input a cmd >>");
        scanf("%s", cmd);
        tDataNode *p = FindCmd(head, cmd);
        if(p == NULL)
        {
            printf("Wrong cmd!\n");
        }
        printf("%s - %s\n", p->cmd, p->desc);
        if(p->handler != NULL)
        {
            p->handler();
        }
    }
}

void help()
{
    ShowAllCmd(head);
    return 0;
}

int add()
{
    int a, b, sum;
    printf("Please input 2 intergers:\n");
    scanf("%d %d", &a, &b);
    sum = a + b;
    printf("%d add %d is %d\n", a, b, sum);
}

int sub()
{      
    int a, b, sum;
    printf("Please input 2 intergers:\n");
    scanf("%d %d", &a, &b);
    sum = a - b;
    printf("%d sub %d is %d\n", a, b, sum);
}

int mul()
{
    int a, b, sum;
    printf("Please input 2 intergers:\n");
    scanf("%d %d", &a, &b);
    sum = a * b;
    printf("%d mul %d is %d\n", a, b, sum);
}

void quit()
{
    exit(0);
}
