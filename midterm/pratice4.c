#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct treep
{
	char key[100];
	char numb[100];
	struct treep* lChild;
	struct treep* rChild;
};
void BST123_print( struct treep* BST123 );
void BST_print( struct treep* BST );
struct treep* BST_find( struct treep* BST , char string[]);
struct treep* BST_insert( struct treep* BST , char string[] , char num[] );
int main( int argc , char*argv[] )
{
	struct treep *BST , *BST123;
	FILE *fp1 , *fp2;
	char tmp[100] , string[100] , number[100] , *ptr = NULL , *lastp;
	int i = 0 , num , len = 0;
	fp1 = fopen( argv[1] , "r" );
	fp2 = fopen( argv[2] , "r" );
	
	while(fgets( tmp , 100 ,fp1)!=NULL)
	{
//		printf("%s\n",tmp);
	
		ptr = tmp;
		i = 0;
		while( *ptr != ' ' )
		{
			string[i++] = *ptr;
			ptr++;
		}
//		printf("%s\n",string);
		i = 0;
		ptr++;
		while( *ptr != '\n' )
		{
			number[i++] = *ptr;
			ptr++;
		}
//		printf("%s\n",number);
	
	//	num = atoi(number);
//		printf("%d\n",num);
		BST = BST_insert( BST , string , number );
		memset( tmp , 0 , sizeof(tmp) );
		memset( string , 0 , sizeof(string) );
		memset( number , 0 , sizeof(number) );
	}
	memset( tmp , 0 , sizeof(tmp) );
	BST_print( BST );
	while(fscanf( fp2 , "%s" , string )!=EOF)
	{
		printf("%s\n",string);	
	//	sscanf( tmp , "%s" , string );
		BST123 = BST_find( BST , string );
		if( BST123 == NULL )
				printf("%s unknown\n",string);
		else
			BST123_print( BST123 );	
		memset( string , 0 , sizeof(string) );
	}

}
struct treep *BST_insert( struct treep* BST , char string[] , char num[] )				
{
	int c;
	struct treep *ptr;
	ptr = (struct treep*) malloc(sizeof(struct treep));
	if(BST==NULL)
	{	
		strcpy( ptr->key , string );
		strcpy( ptr->numb , num);
		BST->lChild = NULL;
		BST->rChild = NULL;
		return BST;
	}
	c = strcmp( BST->key , string );
	if( c<0 )
	{
		ptr =  BST_insert( BST->lChild , string , num );
		BST->lChild = ptr;
		return BST;
	}
	if( c==0 )
	{
		return BST;
	}
	if( c>0 )
	{
		ptr = BST_insert( BST->rChild , string , num );
		BST->rChild = ptr;
		return BST;
	}
}
struct treep *BST_find( struct treep* BST , char string[] )
{
	int c;
	if(BST == NULL)
			return NULL;
	c = strcmp( BST->key , string );

	if( c < 0 )
		return BST_find( BST->lChild , string );
	if( c > 0 )
		return BST_find( BST->rChild , string );
	if( c == 0 )
		return BST;
}			
void BST_print( struct treep* BST )
{
	if( BST != NULL )
	{
		BST_print( BST->lChild );
		printf( "%s %d\n", BST->key , BST->numb );
		BST_print( BST->rChild );
	}	
}
void BST123_print( struct treep* BST123 )
{
	printf("%s %d\n" , BST123->key , BST123->numb );	
}
