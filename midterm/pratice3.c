#include <stdio.h>
#include <ctype.h>

int main()
{
	char tmp[100] = {0} , *ptr , *ptr1;	
		
	while(fgets( tmp , 100 , stdin ))
	{
		ptr = tmp;
		
		while( *ptr != '\n' )
		{
			while( *ptr != '\n' )
			{
				if( *(ptr) == ' ' && *(ptr+1) == ' ' )
							break;
				else
				{	printf("%c",*ptr);
					ptr++;
				}
			}
			
			while( *ptr != '\n' )
			{	
				if( tmp[0] == ' ' )
				{
					if(isalpha(*ptr))
					{	
						printf(" ");	
						break;
					}	
					else
						ptr++;	
				}
				if(isalpha(*ptr))
				{	
					printf(" ");	
					break;
				}
				else
					ptr++;
			}
			
		}
	}
}
