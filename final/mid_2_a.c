#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 300

struct arr 
{
	char key[MAX];
};
int mycompare( const void * , const void * );
int main()
{
	struct arr array[MAX];
	char tmp[MAX] = {0};
	int i = 0 , len;

	while( fgets( tmp , MAX , stdin ) )
	{
		len = strlen(tmp);	
		if( tmp[len-1] == '\n' || tmp[len-1] == EOF )
		tmp[len-1] = '\0';
		strcpy( array[i].key , tmp );
		i++;
	}
	
	qsort( array , i , sizeof(struct arr) , mycompare );
	
	for( len=0; len<i; len++ )
	{
		printf("%s\n",array[len].key);
	}
	return 0;
}
int mycompare( const void *x , const void *y )
{
 	struct arr *a = (struct arr*)x;
 	struct arr *b = (struct arr*)y;

 	return ( strcmp ( a->key , b->key ) );
}
