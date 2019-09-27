#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct lnode 
{
	char key[300];
	int value;
	struct lnode *next;
};

struct lnode *l_insert( struct lnode * , char [] , int );
int l_delete( struct lnode * , char [] );
struct lnode *l_find( struct lnode * , char [] );
void l_print( struct lnode * );
int main( int argc , char *argv[] )
{
	struct lnode *llist , *lfind;
	FILE *fp , *fp1;
	char tmp[300] = {0} , string[300] = {0} , val[300] = {0};	
	int num = 0 , state = 0;
	
	if( argc == 3 )
	{
		fp = fopen( argv[1] , "r" );
		while( fgets( tmp , 300 , fp ) )
		{
			sscanf( tmp , "%s %s" , string , val );
			num = atoi(val);
			if( strcmp( string , "PRINT" ) == 0 )
			{
				memset( string , 0 , sizeof(string) );
				memset( val , 0 , sizeof(val) );
				continue;
			}
			llist = l_insert( llist , string , num );
			memset( string , 0 , sizeof(string) );
			memset( val , 0 , sizeof(val) );
		}
	
		memset( tmp , 0 , sizeof(tmp) );		
		fp1 = fopen( argv[2] , "r" );
	
		while( fgets( tmp , 300 , fp1 ) )
		{
			strncpy( string , tmp , strlen(tmp)-1 );
	//		printf("%s\n",string);	
			if( strcmp( string , "PRINT" ) == 0 )
				l_print( llist );
		
			else if( tmp[0] == '-' )
			{
				sscanf( tmp , "-%s" , val );
				printf("%s\n",val);
				state = l_delete( llist , val );
				if( state == 0 )
					printf("%s NOT_FOUND\n" , val);	
				
				else
					printf("%s DELETED\n" , val);
			}
		
			else
			{
				lfind = l_find( llist , string );
				if( lfind == NULL )
					printf( "%s NOT_FOUND\n" , string );	
				else
					printf( "%s %d\n" , lfind->key , lfind->value );
			}
			memset( string , '\0' , sizeof(string) );			
		}
	}
	return 0;
}
struct lnode *l_insert( struct lnode *llist , char string[] , int num )
{
	struct lnode *ptr;
	ptr = (struct lnode*)malloc(sizeof(struct lnode));
	
		
		strcpy( ptr->key , string );
		ptr->value = num;
		ptr->next = llist;
		llist = ptr;
		return llist;
				
}
int l_delete( struct lnode *llist , char string[] )
{
	struct lnode *ptr , *lastp;
	ptr = lastp = llist;

	while( llist != NULL )
	{
		lastp = llist;
		if( strcmp( llist->key , string ) == 0 )
		{		break;
		else
		{
			ptr = llist;
			llist = llist->next;
		}
	}

	if( lastp == ptr )
	{
		ptr = llist->next;
		free( llist );
		return 1;
	}
	else
	{
		ptr->next = lastp->next;
		free( lastp );
		return 1;
	}
	return 0;
}
struct lnode *l_find( struct lnode *llist , char string[] )
{
	while( llist != NULL )
	{
		if( strcmp( llist->key , string ) == 0 )
				break;
		else
				llist = llist->next;
	}
	return llist;
}

void l_print( struct lnode *llist )
{
	while( llist != NULL )
	{
		printf( "%s %d\n" , llist->key , llist->value );
		llist = llist->next;
	}
}
