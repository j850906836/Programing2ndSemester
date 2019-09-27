#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define ON 1
#define OFF 0
int main()
{
	char tmp[1004] = {0} , *ptr , *lastp;
	int state;
	while( fgets( tmp , 1004 , stdin ) )
	{
		ptr=tmp;
		state = ON;
		if(*ptr=='\0')
		{
			printf("\n");
			continue;
		}
		while( *ptr != '\0' )
		{
			if( isspace(*ptr) && isspace(*(ptr+1)) )
			{
				lastp = ptr;
				while(*lastp != '\n')
				{
					if( isalpha(*lastp)||ispunct(*lastp) )
					{
						lastp--;
						ptr = lastp;
						state = ON;
						break;
					}
					else
						lastp++;
				}
				if( *lastp == '\n' )
				{
					printf( " " );
					state = OFF;
					break;
				}
			}
			else
			{
				printf( "%c",*ptr );
				ptr++;
			}
		}
		if(state == OFF)
		{
		printf( "\n" );
		}
	}
	return 0;
}
