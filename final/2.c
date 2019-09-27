#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 1024
struct arr
{
	char key[MAX];
};
int main(int argc , char *argv[])
{
	struct arr array[MAX];
	char tmp[MAX] = {0} , *ptr;
	int i , cnt = 0;
	FILE *fp;
	fp = fopen( argv[1] , "r+" );
	if( argc == 2 )
	{
		while( fgets( tmp , MAX , fp ) )
		{	
			ptr = tmp;
			i=0;
			if( tmp[0] == '\n' || tmp[0] == EOF )
					continue;
			while(*ptr!='\n')
			{
				tmp[i] = tolower(tmp[i]);
				i++;
				ptr++;
			}
			strcpy( array[cnt].key , tmp );
			cnt++;
		}
	}
	fp = fopen( argv[1] , "w" );
	for( i=0; i<cnt; i++ )
	{
		fprintf( fp , "%s" , array[i].key );
	}
	return 0;
}
