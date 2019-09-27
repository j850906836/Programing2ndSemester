#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct tnode
{
	char key[100];
	int cnt;
	struct tnode *RC;
	struct tnode *LC;
};

struct tnode* t_insert( struct tnode *treep , char word[] );
struct tnode* t_delete( struct tnode *treep , char word[] );
//int t_count( struct tnode *treep , int len );
struct tnode* t_find( struct tnode *treep , char word[] );
//int mycompare( const void *x , const void *y );
void t_inorder( struct tnode *treep );
int main()
{	
	struct tnode *treep , *trees;
//	struct arr array[100];
	int len , i;
	char tmp[100] = {0} , string[100] = {0} , order[100] = {0};
	while( fgets( tmp , 100 , stdin ) )
	{
		sscanf( tmp , "%s\t%s" , order , string );
		if( strcmp( order , "insert" ) == 0 )
		{
			treep = t_insert( treep , string );
		}
		else if( strcmp( order , "delete" ) == 0 )
		{
			treep = t_delete( treep , string );
		}
		else if( strcmp( order , "find" ) == 0 )
		{
			trees = t_find( treep , string );
			printf("find\n");
			printf("%s\t%d\n",trees->key,trees->cnt);
			printf("-------\n");
		}
/*		else if( strcmp( order , "count" ) == 0 )
		{
			len = t_count( treep , 0 );
		//	printf("%d\n",len);
			for( i = 0 ; i < 4; i++ )
			{
				printf("%s\t%d\n",array[i].key,array[i].cnt);
			}
		}*/
		else if( strcmp( order , "inorder" ) == 0 )
		{
			t_inorder( treep );
		}
		memset( tmp , 0 , sizeof(tmp) );
		memset( string , 0 , sizeof(string) );
		memset( order , 0 , sizeof(order) );
	}
	return 0;

}

struct tnode* t_insert( struct tnode *treep , char word[] )
{
	int c;
	struct tnode *ptr;
	ptr = (struct tnode*)malloc (sizeof(struct tnode));

	if( treep == NULL )
	{
		strcpy( ptr->key , word );
		ptr->cnt = 1;
		ptr->RC = NULL;
		ptr->LC = NULL;
		treep = ptr;
		return treep;
	}
	c = strcmp( treep->key , word );
//	printf("strcmp:%d\t%s\t%s\n",c,treep->key,word);
	if( c > 0 )
	{
		ptr = t_insert( treep->LC , word );
		treep->LC = ptr;
		return treep;
	}
	else if( c == 0 )
	{
		treep->cnt++;
		return treep;
	}
	else if( c < 0 )
	{
		ptr = t_insert( treep->RC , word );
		treep->RC = ptr;
		return treep;
	}
	return NULL;
}
struct tnode* t_delete( struct tnode *treep , char word[] )
{
	int c;
	c = strcmp( treep->key , word );

	if( treep == NULL )
			return NULL;
	else if( c < 0 )
	{
		if( treep->RC == NULL )
				return NULL;
		else
		{
		t_delete( treep->RC , word );
		return treep;
		}
	}
	else if( c == 0 )
	{
		if( (treep->cnt) > 0 )
		{
		treep->cnt--;
		}
		else
		{
			treep->cnt = 0;
		}
		return treep;
	}
	else if( c > 0 )
	{
		if( treep->LC == NULL )
				return NULL;
		else
		{
		t_delete( treep->LC , word );
		return treep;
		}
	}
	
return NULL;	
}
struct tnode* t_find( struct tnode *treep , char word[] )
{
	int c;
	c = strcmp( treep->key , word );
	if( treep == NULL )
		return NULL;
	if( c > 0 )
	{
		t_find( treep->LC , word );
	}
	if( c == 0 )
	{
		return treep;
	}
	if( c < 0 )
	{
		t_find( treep->RC , word );
	}	
	return NULL;
}
/*int t_count( struct tnode *treep , int len )
{
	struct arr array[100];
	int i;
	
	if( treep == NULL )
			return len;
	strcpy(array[len].key , treep->key);
	array[len].cnt = treep->cnt;
	len++;
	if( treep->LC != NULL )
		t_count( treep->LC , len );		
	if( treep->RC != NULL )
		t_count( treep->RC , len );	
	
	strcpy(array[len].key , treep->key);
	array[len].cnt = treep->cnt;
	len++;
	return len;
}*/
void t_inorder( struct tnode* treep )
{
	if( treep != NULL)
	{		
	t_inorder( treep->LC );
	if( treep->cnt != 0 )
	{
	printf("%s\t%d\n",treep->key , treep->cnt);
	}
	t_inorder( treep->RC );
	}
}/*
int mycompare( const void *x , const void *y )
{
	struct tnode* a = (struct tnode*)x;
	struct tnode* b = (struct tnode*)y;
	if( a->cnt == b->cnt )
			return(strcmp(b->key , a->key));
	else
			return (b->cnt-a->cnt);
}
*/			
