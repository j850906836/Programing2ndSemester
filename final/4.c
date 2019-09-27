#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1024

struct arr
{
	char key[MAX];
};
int mycompare( const void *x , const void *y );
int main()
{
	struct arr array[MAX];
	char tmp[MAX] = {0};
	int i=0 , len;
	
	while( fgets( tmp , MAX , stdin ) )
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
	return 0;
}
int mycompare( const void *x , const void *y )
{
	struct arr *a = (struct arr*)x;
	struct arr *b = (struct arr*)y;

	return (strcmp( a->key , b->key ) );
}
