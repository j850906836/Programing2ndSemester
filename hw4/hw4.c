#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define TRUE 1
#define FALSE 0
typedef struct
{
	char word[110];
	int  cnt;
}
tcount;

int main()
{
	tcount wordcnt[10100];
	char tmp[110] = {0} , stringtmp[110] = {0} , *ptr , *ptr1 , string[110] = {0};
	int len = 0 , i = 0 , j = 0 , state , cnttmp = 0;
	
	while( fgets( tmp , 110 , stdin ) != NULL )
   	{
         ptr = tmp;
         while( *ptr != '\n' )
		 {
		     if( isalpha(*ptr) )
		     		 break;
			 else 
			 		 ptr++;
		 }
		 ptr1 = ptr;
		 
		 while(*ptr1 != '\n' )
		 {
		 	if( isspace(*ptr1) || ( *ptr1 == '\n' ) )
		 			break;
			else
					ptr1++;
		 }
		 i = 0;	
		 while( *ptr != *ptr1 )
		 {
		 	string[i++] = *ptr;
		 	ptr++;
		 }
		 state = TRUE;
		 for( i = 0; i < len; i++ )
		 {
		 	if( strcmp( wordcnt[i].word , string ) == 0 )
			{		
					wordcnt[i].cnt += 1;
		 			state = FALSE;
		 	}
		 }
		 if( state == TRUE )
		 {		 		 
		 strcpy( wordcnt[len].word , string );
		 wordcnt[len].cnt = 1;
		 len++;
		 }
		 memset( string , 0 , sizeof(string) );
		 
	}
	for( j = 0; j < len-1; j++ )
	{
		for( i = 0; i < len-j-1; i++ )
		{
			if(strcmp( wordcnt[i].word , wordcnt[i+1].word ) > 0)
			{
				strcpy( stringtmp , wordcnt[i+1].word );
				cnttmp = wordcnt[i+1].cnt;

				strcpy( wordcnt[i+1].word , wordcnt[i].word );
				wordcnt[i+1].cnt = wordcnt[i].cnt;

				strcpy( wordcnt[i].word , stringtmp );
				wordcnt[i].cnt = cnttmp;
			}
		}
	}
	for( j = 0; j < len-1; j++ )
	{
		for( i = 0; i < len-j-1; i++ )
		{
			if( wordcnt[i].cnt < wordcnt[i+1].cnt )
			{
				strcpy( stringtmp , wordcnt[i+1].word );
				cnttmp = wordcnt[i+1].cnt;

				strcpy( wordcnt[i+1].word , wordcnt[i].word );
				wordcnt[i+1].cnt = wordcnt[i].cnt;

				strcpy( wordcnt[i].word , stringtmp );
				wordcnt[i].cnt = cnttmp;
			}
		}
	}
	for( i = 0; i < len; i++ )
	{
		printf("%d %s\n",wordcnt[i].cnt , wordcnt[i].word );
	}
	return 0;	
}

