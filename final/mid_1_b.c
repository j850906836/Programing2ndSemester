#include<stdio.h>
#include<stdlib.h>
#define MAX 128
int main()
{
                char line[MAX]={'\0'}, *ptr;
                while(fgets(line, MAX, stdin)!=NULL)
                {
                                ptr=line;

                                while(*ptr!='\0')
                                {
                                                if(*ptr=='\n')
                                                                break;
                                                if(*ptr==' ')
                                                {
                                                                printf("%c", *ptr);
                                                                while(*ptr==' ' && *ptr!='\0')
                                                                {
                                                                                ptr++;
                                                                }
                                                }
                                                else
                                                {
                                                                printf("%c", *ptr);
                                                        ptr++;
                                                }
                                }
                                printf("\n");
                }
                return 0;
}
