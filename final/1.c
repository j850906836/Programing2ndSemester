#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1024

int main()
{
	char tmp[MAX] = {0} , *ptr;	

	while( fgets( tmp , MAX , stdin ) )
	{
			ptr = tmp;
		while( *ptr != '\n' )
		{
			if( *ptr == ' ' )
			{
				printf("%c",*ptr);
				ptr++;
				while( *ptr == ' '||*ptr == EOF )
				{
					ptr++;
				}
			}
			else
			{
				printf("%c",*ptr);
				ptr++;
			}
		}
		printf("\n");
	}
	return 0;
}
