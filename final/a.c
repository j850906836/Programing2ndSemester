#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 300

struct arr
{
	char key[MAX];
};

int main(int argc , char *argv[])
{
	struct arr array[MAX];
	char tmp[MAX] = {0};
	int len , i , j = 0;
	FILE *fp;
	if( argc == 2 )
	{
		fp = fopen( argv[1] , "r+" );
		
		while( fgets( tmp , MAX , fp ) )
		{
			if( tmp[0] == '\n' )
				continue;
			len = strlen(tmp);
			for( i=0; i<len; i++ )
			{
				tmp[i] = tolower(tmp[i]);
			}
			strcpy( array[j].key , tmp );
			j++;			
		}
		
	}

			fp = fopen( argv[1] , "w+" );
	
			for( i=0; i<j; i++ )
			{
				fprintf( fp , "%s" , array[i].key );
			}
	return 0;
}
