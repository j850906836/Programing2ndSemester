#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 300
struct tnode
{
	char key[MAX];
	struct tnode *LC;
	struct tnode *RC;
};
struct tnode *t_insert( struct tnode * , char []);
void t_print( struct tnode * );
int main()
{
	struct tnode *treep = NULL;
	char tmp[MAX] = {0};
	int len;
	while( fgets( tmp , MAX , stdin ) )
	{
		len = strlen(tmp);
		if(tmp[len-1] == '\n' || tmp[len-1] == EOF)
		tmp[len-1] = '\0';
		treep = t_insert( treep , tmp);
	}
	t_print( treep );

	return 0;
}
struct tnode * t_insert( struct tnode *treep , char key[] )
{
	struct tnode *ptr;
	int c;

	if( treep == NULL )
	{
		ptr = (struct tnode *)malloc(sizeof(struct tnode));
		strcpy( ptr->key , key );
		ptr->LC = NULL;
		ptr->RC = NULL;
		return ptr;
	}

	c = strcmp( treep->key , key );
	
	if( c<0 )
	{
		ptr = t_insert( treep->RC , key );
		treep->RC = ptr;
		return treep;
	}
	if( c==0 )
			return treep;
	if( c>0 )
	{
		ptr = t_insert( treep->LC , key );
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
		printf( "%s\n",treep->key);
		t_print( treep->RC );
	}
}
