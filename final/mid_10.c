#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 300
struct arr
{
	char key[MAX];
	int data;
};
int mycompare( const void * , const void * );
int main()
{
	struct arr array[MAX];
	char tmp[MAX] = {0} , data[MAX] = {0} , *ptr;
	int i , j = 0 , len;

	while( fgets( tmp , MAX , stdin ) )
	{
		len = strlen(tmp);
		if( tmp[len-1] == '\n' || tmp[len-1] == EOF )
				tmp[len-1] = '\0';
		ptr = tmp;
		i = 0;
		while( *ptr != '\0' )
		{
			if( isdigit(*ptr) )
			{
				data[i++] = *ptr;
				ptr++;
			}
			else
				ptr++;
		}
		
		strcpy( array[j].key , tmp );
		array[j].data = atoi(data);
		j++;
	}
	
	len = j;
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

	return ( a->data - b->data );
}
