#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX (1<<10)
#define found   1
#define unfound 0
struct node
{
                char *word;
                int value;
}key[1000];
int cmp(const void *x, const void *y)
{
                if(((struct node *)x)->value==((struct node *)y)->value)
                                return strcmp(((struct node *)x)->word, ((stru                                                ct node *)y)->word);
                return ((struct node *)y)->value-((struct node *)x)->value;
}
int main()
{
                int count=0, total=0, i=0, state=unfound;
                char *line, *ptr;
                line=(char *)malloc(MAX*sizeof(char));
                while(scanf("%s", line)!=EOF)
                {
                                ptr=line;
                                count=0;
                                if(*ptr=='+' || *ptr=='-')
                                {
                                                while((*ptr=='+' || *ptr=='-')                                                 && *ptr!='\0')
                                                {
                                                                if(*ptr=='+')
                                                                             c                                                ount++;
                                                                else if(*ptr==                                                '-')
                                                                             c                                                ount--;
                                                                ptr++;
                                                }
                                                for(i=0; i<total; i++)
                                                {
                                                                if(strcmp(key[                                                i].word, ptr)==0)
                                                                {
                                                                             k                                                ey[i].value+=count;
                                                                             s                                                tate=found;
                                                                }
                                                }
                                                if(state==unfound)
                                                {
                                                                key[total].wor                                                d=strdup(ptr);
                                                                key[total].val                                                ue+=count;
                                                                total++;
                                                }
                                                state=unfound;
                                }
                }
                qsort(key, total, sizeof(key[0]), cmp);
                for(i=0; i<total; i++)
                                printf("%s %d\n", key[i].word, key[i].value);
                free(line);
                return 0;
}