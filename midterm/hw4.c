#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define OFF 0
#define ON 1
struct lnode
{
	char string[100];
	char number[100];
	struct lnode *next;

};
struct lnode* lfind( struct lnode *llist , char data[] );
struct lnode* ldelete( struct lnode *llist , char dtmp[] );
struct lnode* linsert( struct lnode *llist , char tmp[] , char integer[] );
void lprintf( struct lnode *llist );
int main( int argc , char* argv[] )
{
	int i = 0 , state;
	struct lnode* llist , *lfindit;
	char data[100] = {0} , tmp[100] = {0} , search[100] = {0} , *ptr = NULL;
	char integer[100] = {0} , p[10] = {0} , dtmp[100] = {0};
	FILE *datafp , *searchfp;
	datafp = fopen( argv[1] , "r" );
	searchfp = fopen( argv[2] , "r" );

		while(fgets( data , 100 , datafp )!=NULL)
		{
			ptr = data;
			i = 0;
			while( *ptr != ' ' )
			{
				tmp[i++] = *ptr;
				ptr++;
			}
			i = 0;
			ptr++;
			while( *ptr != '\n' )
			{
				integer[i++] = *ptr;
				ptr++;
			}
			
			llist = linsert( llist , tmp , integer );
			memset( tmp , 0 , sizeof(tmp) );
		}
	
		while(fgets( tmp , 100 , searchfp )!=NULL)
		{
			sscanf( tmp , "%s" , search );
			i = 0;
	//		printf("%c:\n",search[0]);
	//		printf("%s\n",search);
			if( strcmp( search , "p" ) == 0 )
			{
				printf("print the data\n");
				lprintf(llist);	
			}
			else if( search[0] == '-' )
			{
				strcpy( dtmp , search );
				while( dtmp[i] != '\0' )
				{
				dtmp[i] = dtmp[i+1];
				i++;
				}
			//	printf("%s",dtmp);
				ldelete( llist , dtmp );
				printf("%s is deleted\n",dtmp);
			}
			else
			{
			lfindit = lfind( llist , search );
			if( lfindit != NULL )
			{
				printf("%s %s\n",lfindit->string , lfindit->number);
			}
			}
				
		}
}

struct lnode* linsert( struct lnode *llist , char tmp[] , char integer[] )
{
	struct lnode *newp;
			
		newp = (struct lnode*) malloc(sizeof(struct lnode));

			strcpy( newp->string , tmp );
			strcpy( newp->number , integer );
			newp->next = llist;
		
			llist = newp;
		
			return llist;
}
struct lnode* ldelete( struct lnode *llist , char dtmp[] )
{
	int state;
	struct lnode *ptr , *lastp;
	ptr = llist;
	while( llist != NULL )	
	{	
			state = OFF;
		if( strcmp( llist->string , dtmp ) == 0 )
		{
					state = ON;
						break;
		}
		
		else
		{
			lastp = llist;
			llist = llist->next;
		}
	}
	
	if( state == ON )
	{
		if( llist == ptr )
		{
			llist = ptr->next;
			free(ptr);
			return llist;
		}
		else
		{
		ptr = llist;
		lastp->next = ptr->next;
		free(ptr);
		return llist;
		}
	}
}
struct lnode* lfind( struct lnode *llist , char search[] )
{
	
	while( llist != NULL )
	{
		if(strcmp( llist->string , search ) == 0 )
				break;
		else
				llist = llist->next;
	}
	return llist;
}
void lprintf( struct lnode *llist )
{
	struct lnode *ptr;
	ptr = llist;
	while( ptr != NULL )
	{
		printf( "%s %s\n" , ptr->string , ptr->number );
		ptr = ptr->next;
	}
}
