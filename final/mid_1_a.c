#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 300
int main(int argc , char *argv[])
{
	char tmp[MAX] = {0} , *ptr , *ptr1;
	int len = strlen(argv[1]);
	if( argc == 3 )
	{
		while(fgets( tmp , MAX , stdin ) )
		{
			ptr = strstr( tmp , argv[1] );
		
			if( ptr == NULL )
			{	
				printf("%s",tmp);
				continue;
			}
			else
			{
				ptr1 = tmp;
				while( *ptr1 != '\0' )
				{
					if( ptr == NULL )
					{	
						printf("%s",ptr1);
						break;
					}
			
					while( ptr1 != ptr )
					{
						printf("%c",*ptr1);
						ptr1++;
					}
					printf("%s",argv[2]);
					ptr1 += len;
	//				printf("ptr1:%s\n",ptr1);
					ptr = strstr( ptr1 , argv[1] );
	//				printf("ptr:%s\n",ptr);
				}
				continue;
			}
		}
	}
	return 0;
}
