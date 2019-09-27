#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 300

struct tnode
{
	char key[MAX];
	int data;
	struct tnode *RC;
	struct tnode *LC;
};
struct tnode *t_insert( struct tnode * , char [] , int );
struct tnode *t_find( struct tnode * , char [] );
int main(int argc , char *argv[])
{
	struct tnode *treep , *find;
	char tmp[MAX] = {0} , key[MAX] = {0} , value[MAX] = {0};
	int len , data;
	FILE *fp , *fp1;
	if( argc == 3 )
	{
		fp = fopen( argv[1] , "r" );
		fp1 = fopen( argv[2] , "r" );
		while( fgets( tmp , MAX , fp ) )
		{
			sscanf( tmp , "%s %s" , key , value );
			data = atoi(value);
			treep = t_insert( treep , key , data );
			memset( key , '\0' , sizeof(key) );
			memset( value , '\0' , sizeof(value) );
		}
		
		while( fgets( tmp , MAX , fp1 ) )
		{
			len = strlen(tmp);
			if( tmp[len-1] == '\n' || tmp[len-1] == EOF )
				tmp[len-1] = '\0';
			find = t_find( treep , tmp );
			if( find == NULL )
					printf("%s unknown\n",tmp);
			else
					printf("%s %d\n",find->key , find->data);	
		}
	}
	return 0;
}
struct tnode *t_insert( struct tnode *treep , char key[] , int data )
{
	struct tnode *ptr;
	int c;
	ptr = (struct tnode*) malloc(sizeof(struct tnode));
	if( treep == NULL )
	{
		strcpy( ptr -> key , key );
		ptr->data = data;
		ptr->RC = NULL;
		ptr->LC = NULL;
		treep = ptr;
		return treep;
	}
	c = strcmp( treep->key , key );
	if( c<0 )
	{
		treep->RC = t_insert( treep->RC , key , data );
	}
	else if( c>0 )
	{
		treep->LC = t_insert( treep->LC , key , data );
	}
	return treep;
}
struct tnode *t_find( struct tnode *treep , char key[] )
{
	int c;
	c = strcmp( treep->key , key );
	
	if( treep == NULL )
			return NULL;
	if( c>0 )
	{
		if( treep->LC == NULL )
				return NULL;
		else
				return t_find( treep->LC , key );
	}
	if( c==0 )
			return treep;
	else
	{
		if( treep->RC == NULL )
				return NULL;
		else
				return t_find( treep->RC , key );
	}
}

