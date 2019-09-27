#include <stdio.h>

struct lnode
{
	char key[100];
	int cnt;
	struct lnode *next;
};
struct lnode *linsert( struct lnode *llist , char string , int count );
int main()
{
		struct lnode *llist;
		char tmp[100] , *ptr , string[100] , number[100];
		int i;
		while(fgets( tmp , 100 ,stdin ) )
		{
			ptr = tmp;	
			i = 0;
			while( *ptr != ' ' )
			{
				string[i++] = *ptr;
				ptr++;
			}
			
			i = 0;
			ptr++;
			while( *ptr != '\n' )
			{
				number[i++] = *ptr;
				ptr++;
			}
			count = atoi(number);
			llist = linsert( llist , string , count );
			memset( tmp , 0 , sizeof(tmp);
		}
}
struct lnode *linsert( struct lnode *llist , char string , int count )
{
	struct lnode *newp , *ptr , *lastp;
	newp = (struct lnode*)malloc(sizeof(struct lnode));
	ptr = lastp = llist;
	
	if(llist == NULL)
	{
		strcpy( newp->key , string );
		newp->cnt = count;
		llist = newp;
		return llist;
	}
	if( llist != NULL && (strcmp( llist->key , string )<0)
	{
		


