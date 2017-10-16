/*************************************************
Date:2017/10/15
Author:Jeffrey
*************************************************/
#include<stdlib.h>
#include<stdio.h>
#include  "linktable.h"

tLinkTable *CreateLinkTable()
{
	tLinkTable *pLinkTable =(tLinkTable*)malloc(sizeof(tLinkTable));
	pLinkTable->pHead=NULL;
	pLinkTable->pTail=NULL;
	pLinkTable->SumOfNode=0;
	return pLinkTable;
}

int AddLinkTableNode(tLinkTable *pLinkTable,tLinkTableNode *pNode)
{
	if(pLinkTable ==NULL)
	{
		printf("Error,The table is empty!\n");
        exit(0);
	}
	 else if (pNode == NULL)
    {
        printf("The node is empty!\n");
        return 0;
    }
    else if (pLinkTable->pHead == NULL)
    {
        pLinkTable->pHead = pNode;
        pLinkTable->pTail = pNode;
        pLinkTable->SumOfNode = 1;
    }
    else
    {
        pLinkTable->pTail->pNext = pNode;
        pLinkTable->pTail = pNode;
        pLinkTable->SumOfNode++;
    }
    return 0;
}

tLinkTableNode * GetLinkTableHead(tLinkTable *pLinkTable)
{
    if (pLinkTable == NULL)
    {
        printf("The table is empty!\n");
        exit(0);
    }
    return pLinkTable->pHead;
}

tLinkTableNode * GetNextLinkTableNode(tLinkTable *pLinkTable, tLinkTableNode *pNode)
{
    if (pLinkTable == NULL)
    {
        printf("Erroe,The table is empty!\n");
        exit(0);
    }
    else if (pNode == NULL)
    {
        printf("Erroe,The node is empty!\n");
        exit(0);
    }
    return pNode->pNext;
}  

int DeleteLinkTable(tLinkTable * pLinkTable)
{
    if(pLinkTable == NULL)
        return FAILURE;

    while(pLinkTable->pHead != NULL)
    {
	tLinkTableNode *p = pLinkTable->pHead;
	pLinkTable->pHead = p->pNext;
	free(p);
    }

    pLinkTable->pHead = NULL;
    pLinkTable->pTail = NULL;
    pLinkTable->SumOfNode = 0;
    free(pLinkTable);
    return SUCCESS;
}


