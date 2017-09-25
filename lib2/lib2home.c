#include <stdio.h>
#include <stdlib.h>

void help()
{
    printf("This is help cmd!\n");
}
void wrong()
{
    printf("This is wrong cmd!\n");
}
void cmd1()
{
    printf("This is cmd1!\n");
}
void cmd2()
{
    printf("This is cmd2!\n");
}
void cmd3()
{
    printf("This is cmd3!\n");
}
void cmd4()
{
    printf("This is cmd4!\n");
}
void cmd5()
{
    printf("This is cmd5!\n");
}
void cmd6()
{
    printf("This is cmd6!\n");
}

int main()
{
    char cmd[128];
    while(1)
	{
	    scanf("%s",cmd);
	    if(strcmp(cmd,"help") == 0)
		{
		    help();
		}
	    else if(strcmp(cmd,"quit") == 0)
		{
		    exit(0);
		}
            else if(strcmp(cmd,"cmd1") == 0)
		{
		    cmd1();
		}
	    else if(strcmp(cmd,"cmd2") == 0)
		{
		    cmd2();
		}
	    else if(strcmp(cmd,"cmd3") == 0)
		{
		    cmd3();
		}
	    else if(strcmp(cmd,"cmd4") == 0)
		{
		    cmd4();
		}
	    else if(strcmp(cmd,"cmd5") == 0)
		{
		    cmd5();
		}
            else if(strcmp(cmd,"cmd6") == 0)
		{
		    cmd6();
		}
	    else
		{
		    wrong();
		}
	}
    return 0;
}

