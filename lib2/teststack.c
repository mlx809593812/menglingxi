#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
//三种状态定义

#define OK 0            
#define ERROR -1        
#define OVERFLOW -2       
//定义初始长度和增量长度  

#define size 10      
#define inc 10     
//定义栈的结构体

typedef struct
{
    int *base;     //栈底指针 
    int *top;        //栈顶指针 
    int stackSize;        // 栈大小 
    int realSize;        // 栈当前大小
}SqStack; 
//初始化一个栈

int InitStack(SqStack &sqstack)
{
    //申请默认栈大小 
    sqstack.base = (int*)malloc(size*sizeof(int)); 
    if(!sqstack.base) exit(OVERFLOW);
    sqstack.top  = sqstack.base;
    sqstack.stackSize = size;
    sqstack.realSize = 0; 
    return OK;
}

//进栈
int Push(SqStack &sqstack,int &e)
{
    if(sqstack.top-sqstack.base>=sqstack.stackSize) //是否需要扩充栈大小
	{
        sqstack.base = (int*)realloc(sqstack.base,(sqstack.stackSize+inc)*sizeof(int)); 
        if(!sqstack.base) exit(OVERFLOW);
        sqstack.stackSize = sqstack.stackSize + inc;
        }
        *sqstack.top++ = e;
        sqstack.realSize++;
        return OK;
}
         
//出栈
int Pop(SqStack &sqstack,int &e)
{
    if(sqstack.base==sqstack.top)
    {
        exit(ERROR);
    }
    e = *--sqstack.top;
    sqstack.realSize--;
    return OK;
}

//得到栈顶元素 
int GetTop(SqStack &sqstack,int &e)
{
    if(sqstack.base==sqstack.top)
    {
        exit(ERROR);
    }
    e = *(sqstack.top-1);
    return OK;
}

//判断栈是否为空
bool IsEmpty(SqStack &sqstack)
{
    if(sqstack.realSize>0)
        return false;
    else
        return true;
} 

//销毁栈 
int DestroyStack(SqStack &sqstack)
{
    sqstack.top = sqstack.base;
    free(sqstack.base);
    sqstack.realSize = 0;
    sqstack.stackSize = size; 
    return OK;
} 
 

int main()
{ 
    
    SqStack sqstack;
    int N = 0;         //用于记录输入栈的个数 
    int temp = 0;    //用于临时存栈 
    InitStack(sqstack);
    printf("初始化时，堆的大小为：%d\n",sqstack.stackSize);
    printf("请入你想要输入几个数据进栈：");
    scanf("%d",&N) ;
    while(N--)
	{
        scanf("%d",&temp);
        Push(sqstack,temp);
        printf("进栈的大小为：%d\t",temp);
        printf("压栈后，栈的大小为%d\n",sqstack.realSize);
        
    } 

    while(1)
    {
    int m=0;
    printf("入栈一个元素请输入0、出栈一个元素请输入1、获取此时栈顶元素请输入2、全部出栈请输入3、摧毁栈请输入4、help请输入5、退出请输入6、否则为错误指令\n");
    scanf("%d",&m);
    if(m==0)
    {
	printf("请输入你想要进栈的元素");
    if(sqstack.top-sqstack.base>=sqstack.stackSize) //是否需要扩充栈大小
	{
        sqstack.base = (int*)realloc(sqstack.base,(sqstack.stackSize+inc)*sizeof(int)); 
        if(!sqstack.base) exit(OVERFLOW);
        sqstack.stackSize = sqstack.stackSize + inc;
    }
	    scanf("%d",&temp);
        Push(sqstack,temp);
        printf("进栈的元素为：%d\t",temp);
        printf("压栈后，栈的大小为%d\n",sqstack.realSize);
    }

    if(m==1)
    {
        if(sqstack.base==sqstack.top)
	    {
		printf("此时的栈为空");
		exit(ERROR);
		}
            Pop(sqstack,temp);
            printf("栈此次输出的元素为%d \n",temp);
	        printf("%d元素已经出栈");
    }
	//出栈
    if(m==2)
    {
	GetTop(sqstack,temp);
        printf("得到栈顶元素为：%d\n",temp); 
    }
    if(m==3)
    {
	printf("栈内元素开始逐一出栈：\n");
    while(!IsEmpty(sqstack))
        {
        Pop(sqstack,temp);
        printf("%d \t",temp);
        }
        printf("\n栈输出完成！！\n");
	}
    if(m==4)
    {
    DestroyStack(sqstack);
    printf("销毁栈完成！！\n");
    scanf("%d",&temp);
    }
    if(m==5)
    {
	printf("This is help\n");
    }
    if(m==6)
    {
        break;
    }
    if(m!=6 && m!=5 && m!=4 && m!=3 && m!=2 && m!=1 && m!=0)
    {
        printf("This is wrong cmd\n");
    }
}
	return 0;
} 
