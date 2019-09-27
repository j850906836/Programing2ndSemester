#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define ON 1
#define OFF 0
struct array
{
	char word[100];
	int count;
};
void arrayD( struct array *arrayCNT , int i , int num );
void arrayP( struct array *arrayCNT , int num );
int mycompare( const void *x , const void *y );
void main()
{
	struct array arrayCNT[100];
	char tmp[100] = {0} , string[100] = {0} , *ptr = NULL , pre[100];
	int i , state , num = 0 , len = 0;
	while(fgets( tmp , 100 , stdin ))
	{
		sscanf( tmp , "%[^a-z]%[a-z]" , pre , string );
	//	printf("%s\n" , prefix);
	//	printf("%s\n" , stringa);
		if( pre == NULL )
		{
			memset( pre , 0 , sizeof(pre) );
			memset( string , 0 , sizeof(string) );
		}
		else if( pre[0] == '+' )
		{
			len = strlen(pre);
			state = OFF;
			for( i = 0; i<num; i++ )
			{
				if(strcmp( arrayCNT[i].word , string)==0)
				{
					state = ON;
					break;
				}
			}
			if( state == ON )
			{
				arrayCNT[i].count += len;
			}
			else
			{
				strcpy( arrayCNT[num].word , string );
				arrayCNT[num].count = len;
				num++;
			}
			memset( pre , 0 , sizeof(pre) );
			memset( string , 0 , sizeof(string) );

		}
		else
		{
			len = strlen(pre);
			state = OFF;
			for( i = 0; i<num; i++ )
			{
				if(strcmp( arrayCNT[i].word , string)==0)
				{
					state = ON;
					break;
				}
			}
			if( state == ON )
			{
				arrayCNT[i].count -= len;
				if(arrayCNT[i].count < 1)
				{
					arrayD( arrayCNT , i  , num );		
					num--;
				}
			}
			memset( pre , 0 , sizeof(pre) );
			memset( string , 0 , sizeof(string) );

		}
	}
//	printf("%d\n",num);
	qsort( arrayCNT , num , sizeof( struct array ) , mycompare );	
	arrayP( arrayCNT , num );
}
void arrayP( struct array *arrayCNT , int num )
{
	int i = 0;
	for( i = 0; i < num; i++ )
	{
	printf("%s %d\n" , arrayCNT[i].word , arrayCNT[i].count);
	}
}
void arrayD( struct array *arrayCNT , int i , int num )
{
	int c;
	for( c = i; c<num; c++ )
	{
		strcpy( arrayCNT[c].word , arrayCNT[c+1].word );
		arrayCNT[c].count = arrayCNT[c+1].count;
	}
	
}
int mycompare( const void *x , const void *y )
{
	struct array *a = (struct array*)x;
	struct array *b = (struct array*)y;
	
	if( a->count == b->count )
		return (strcmp( a->word , b->word ) );
	else
		return( b->count - a->count );	
}
