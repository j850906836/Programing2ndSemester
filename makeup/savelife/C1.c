#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct tnode
{
	char key[200];
	struct tnode *RC;
	struct tnode *LC;
};

struct tnode *t_insert( struct tnode * , char [] );
void t_print( struct tnode * );
int main()
{
	struct tnode *treep;
	char tmp[200] = {0};
	int len = 0;	
	
	while( fgets( tmp , 200 , stdin ) )
	{
		len = strlen(tmp);
	//	printf("/%c/\n",tmp[len]);
		if( tmp[len-1] == '\n' || tmp[len-1] == EOF )
		tmp[len-1]='\0';
		treep = t_insert( treep , tmp );
	}
	
	t_print( treep );
	return 0;
}

struct tnode *t_insert( struct tnode *treep , char word[] )
{
	struct tnode *ptr = NULL;
	int c;
	ptr = (struct tnode*)malloc(sizeof(struct tnode));
	if( treep == NULL )
	{
		strcpy( ptr->key , word );
		ptr->RC = NULL;
		ptr->LC = NULL;
		treep = ptr;
		return treep;
	}
	c = strcmp( treep->key , word );
	
	if( c < 0 )
	{
		ptr = t_insert( treep->RC , word );
		treep->RC = ptr;
		return treep;
	}
	else if( c == 0 )
	{
		return treep;
	}
	else if( c > 0 )
	{
		ptr = t_insert( treep->LC , word );
		treep->LC = ptr;
		return treep;
	}
	return NULL;
}
void t_print( struct tnode *treep )
{
	if( treep != NULL )
	{
	t_print( treep->LC );
	printf( "%s\n",treep->key );
	t_print( treep->RC );
	}

	if(treep == NULL)
			return;
}
