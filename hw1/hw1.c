#include <stdio.h>
#define _GNU_SOURCE_
#include <string.h>
#include <ctype.h>
#define SIZE 10000


void mode_3 ( char ** ) ;
void mode_i ( char ** ) ;
void mode_a ( char ** ) ;
void mode_i_a (char ** ) ;
int main ( int argc, char **argv )
{
	
		if( argc == 1 )
		{
				printf("the format of Substitution:\n\n") ;
				printf("./substitute [-i] [-a] [source_pat] [target_pat]\n") ;
		}

		else if( argc == 2 )
		{
				printf("the format of Substitution:\n\n") ;
				printf("./substitute [-i] [-a] [source_pat] [target_pat]\n") ;
		}

		else if( argc == 3 )
		{
				mode_3(argv);
		}

		else 
		{
				if( argv[2][0] != '-' )
				{
						if( argv[1][0]	== '-' )
						{
								if( argv[1][1] == 'i' )
								{
										mode_i(argv);
								}
								else if( argv[1][1] == 'a' )
								{
										mode_a(argv);
								}
								else 
								{
										 printf("the format of Substitution:\n\n") ;
										 printf("./substitute [-i] [-a] [source_pat] [target_pat]\n") ;
								}
						}
				}
				else if( argv[1][0] =='-' && argv[2][0] == '-' )
				{
						if( argv[1][1] == 'i' && argv[2][1] == 'a' )
						{
								mode_i_a(argv) ;
						}
						else if( argv[1][1] == 'a' && argv[2][1] == 'i' )
						{	
								mode_i_a(argv) ;
						}
						else 
						{
								printf("the format of Substitution:\n\n") ;
								printf("./substitute [-i] [-a] [source_pat] [target_pat]\n") ;
						}
				}




		}


		return 0 ;
}

void mode_3 ( char **argv )
{
		int len = 0 ;
		char sentence[SIZE] = {0} ;
		char *ptr1 = 0 , *ptr2 = 0 ; 

		while( fgets( sentence, SIZE , stdin) != NULL)
		{
				len = strlen( argv[1] ) ;
				ptr1 = sentence ;
				ptr2 = strstr( sentence , argv[1] ) ;


				if( ptr2 == NULL )
				{
						printf( "%s" , ptr1 );
				}

				else
				{
						while( ptr1 != ptr2 )
						{
								printf( "%c" , *ptr1 ) ;
								ptr1++ ;
						}

						printf( "%s" , argv[2] ) ;
						printf( "%s" , ptr1+len ) ;
				}
		}
}

void mode_i ( char **argv ) 
{
		int len = 0 ;
		char sentence[SIZE] = {0} ;
		char *ptr1 = 0 , *ptr2 = 0 ;

		while( fgets( sentence, SIZE , stdin) != NULL)
		{
				len = strlen( argv[2] ) ;
				ptr1 = sentence ;
				ptr2 = strcasestr( sentence , argv[2] ) ;


				if( ptr2 == NULL )
				{
						printf( "%s" , ptr1 );
				}

				else
				{
						while( ptr1 != ptr2 )
						{
								printf( "%c" , *ptr1 ) ;
								ptr1++ ;
						}

						printf( "%s" , argv[3] ) ;
						printf( "%s" , ptr1+len ) ;
				}
		}
}

void mode_a ( char **argv )
{
		int len = 0 ;
		char sentence[SIZE] = {0} ;
		char  *ptr1 = 0 , *ptr2 = 0 , *ptr3 = 0 ;

		while( fgets( sentence, SIZE , stdin) != NULL)
		{
				len = strlen( argv[2] ) ;
				ptr1 = sentence ;
				ptr2 = strstr( sentence , argv[2] ) ;


				if( ptr2 == NULL )
				{
						printf( "%s" , ptr1 );
				}

				else
				{
						while( ptr2 !='\0' )
						{
								ptr3 = strstr( ptr2 , argv[2] ) ;
								while( ptr1 != ptr3 )
								{
										printf( "%c" , *ptr1 ) ;
										ptr1++ ;
								}

								printf( "%s" , argv[3] ) ;

								ptr2 = ptr1 + len ;
								if( strstr( ptr2 , argv[2] ) == NULL )
								{
										printf( "%s" , ptr1+len ) ;
										break ;
								}
								else 
								{
										ptr1 += len ;
								}											
						}
				}
		}
}

void mode_i_a ( char **argv )
{
		int len = 0 ;
		char sentence[SIZE] = {0} ;
		char *ptr1 = 0 , *ptr2 = 0 , *ptr3 = 0 ;

		while( fgets( sentence, SIZE , stdin) != NULL)
		{
				
				len = strlen( argv[3] ) ;
				ptr1 = sentence ;
				ptr2 = strcasestr( sentence , argv[3] ) ;


				if( ptr2 == NULL )
				{
						printf( "%s" , ptr1 );
				}

				else
				{
						while( ptr2 !='\0' )
						{
								ptr3 = strcasestr( ptr2 , argv[3] ) ;
								while( ptr1 != ptr3 )
								{
										printf( "%c" , *ptr1 ) ;
										ptr1++ ;
								}

 							 printf( "%s" , argv[4] ) ;

								ptr2 = ptr1 + len ;
								if( strcasestr( ptr2 , argv[3] ) == NULL )
								{
										printf( "%s" , ptr1+len ) ;
										break ;
								}
								else
								{
										ptr1 += len ;
								}    
						}

				}
		}
}


