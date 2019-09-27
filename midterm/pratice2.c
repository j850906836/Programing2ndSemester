#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc , char * argv[])
{
	char tmp[100] = {0} , *ptr = NULL , *ptr1 = NULL , *lastp = NULL;
	
	while(fgets( tmp , 100 , stdin ))
	{
		ptr = tmp;
		lastp = strstr( tmp , argv[1] );

		while( *ptr != *lastp )
		{
			printf("%c",*ptr);
			ptr++;
		}
			printf( "%s", argv[2] );
			ptr = ptr+strlen(argv[1]);
		while( *ptr != '\0' )
		{
				ptr1 = ptr;
			if( strstr( ptr1 , argv[1] ) == NULL )
			{
				printf("%s",ptr);
				break;
			}
			else
			{
				lastp = strstr( ptr , argv[1]);	
			
				while( *ptr != *lastp )
				{
					printf("%c",*ptr);
					ptr++;
				}
					printf("%s",argv[2]);
					ptr = ptr+strlen(argv[1]);
			}
	
		}
	}
	return 0;
}
