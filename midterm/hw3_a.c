#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct tnode
{
	char word[100];
	struct tnode *lChild; 
	struct tnode *rChild;
};
void inorder_traversal(struct tnode *treep);
struct tnode* BST_insert( struct tnode *treep , char tmp[] );
int main()
{
	struct tnode *treep;
	char tmp[100] = {0};
	while(fgets( tmp , 100 , stdin ))
	{
		treep = BST_insert( treep , tmp );
	}
	inorder_traversal( treep );
}
struct tnode* BST_insert( struct tnode *treep , char  tmp[] )
{
	int c;
	struct tnode *ptr;
	
	if( treep ==  NULL )
	{
		ptr = (struct tnode*)malloc(sizeof(struct tnode));	
		strcpy( ptr->word , tmp);
		ptr->lChild = NULL;
		ptr->rChild = NULL;
		treep = ptr;
		return treep;
	}
	c = strcmp( treep->word , tmp );
	if( c == 0 )
	{
			return treep;
	}
	else if( c < 0 )
	{
		ptr = BST_insert( treep->rChild , tmp );
		treep->rChild = ptr;
		return treep;
	}
	else 
	{
		ptr = BST_insert( treep->lChild , tmp );
		treep->lChild = ptr;
		return treep;
	}
}
void inorder_traversal(struct tnode* treep)
{
	if( treep != NULL )
	{
		inorder_traversal( treep->lChild );
		printf("%s",treep->word);
		inorder_traversal( treep->rChild );
	}
}
