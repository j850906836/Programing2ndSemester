#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 1024
struct tnode
{
	char key[MAX];
	struct tnode *RC;
	struct tnode *LC;
};
struct tnode *t_insert(struct tnode * , char [] );
void t_print(struct tnode * );
int main()
{
	char tmp[MAX]={0};
	struct tnode *treep;
	int len;

	while( fgets( tmp , MAX , stdin ) )
	{
		len = strlen(tmp);
		if( tmp[len-1] == '\n' || tmp[len-1] == EOF )
				tmp[len-1] = '\0';
		treep = t_insert( treep , tmp );
	}
	t_print( treep );
	return 0;
}
struct tnode *t_insert( struct tnode *treep , char key[] )
{
	int c;
	struct tnode *ptr = NULL;
	ptr = (struct tnode*) malloc( sizeof( struct tnode ) );	
	if( treep == NULL )
	{
		strcpy( ptr->key , key );
		ptr->RC = NULL;
		ptr->LC = NULL;
		treep = ptr;
		return treep;
	}
	
	c = strcmp( treep->key , key );
	if( c>0 )
	{
		treep->LC = t_insert( treep->LC , key );
		return treep;
	}
	else if( c<0 )
	{
		treep->RC = t_insert( treep->RC , key );
		return treep;
	}
	return treep;
}
void t_print( struct tnode *treep )
{
	if(treep != NULL)
	{
		t_print( treep->LC );
		printf("%s\n",treep->key);
		t_print( treep->RC );
	}
	
}
