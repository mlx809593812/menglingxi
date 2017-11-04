/*************************************************
Date:2017/11/04
Author:Jeffrey
*************************************************/
#ifndef _MENU_H
#define _MENU_H

int MenuConfig(char * cmd, char * desc, void (*handler)(int argc, char *argv[]));

int ExecuteMenu();

#endif
