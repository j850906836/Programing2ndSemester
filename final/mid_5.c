#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 300

struct arr
{
	char key[MAX];
};
int mycompare( const void * , const void * );
int main( int argc , char *argv[] )
{
	struct arr array[MAX];
	char tmp[MAX] = {0};
	int len , i = 0;
	FILE *fp;
	fp = fopen( argv[1] , "r" );
	if( argc == 2 )
	{
		while( fgets( tmp , MAX , fp ) )
		{
			len = strlen(tmp);	
			if( tmp[len-1] == '\n' || tmp[len-1] == EOF )
					tmp[len-1] = '\0';
			strcpy( array[i].key , tmp );
			i++;
		}
		len = i;
		qsort( array , len , sizeof(struct arr) , mycompare );
		
		for( i=0; i<len; i++ )
		{
			printf("%s\n",array[i].key);
		}
	}
	return 0;
}
int mycompare( const void *x , const void *y )
{
	struct arr *a = (struct arr*)x;
	struct arr *b = (struct arr*)y;

	return( strcmp( a->key , b->key ) );
}
