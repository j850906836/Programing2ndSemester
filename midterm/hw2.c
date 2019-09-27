#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BIG 0
#define SMALL 1
typedef struct 
{
	char word [100];	
}
sort;

void sorts_d( sort * , int );
void sorts_n( sort * , int );
void print( sort * , int );
int mycompareBIG( const void *x , const void *y );
int mycompareSMALL( const void *x , const void *y );

int main( int argc , char **argv)
{
	sort sortword[100];
	char tmp[100] = {0} , string[100] = {0};
	int i = 0 , state;
	
	while( fgets( tmp , 100 , stdin ) )
	{
		sscanf( tmp , "%s" , string );
		strcpy( sortword[i].word , string );
		memset( string , 0 , sizeof(string) );
		i++;	
	}
	if( argc == 2 )
	{
		if( strcmp( argv[1] , "-n" ) == 0 )
		{
			sorts_n( sortword , i );
		}
		else if ( strcmp( argv[1] , "-d" ) == 0 )
		{
			sorts_d( sortword , i );
		}
	}
	if( argc == 3 )
	{
		if( ( strcmp( argv[1] , "-n" ) == 0 ) || ( strcmp( argv[2] , "-n" ) == 0 ) )
				state = SMALL;
		else if( ( strcmp( argv[1] , "-d" ) == 0 ) || ( strcmp( argv[2] , "-d" ) == 0 ) )
				state = BIG;
	}
	if(	state == SMALL )
	{
		qsort( sortword , i , sizeof( sort ) , mycompareSMALL );
	}
	else if( state == BIG )
	{
		qsort( sortword , i , sizeof( sort) ,mycompareBIG );
	}
	print( sortword , i );
	return 0;
}
void sorts_d( sort * sortword , int len )
{
	int i , j;
	char tmp[100];

	for( i = 0;i < (len - 1); i++ )
	{
		for( j = 0; j < (len - i - 1); j++ )
		{
		
			if( strcmp( sortword[j].word , sortword[j+1].word ) < 0	)
			{
				strcpy( tmp , sortword[j].word );
				strcpy( sortword[j].word , sortword[j+1].word );
				strcpy( sortword[j+1].word , tmp );
			}
			
		}
	}
}
void sorts_n( sort * sortword , int len )
{
	int i , j;
	char tmp[100];

	for( i = 0;i < (len - 1); i++ )
	{
		for( j = 0; j < (len - i - 1); j++ )
		{
		
			if( strcmp( sortword[j].word , sortword[j+1].word ) > 0	)
			{
				strcpy( tmp , sortword[j].word );
				strcpy( sortword[j].word , sortword[j+1].word );
				strcpy( sortword[j+1].word , tmp );
			}
			
		}
	}
}
void print( sort * sortword , int len )
{
	int i = 0;
	while( i < len )
	{
	printf( "%s\n" , sortword[i].word );
	i++;
	}
}
int mycompareBIG( const void *x , const void *y )
{
	sort* yes = (sort*)x;
	sort* no = (sort*)y;

	return( strcmp( no -> word , yes -> word ) );
}
int mycompareSMALL( const void *x , const void *y )
{
	sort* yes = (sort*)x;
	sort* no = (sort*)y;

	return( strcmp( yes -> word , no -> word ) );
}
