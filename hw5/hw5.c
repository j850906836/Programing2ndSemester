#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define TRUE 0
#define FALSE 1
struct	lnode
{
	char key[30];
	int count;
	struct lnode *next;
};
void lprintf( struct lnode *llist );
struct lnode* lfind( struct lnode *llist , char word[] );
struct lnode* linsert( struct lnode *llist , char word[] );
struct lnode* ldelete( struct lnode *llist , char test[] );
struct lnode* larray( struct lnode *llist );
int mycompare( const void *x , const void *y );
int main( int argc , char *argv[] )
{
	struct lnode *llist , *ptr = NULL;
	char word[30] = {0} , tmp[30] = {0} , test[30] = {0};
	int i = 0;
	FILE *pfile;
	pfile = fopen( argv[1] , "r" ); 
	if( pfile == NULL )
	{
			printf("terms not exist\n");
			return 0;
	}
	if(argc == 1 )
	{
			printf("insert file name!\n");
			return 0;
	}
	while( fscanf( pfile , "%s" , tmp )!= EOF )
	{
		sscanf( tmp , "%s" , word );
		if( tmp[0] == '-' )
		{
			i = 0;
			strcpy( test , word );
			while( test[i] != '\0' )
			{
				test[i] = test[i+1];
				i++;
			}
				
			ptr = lfind( llist , word );
			if( ptr == NULL )
			{
				llist = ldelete( llist , test );
			}
			else
			{
				llist = linsert( llist , test );	
			}
		}
		else
		{
		ptr = lfind( llist , word );
		if( ptr == NULL )
		{
		llist = linsert( llist , word );
		}
		}
	}
	llist = larray( llist );
	lprintf ( llist );
	return 0;
}

struct lnode* linsert( struct lnode *llist , char word[] )
{
		struct lnode *ptr = NULL , *lastp = NULL , *newp = NULL;
		ptr = lastp = llist;
		newp = (struct lnode* ) malloc (sizeof(struct lnode));
		
		if( llist == NULL )
		{
			llist = newp;
			strcpy( newp -> key , word );
			newp -> count = 1;
		}
		while( ptr != NULL && (strcmp ( ptr -> key , word ) < 0 ) )
		{
			lastp = ptr;
			ptr = ptr -> next;
		}
		if( ptr == lastp )
		{
			strcpy( newp -> key , word );
			newp -> count = 1;
			newp -> next = ptr;
			lastp = newp;
			llist = lastp;
		}
		else
		{
			strcpy( newp -> key , word );
			newp -> count = 1;
			newp -> next = ptr;
			lastp -> next = newp;
		}
		return llist;
}
struct lnode* lfind( struct lnode *llist , char word[] )
{
		struct lnode *ptr = NULL;
		ptr = llist;
		
		while( ptr != NULL && strcmp( ptr ->key , word ) != 0)
		{
			ptr = ptr -> next;
		}
		if( ptr == NULL )
		{
			return ptr;
		}
		else
		{
			ptr -> count++;
			return ptr;
		}
}
struct lnode* ldelete( struct lnode *llist , char test[] )
{
		struct lnode *ptr = NULL , *lastp = NULL;
		int state;
		ptr = lastp = llist;
		
		state = TRUE;
		while( ptr != NULL )
		{
			if(strcmp( ptr ->key , test ) == 0)
			{
					state = FALSE;
					break;
			}
			lastp = ptr;
			ptr = ptr -> next;
		}
		if(state == TRUE)
		{
				return llist;
		}
		else if (state == FALSE) 
		{   
		    ptr -> count--;
			if( ptr -> count == 0 )
			{
				if( ptr == llist )
				{
					ptr = llist ->next;
					free(llist);
					return ptr;
				}
				
					lastp -> next = ptr -> next;
					free(ptr);
					return llist;
				
			}
	
			return llist;
		}
		return 0;
}
struct lnode* larray( struct lnode *llist )
{
		struct lnode* array;
		int i = 0 , j = 0;
		
		array = (struct lnode*) malloc( sizeof ( struct lnode* ));
		while( llist != NULL )
		{
			strcpy( array[i].key , llist -> key );
			array[i].count = llist -> count;
			llist = llist -> next;
			i++;
		}
		qsort( array , i , sizeof(struct lnode) , mycompare );
		
		for( j = 0; j < i - 1; j++ )
		{
			array[j].next = &array[j+1];
		}
		llist = &array[0];
		return llist;
}
void lprintf( struct lnode *llist )
{
		struct lnode *ptr;
		ptr = llist;
	
		while( ptr != NULL )
		{
				printf( "%s:%3d\n" , ptr -> key , ptr -> count);
				ptr = ptr -> next;
		}

}
int mycompare( const void * x , const void * y )
{
	struct lnode* yes = (struct lnode*)x;
	struct lnode* no = (struct lnode*)y;
	if((no -> count - yes -> count)!=0)
	{
		return( no -> count - yes -> count );
	}
	if( (yes -> count) == (no -> count) )
	{
		return(strcmp( yes -> key , no -> key ));
	}
	else
			return 0;
	
}
