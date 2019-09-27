#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "struct.h"

struct hnode *Htab[30] = { NULL };
unsigned int hash33( char [] );
struct hnode *h_insert( struct hnode* , char [] );
struct hnode *h_find(struct hnode* , char []);
struct hnode *h_delete(struct hnode* , char []);

int main()
{
	char tmp[100]={0} , order[100]={0} , string[100]={0};
	struct hnode *ptr;
	unsigned int hv;

	while(fgets(tmp , 100 , stdin))
	{
		sscanf(tmp , "%s\t%s" , order , string);
		hv = hash33(string);
		
		if(strcmp(order , "insert") == 0)
		{
				Htab[hv] = h_insert(Htab[hv] , string);
		}
		else if(strcmp(order , "find") == 0)
	    {
			ptr = h_find(Htab[hv] , string);
			if( ptr == NULL )
			{
				printf("find\t%s\n",string);
				printf("----------\n");
				printf("Not\tfound!\n");
				printf("----------\n");
			}
			else
			{
				printf("find\t%s\n",string);
				printf("----------\n");
				printf("%s\t%d\n",ptr->key,ptr->cnt);
				printf("----------\n");
			}
		}
		else if(strcmp(order , "delete") == 0)
		{
				Htab[hv] = h_delete(Htab[hv] , string);
		}
		
		memset(order,0,sizeof(order));
		memset(string,0,sizeof(string));
	}
	return 0;
}
	
unsigned int hash33( char text[] )
{
	int len , i=0 , hashv=0;
	len = strlen(text);
	
	for( i=0; i<len; i++ )
	{
		hashv = (hashv<<2) + text[i];
	}

	return hashv%30;
}

struct hnode *h_insert( struct hnode *Htab , char key[] )
{
	struct hnode *hptr = Htab;
	
	while( hptr != NULL )
	{
		if( strcmp( hptr->key,key ) == 0)
		{
					hptr->cnt++;
			return Htab;
		}
		hptr = hptr->next;
	}
	hptr = (struct hnode*) malloc(sizeof(struct hnode));

	if( hptr == NULL )
	{		
		printf("malloc error");
		exit(1);
	}
		strcpy(hptr->key,key);
		hptr->cnt = 1;
		hptr->next =  Htab;
		Htab = hptr;
		return Htab;
}

struct hnode *h_find(struct hnode *Htab , char key[])
{
	struct hnode *hptr = Htab;
	while(hptr != NULL)
	{
		if(strcmp(hptr->key,key) == 0)
				return hptr;
		else
				hptr = hptr->next;
	}
	return NULL;
}

struct hnode *h_delete(struct hnode *Htab , char key[])
{
	struct hnode *hptr = Htab;
	if( hptr == NULL )
			printf("NULL\n");
	while(hptr != NULL)
	{
		if(strcmp(hptr->key,key) == 0)
		{		
				if(hptr->cnt==0)
					return Htab;
				else
				{
					hptr->cnt--;
					return Htab;
				}
		}
		else
				hptr = hptr->next;
	}
	return Htab;
}
