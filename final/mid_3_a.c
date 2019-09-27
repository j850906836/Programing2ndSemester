#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 30
struct node
{
      char *word;
      struct node *left;
      struct node *right;
};
struct node *insert(struct node *lnode, char *w);
void traversal(struct node *lnode);
int main()
{
          char line[MAX]={'\0'};
          struct node *key=NULL, *current;
 	      while(fgets(line, MAX, stdin)!=NULL)
    	  {
               key=insert(key, line);
          }
          current=key;
          traversal(current);
          return 0;
}
struct node *insert(struct node *lnode, char *w)
{
        int c;
        struct node *new, *current=lnode;
        new=(struct node *)malloc(sizeof(struct node));
        if(current==NULL)
        {
               new->word=strdup(w);
               new->left=new->right=NULL;
               lnode=new;
               return lnode;
        }
        c=strcmp(current->word, w);
        if(c>0)
           current->left=insert(current->left, w);
        else if(c<0)
           current->right=insert(current->right, w);
        return lnode;
}

void traversal(struct node *lnode)
{
        if(lnode!=NULL)
        {
              traversal(lnode->left);
              printf("%s", lnode->word);
              traversal(lnode->right);
        }
}
