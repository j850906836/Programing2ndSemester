#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 300
struct lnode
{
	char key[MAX];
	int data;
	struct lnode *next;
};
struct arr
{
	char key[MAX];
	int data;
};
struct lnode *l_insert( struct lnode * , char [] , int );
struct lnode *l_delete( struct lnode * , char [] );
struct lnode *l_find( struct lnode * , char [] );
void l_sort( struct lnode * );
void l_print( struct lnode * );
int mycompare( const void * , const void * );
int main(int argc , char *argv[])
{
	struct lnode *llist , *find , *del;
	char tmp[MAX] = {0} , key[MAX] = {0} , value[MAX] = {0};
	int len , data;
	FILE *fp , *fp1;
	fp = fopen( argv[1] , "r" );
	fp1 = fopen( argv[2] , "r" );
	if( argc == 3 )
	{
		while( fgets ( tmp , MAX , fp ) )
		{
			sscanf( tmp , "%s %s", key , value );
			data = atoi(value);
			llist = l_insert( llist , key , data );
			memset( key , '\0' , sizeof(key) );
			memset( value , '\0' , sizeof(value) );
		}
		while( fgets( tmp , MAX , fp1 ) )
		{
			if( tmp[0] == '-' )
			{
				sscanf( tmp , "-%s" , key );
				del = l_delete( llist , key );
				
				if( del == NULL )
					printf( "%s NOT_FOUND\n" , key );
				else
					printf( "%s is deleted\n" , key );
			}
			else if( tmp[0] == 'p' )
					l_print(llist);
			else if( tmp[0] == 's' )
					l_sort(llist);
			else if( tmp[0] != '-' )
			{
				len = strlen(tmp);
				if( tmp[len-1] == '\n'||tmp[len-1] == EOF )
						tmp[len-1] = '\0';
				find = l_find( llist , tmp );
				if( find == NULL )
						printf( "%s NOT_FOUND\n" , tmp );
				else
						printf( "%s %d\n" , find->key , find->data );
			}
		}
	}
	return 0;
}
struct lnode *l_insert( struct lnode *llist , char key[] , int data )
{
	struct lnode *ptr;
	ptr = (struct lnode*) malloc( sizeof( struct lnode ) );

		strcpy( ptr->key , key );
		ptr->data = data;
		ptr->next = llist;
		llist = ptr;

	return llist;
}
struct lnode *l_delete( struct lnode *llist , char key[] )
{
	struct lnode *ptr , *lastp;
	ptr = lastp = llist;
	if( llist == NULL )
			return NULL;
	else
	{
		while( llist != NULL )
		{
			if( strcmp( llist->key , key ) == 0 )
			{
					lastp = llist;
					break;
			}
			else
			{	
					ptr = llist;
					llist = llist->next;
			}
		}
	}
	if( ptr == lastp )
	{
		llist = llist->next;
		return llist;
	}
	else if( llist != NULL )
	{
		ptr->next = lastp->next;
		free(lastp);
		return ptr;
	}

	return NULL;
}	
struct lnode * l_find(struct lnode *llist , char key[] )
{
	if( llist == NULL )
			return NULL;
	else
	{
		while( llist != NULL )
		{
			if( strcmp( llist->key , key ) == 0 )
			{
					return llist;
					break;
			}
			else
					llist = llist->next;
		}
	}
	return NULL;
}
void l_sort( struct lnode *llist )
{
	struct arr array[MAX];
	int i=0 , len;
	
	if( llist == NULL )
			return ;
	while( llist != NULL )
	{
		strcpy( array[i].key , llist->key );	
		array[i].data = llist->data;
		i++;
		llist = llist->next;
	}
	qsort( array , i , sizeof( struct arr ) , mycompare );

	len = i;
	printf( "data sort\n" );
	for( i=0; i<len; i++ )
	{
		printf( "%s %d\n",array[i].key , array[i].data );	
	}

}
void l_print( struct lnode *llist )
{
	if( llist == NULL )
			return;
	else
	{
		printf("data print:\n");
		while( llist != NULL )
		{
			printf( "%s %d\n" , llist->key , llist->data );	
			llist = llist->next;
		}
	}
	
}
int mycompare( const void *x , const void *y )
{
	struct arr *a = (struct arr*)x;
	struct arr *b = (struct arr*)y;

	return ( strcmp ( a->key , b->key ) );
}
