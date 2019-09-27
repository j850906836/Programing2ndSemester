#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 300

int main(int argc , char *argv[])
{
	char tmp[MAX] = {0} , *find;
	FILE *fp;
	int len;

	fp = fopen( argv[argc-1] , "r" );
	
	if(argc == 3)
	{
		while( fgets( tmp , MAX , fp ) )
		{
			find = strstr( tmp , argv[1] );
			if( find != NULL )
					printf( "%s",tmp );
			else
					continue;
		}
	}
	if( argc == 4 )
	{
		if( strcmp( argv[1] , "-i" ) == 0 )
		{
			while( fgets( tmp , MAX , fp ) )
			{
				find = strcasestr( tmp , argv[2] );
				if( find != NULL )
						printf( "%s",tmp );
				else
						continue;
			}
		}

		if( strcmp( argv[1] , "-x" ) == 0 )
		{
			while( fgets( tmp , MAX , fp ) )
			{
				len = strlen(tmp);
				if( tmp[len-1] == '\n' || tmp[len-1] == EOF )
						tmp[len-1] = '\0';
				if( strcmp( argv[2] , tmp ) == 0 )
				{
					printf( "%s\n",tmp );
				}
				else
					continue;
			}
		}
	}
	if( argc == 5 )
	{
		while( fgets( tmp , MAX , fp ) )
		{
			if( ( strcmp(argv[1] , "-i") == 0 && strcmp(argv[2] , "-x") == 0 ) || ( strcmp(argv[1] , "-x") == 0 && strcmp(argv[2] , "-i") == 0 ))
			{
				len = strlen(tmp);
				if( tmp[len-1] == '\n' || tmp[len-1] == EOF )
						tmp[len-1] = '\0';
				if( strcasecmp( argv[3] , tmp ) == 0 )
				{
					printf( "%s\n",tmp );
				}
				else
						continue;
			}	
		}
	}

	return 0;
}
