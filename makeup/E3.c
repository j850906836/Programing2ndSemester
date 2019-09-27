#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define ON 1
#define OFF 0

struct arr
{
	char key[1200];
	int cnt;
};
int mycompare( const void* , const void* );
int main()
{
	struct arr array[1000];
	char tmp[1200] = {0} , count[1200] = {0} , string[1200] = {0} , *ptr;
	int state , cnt = 0 , len = 0 , i = 0;
	while(fgets(tmp , 1200 , stdin))
	{
		ptr = tmp;
		cnt = 0;
		//printf("%s\t%s\n",count,string);
		if( *ptr != '+' || *ptr != '-' )
					cnt = 0;
		else
		{
			while( *ptr != '\0' )
			{
				if( *ptr != '+' || *ptr != '-' )
						break;
				else
				{
					if( *ptr == '+' )
							cnt++;
					else if( *ptr == '-' )
							cnt--;
				}
						ptr++;
			}
		}
		state = OFF;
		for( i=0; i<len; i++ )
		{
			if(strcmp( array[i].key , string ) == 0 )
			{
					array[i].cnt+=cnt;
					state = ON;
			}
		}
		if( state == OFF && cnt != 0)
		{
			strcpy( array[len].key , string );
			array[len].cnt = cnt;
			len++;
		}
		memset( count , 0 , sizeof(count) );
		memset( string , 0 , sizeof(string) );
	}
	qsort( array , len , sizeof(struct arr) , mycompare );
	for( i=0; i<len; i++ )
	{
		printf("%s %d\n",array[i].key,array[i].cnt);
	}
	return 0;
}

int mycompare( const void *x , const void *y )
{
	struct arr *a = (struct arr*)x;
	struct arr *b = (struct arr*)y;

	if( (a->cnt - b->cnt) == 0 )
			return strcmp( a->key , b->key );
	else
			return (b->cnt - a->cnt );
}
