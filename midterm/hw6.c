#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
struct array
{
	char key[10000];
	int num;
};
int mycompare( const void *x , const void *y );
void arrayP( struct array *arrayLine , int len );
int main()
{
	struct array arrayLine[100];
	char *ptr = NULL , tmp[100] = {0} , string[100] = {0} , number[100] = {0};
	int i , len = 0;;

	while(fgets( tmp , 100 , stdin ))
	{
		ptr = tmp;	
		i = 0;
		while( *ptr != '\n' )	
		{
			if( *ptr>='0' && *ptr<='9' )
			{
				number[i++] = *ptr;
			}
			ptr++;
		}
		printf("%d\n",atoi(number));
		strcpy( arrayLine[len].key , tmp );
		arrayLine[len].num = atoi(number);
		memset( tmp , 0 , sizeof(tmp) );
		memset( tmp , 0 , sizeof(tmp) );
		len++;
	}
	qsort( arrayLine , len , sizeof(struct array) , mycompare );
	arrayP( arrayLine , len );
	
}
void arrayP( struct array *arrayLine , int len )
{
	int i;
	for( i = 0; i < len; i++ )
	{
		printf("%s",arrayLine[i].key);
	}
}
int mycompare( const void *x , const void *y )
{
	struct array *a = (struct array *)x;
	struct array *b = (struct array *)y;
	return( a->num - b->num );
}
