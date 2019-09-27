#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tnode
{
	char key[100];
	char num[100];
	struct tnode* lChild;
	struct tnode* rChild;
};
struct tnode* print( struct tnode* treep );
void BST_print( struct tnode* trees );
struct tnode* BST_find( struct tnode* treep , char search[]);
struct tnode* BST_insert( struct tnode* treep , char word[] , char number[] );
int main( int argc , char* argv[] )
{
	struct tnode *treep , *trees;
	FILE *fp1 , *fp2;
	char tmp[100] = {0} ,number[100] = {0} , word[100] = {0} , search[100] = {0} , *ptr = NULL;
	int i;
	fp1 = fopen( argv[1] , "r" );
	fp2 = fopen( argv[2] , "r" );
	while( fgets( tmp , 100 , fp1 ) != NULL )
	{
		ptr = tmp;
		i = 0;
		while( *ptr != ' ' )
		{
			word[i++] = *ptr;
			ptr++;
		}
			
		ptr++;
		i = 0;
		while( *ptr != '\n' )
		{
			number[i++] = *ptr;
			ptr++;
		}
		
		treep = BST_insert( treep , word , number );
		memset( tmp , 0 , sizeof(tmp) );
		memset( word , 0 , sizeof(word) );
		memset( number , 0 , sizeof(number) );
	}	
//	print( treep );
	while( fscanf( fp2 , "%s" , search ) != EOF )
	{
		trees = BST_find( treep , search );
		if( trees == NULL )
				printf("%s unknown\n",search);
		else
				BST_print( trees );
		memset( search , 0 , sizeof(search ) );
	}
}
struct tnode* BST_insert( struct tnode* treep , char word[] , char number[] )
{
	int c;
	struct tnode *ptr;
	ptr = (struct tnode*)malloc(sizeof(struct tnode));
	if( treep == NULL )
	{
		strcpy( ptr->key , word );
		strcpy( ptr->num , number );
		ptr->lChild = NULL;
		ptr->rChild = NULL;
		treep = ptr;
		return treep;
	}
	c = strcmp( treep->key , word );
	if( c== 0 )
	{
		return treep;
	}
	else if( c > 0 )
	{
		ptr = BST_insert( treep->rChild , word , number );
		treep->rChild = ptr;
		return treep;
	}
	else
	{
		ptr = BST_insert( treep->lChild , word , number );
		treep->lChild = ptr;
		return treep;
	}
}
struct tnode* BST_find( struct tnode *treep , char search[] )
{
	int c;
	if(treep == NULL)
			return NULL;
	c = strcmp( treep->key , search );
	if( c == 0 )
			return treep;
	else if( c < 0 )
			return BST_find( treep->lChild , search );
	else
			return BST_find( treep->rChild , search );
}
void BST_print( struct tnode *trees )
{
	printf("%s %s\n" , trees->key , trees->num );
}
struct tnode* print( struct tnode *treep )
{
	if( treep != NULL )
	{
		print( treep->lChild );
		printf("%s %s\n",treep->key , treep->num );
		print( treep->rChild );
	}
}
