#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
	char tmp[100] = {0} , *ptr = NULL , *lastp = NULL;

	while( fgets( tmp , 100 , stdin ) )
	{
		ptr = lastp = tmp;
		while( *ptr != '\0')
		{
			if( isalpha(*ptr) )
					break;
			else
					ptr++;
		}
		while( *ptr != '\0' )
		{
		  	printf( "%c" , *ptr );
		 
			if( (*(ptr+1) == ' ') && (*(ptr+2) == ' ') ) 
			{
				lastp = ptr+1;
				while( *lastp != '\0' )
				{
					if( isalpha(*lastp)||ispunct(*lastp) )
					{
						break;
					}
					else
					{ 
						lastp++;
					}
				}
				ptr = lastp-1;
			}
			else
			{
				ptr++;
			}
			
		}
	}
	return 0;
}
