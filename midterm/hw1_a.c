#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TRUE 1
#define FALSE 0
int main( int argc , char **argv )
{
	int i = 0 , len = 0 , state;
	char tmp[1000] = {0} , *ptr = NULL , *ptr1 = NULL , *ptr2 = NULL;
	while( fgets( tmp , 1000 , stdin )!= NULL)
	{
		len = strlen( argv[1] );
		if ( argc == 3 )
		{
			ptr = strstr( tmp , argv[1] );
			ptr1 = tmp;
			ptr2 = tmp;
			while( *ptr1 != *ptr )
			{
					printf( "%c" , *ptr1 );
					ptr1++;
			}
				while( *ptr1 != '\0' )
				{
					ptr = strstr( ptr2 , argv[1] );
					
					state = FALSE;
					if( strstr( ptr1 , argv[1] ) == NULL )
					{
						printf( "%s" , ptr1 );
						state = TRUE;
					}
					else
					{
						while( *ptr1 != *ptr )
						{
							printf( "%c" , *ptr1 );
							ptr1++;
						}
							printf( "%s" , argv[2] );
							ptr2 = ptr2 + len;
							ptr1 = ptr1 + len;
					}
					if(state == TRUE)
					{
							break;
					}	
			}
		
		}
	}
}
