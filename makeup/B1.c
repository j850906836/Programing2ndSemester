#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct arr
{
	char key[1004];
};
int mycompare( const void * , const void * );
int main()
{
	char tmp[1004] = {0};
	struct arr array[6000];
	int i = 0 , len = 0;
	while( fgets( tmp , 1004 , stdin ) )
	{
		len = strlen(tmp);
		tmp[len-1]='\0';
		strcpy( array[i].key , tmp);
		i++;
	}

	len = i;
	qsort( array , len , sizeof(struct arr) , mycompare);

	for( i=0; i<len; i++ )
	{
		printf("%s\n",array[i].key);
	}
	return 0;
}
int mycompare( const void *x, const void *y )
{
	struct arr *a = (struct arr*)x;
	struct arr *b = (struct arr*)y;
	
	return( strcmp(a->key,b->key) );
}
