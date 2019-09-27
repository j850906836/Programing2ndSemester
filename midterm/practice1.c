#include <stdio.h>
#include <string.h>

struct array 
{
	char key[100];
};
void arrayP( struct array *arraysort , int len );
int mycompare( const void *x , const void *y );
int main()
{
	struct array arraysort[10000];
	char tmp[100] = {0} , string[100] = {0};
	int i , len = 0;
	FILE *fp;
	fp = fopen( "Q1.txt","r");
	
	while(fgets( tmp , 100 , fp ))
	{
		strcpy( arraysort[len].key , tmp );
		memset( tmp , 0 , sizeof(tmp) );
		len++;
	}
	qsort( arraysort , len , sizeof(struct array) , mycompare );
	arrayP( arraysort , len );
}
void arrayP( struct array *arraysort , int len )
{
	int i;
	for( i = 0; i < len; i++ )
	{
		printf("%s",arraysort[i].key);
	}
}
int mycompare( const void *x , const void *y )
{
	struct array *a = (struct array*)x;
	struct array *b = (struct array*)y;

	return(strcmp( a->key , b->key ));
}
