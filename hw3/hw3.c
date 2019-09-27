#include <stdio.h>
#include <stdlib.h> 
#include <ctype.h>
#include <string.h>
#define CNT 10000
#define ON 1
#define OFF 0
typedef struct 
{
		char name[20];
		char id[20];
		int age;
		char phone[20];
}
addr;
void insert( addr * , int );
void list( addr * , int );
void find( addr * , int );
void update( addr * , int );
void sort_id( addr * , int );
void sort_name( addr * , int );
void sort_phone( addr * , int );
void sort_age( addr * , int );

int main()
{
		addr addrbook[CNT];
		int i = 0 , agetmp = 0 , len = 0 , search = 0 , light = OFF; 
		char command , tmp[100] = {0} , itoaage[10000][20] , string[20] = {0} , idtmp[20] = {0} , idold[20] = {0} , idnew[20] = {0} , nametmp[20] = {0} , phonetmp[20] = {0};
		char *ptr , *ptr1 , *ptr2;

		printf("Please input command(i/d/u/f/l/s/w/q) and data.\n");
		while( fgets( tmp , 100 , stdin ) != NULL )
		{
				
				ptr = tmp;
		
				while( *ptr != '\n' )
				{
						if(isalpha(*ptr))	
								break;
						else
								ptr++;
				}
				command = *ptr;
				if( command == 'q')	
						   return 0;
				while( (command != 'q') )
				{
						if( *ptr == '\n' )
						{
							printf("Please input command(i/d/u/f/l/s/w/q) and data.\n");
							break;
						}
						if( command == 'i' )
						{
								ptr = tmp;
								while( *ptr != '\n' )
								{
										if( *ptr == ',' )
												break;
										else
												ptr++;
								}
										i = 0;	
								while( *ptr != '\n' )
								{
										if( isdigit(*ptr)	|| isalpha(*ptr))
												break;
										else
												ptr++;
								}
									ptr1 = ptr;

								while( *ptr != '\n' )
								{
										if( *ptr == ',' )
												break;
										else
												ptr++;
								}
								if( *ptr == '\n' )
								{
								printf("Please input command(i/d/u/f/l/s/w/q) and data.\n");
								break;
								}
								ptr2 = ptr+1;
								ptr--;
								while( *ptr != '\n' )
								{	
										if( isdigit(*ptr) || isalpha(*ptr))
												break;
										else
												ptr--;
								}
								ptr++;

								while( ptr1 != ptr )
								{
										idtmp[i++] = *ptr1;				//insert id
										ptr1++;
								}
								light = OFF;
								for( i = 0; i<len; i++)
								{
										if(strcmp(addrbook[i].id , idtmp) == 0 )
										{
												printf("ERROR!!ID EXIST!!\n");
												memset( idtmp , 0 , sizeof(idtmp) );
												printf("Please input command(i/d/u/f/l/s/w/q) and data.\n");
												light = ON;
										}
								}
								if( light == ON )
										break;

								ptr = ptr2;
								while( *ptr != '\n' )
								{	
										if(	isalpha(*ptr) )
												break;
										else
												ptr++;
								}
								if( *ptr == '\n' )
								{
								printf("Please input command(i/d/u/f/l/s/w/q) and data.\n");
								break;
								}
								while( *ptr2!= '\n')
								{
										if( *ptr2 == ',' )
												break;
										else
												ptr2++;
								}
								if( *ptr2 == '\n' )
								{
								printf("Please input command(i/d/u/f/l/s/w/q) and data.\n");
								break;
								}
								ptr1 = ptr2;
								ptr1++;
								while( *ptr2 != '\n' )
								{
										if( isalpha(*ptr2) )
												break;
										else
												ptr2--;
								}
								ptr2 += 1;
								i=0;
								while( ptr != ptr2 )
								{
										nametmp[i++] = *ptr;    		//insert name
										ptr++;
								}
								ptr = ptr1;
								while( *ptr1 != '\n' )
								{
										if( isdigit(*ptr1) )
												break;
										else
												ptr1++;
								}
								if( *ptr1 == '\n' )
								{
								printf("Please input command(i/d/u/f/l/s/w/q) and data.\n");
								break;
								}
								while( *ptr != '\n' )
								{
										if( *ptr == ',' )
												break;
										else
												ptr++;
								}
								if( *ptr == '\n' )
								{
								printf("Please input command(i/d/u/f/l/s/w/q) and data.\n");
								break;
								}
								ptr2 = ptr;
								while( *ptr != '\n' )
								{
										if( isdigit(*ptr) )
												break;
										else
												ptr--;
								}
								ptr++;	
								i=0;
								while( ptr1 != ptr )
								{
										phonetmp[i++] = *ptr1;			//insert phone
										ptr1++;
								}
								
								ptr2++;
								while( *ptr2 != '\n' )
								{
										if( isdigit(*ptr2) )
												break;
										else
												ptr2++;
								}
								if( *ptr2 == '\n' )
								{
								printf("Please input command(i/d/u/f/l/s/w/q) and data.\n");
								break;
								}
								agetmp = atoi(ptr2);			//insert age

								strcpy( addrbook[len].id , idtmp );
								strcpy( addrbook[len].name , nametmp );
								strcpy( addrbook[len].phone , phonetmp );
								addrbook[len].age = agetmp;



								insert( addrbook ,len );	

								memset(idtmp, 0 , sizeof(idtmp));
								memset(nametmp, 0 , sizeof(nametmp));
								memset(phonetmp, 0 , sizeof(phonetmp));
								agetmp = 0;
								len++;
						}
						else if( command == 'l' )
						{
								list( addrbook , len);
						}
						else if( command == 'f' )
						{
								search = len;
								
								while( *ptr != '\n' )
								{
										if( *ptr == ',' )
												break;
										else
												ptr++;
								}
								while( *ptr != '\n' )
								{
										if( isalpha(*ptr) || isdigit(*ptr) )
												break;
										else
												ptr++;
								}
								if( *ptr == '\n' )
								{
										printf("Please input command(i/d/u/f/l/s/w/q) and data.\n");
										break;
								}
								i = 0;
								while( *ptr != '\n')
								{
										string[i++] = *ptr;				//insert find string
										ptr++;
								}

								i = 0;
								light = OFF;
								for( i = 0; i < len; i++ )
								{
									sprintf( itoaage[i] , "%d" , addrbook[i].age );
								}
								for( i = 0; i < len; i++ )
								{
										if( (strstr( addrbook[i].id , string ) != NULL) || (strstr( addrbook[i].phone , string ) != NULL) || (strstr( addrbook[i].name , string ) != NULL) || (strstr( itoaage[i] , string ) != NULL ) )
										{
												search = i;
												find( addrbook , search );
												light = ON;
										}

								}
								if( light == OFF )
								{
										printf("ERROR! STRING DOES NOT EXIST!\n");
								}
								printf("Please input command(i/d/u/f/l/s/w/q) and data.\n");
								memset(string, 0 , sizeof(string));


						}
						else if( command == 'd' )
						{
							ptr = tmp;
							
							while( *ptr != '\n' )
							{
								if( *ptr == ',' )
										break;
								else
										ptr++;
							}
							while( *ptr != '\n' )
							{
								if(isdigit(*ptr)||isalpha(*ptr))
										break;
								else
										ptr++;
							}
							if( *ptr == '\n' )
							{
									printf("Please input command(i/d/u/f/l/s/w/q) and data.\n");
									break;
							}
							ptr1 = ptr;

							while( *ptr1 != '\n' )
							{
								if(isspace(*ptr1))
										 break;
								else
										 ptr1++;
							}
					

							i = 0;
							while( *ptr != *ptr1 )
							{
								idtmp[i++] = *ptr;			//insert ID
								ptr++;
							}
						
							light = OFF;
							for( i = 0; i < len; i++ )
							{
								if( strcmp ( addrbook[i].id , idtmp ) == 0 )
								{	
									search = i;
									light = ON;
									break;
								}
							}
							if( light == OFF )
							{
								printf("Delete error! studentID not exists !\n");
								printf("Please input command(i/d/u/f/l/s/w/q) and data.\n");
								break;
							}
							printf( "%s,%s,%s,%d\n",addrbook[search].id,addrbook[search].name,addrbook[search].phone,addrbook[search].age );

							for( i = search; i < len; i++ )
							{
								strcpy( addrbook[i].id , addrbook[i+1].id );
								strcpy( addrbook[i].name , addrbook[i+1].name );
								strcpy( addrbook[i].phone , addrbook[i+1].phone );
								addrbook[i].age = addrbook[i+1].age;
							}
							len = len-1;
							memset( idtmp , 0 ,sizeof(idtmp) );
							printf("Please input command(i/d/u/f/l/s/w/q) and data.\n");
						}
						else if( command == 'w' )
						{
							FILE *pfile;

							ptr = tmp;
							while( *ptr != '\n' )
							{
								if( *ptr == ',' )
										break;
								else
										ptr++;
							}

							while( *ptr != '\n' )
							{	
								if(	(isalpha(*ptr)) || (isdigit(*ptr)) )
										break;
								else
										ptr++;
							}
							if( *ptr == '\n' )
							{
									printf("Please input command(i/d/u/f/l/s/w/q) and data.\n");
									break;
							}
							i = 0;
							while( *ptr != '\n' )
							{
								string[i++] = *ptr;				
								ptr++;							//insert file name
							}
							pfile = fopen( string , "w" );
							
							for( i = 0; i < len; i++ )
							{
								fprintf( pfile , "%s,%s,%s,%d\n",addrbook[i].id,addrbook[i].name,addrbook[i].phone,addrbook[i].age );
							}
							if( pfile != NULL)
							{
								printf("Writing file successful !\n");	
							}
							fclose(pfile);
							memset( string , 0 , sizeof(string) );
							printf("Please input command(i/d/u/f/l/s/w/q) and data.\n");
						}	
						else if( command == 's' )
						{
								ptr = tmp;

							while( *ptr != '\n' )
							{
								if( *ptr == ',' )
										break;
								else
										ptr++;
							}

							while( *ptr != '\n' )
							{	
								if(	isalpha(*ptr) )
										break;
								else
										ptr++;
							}
							i = 0;
							if( *ptr == '\n' )
							{
									printf("Please input command(i/d/u/f/l/s/w/q) and data.\n");
									break;
							}
							while( *ptr != '\n' )
							{
								string[i++] = *ptr;	
								ptr++;							//insert sort format
							}
							if( strcmp( string , "studentID" ) == 0 )
							{
							    sort_id( addrbook , len );
							}
							
							if( strcmp( string , "name" ) == 0 )
							{
								sort_name( addrbook , len );
							}

							if( strcmp( string , "phone" ) == 0 )
							{
								sort_phone( addrbook , len );
							}

							if( strcmp( string , "age" ) == 0 )
							{
								sort_age( addrbook , len );
							}
							
							printf("Please input command(i/d/u/f/l/s/w/q) and data.\n");

							memset( string , 0 , sizeof (string) );
						}
						else if( command == 'u' )
						{
								while( *ptr != '\n' )
								{
									if( *ptr == ',' )
											break;
									else
											ptr++;
								}
								while( *ptr != '\n' )
								{
										if(isdigit(*ptr)||isalpha(*ptr))
												break;
										else
												ptr++;
								}
								ptr1 = ptr;
								if( *ptr == '\n' )
								{
									printf("Please input command(i/d/u/f/l/s/w/q) and data.\n");
									break;
								}
								while( *ptr1 != '\n' )
								{
										if(isspace(*ptr1) || *ptr1 == ',' )
												break;
										else
												ptr1++;
								}
								if( *ptr1 == '\n' )
								{
									printf("Please input command(i/d/u/f/l/s/w/q) and data.\n");
									break;
								}
								i = 0;
								while( *ptr != *ptr1 )
								{
										idold[i++] = *ptr; 			//insert old student ID
										ptr++;
								}
								
								light = OFF;
								for( i = 0; i < len ; i++ )
								{
										if(strcmp(addrbook[i].id , idold) == 0 )
										{	
												search = i;
												light = ON;
												break;
										}
								}
										
												if( light == OFF )	
												{
														printf("OLD ID DOES NOT EXIST\n");
														break;
												}	
												while( *ptr != '\n' )
												{
														if( isdigit(*ptr) || isalpha(*ptr))
																break;
														else
																ptr++;
												}
												if( *ptr == '\n' )
												{
													printf("Please input command(i/d/u/f/l/s/w/q) and data.\n");
													break;
												}
												ptr1 = ptr;
												while( *ptr1 != '\n' )
												{
														if( isspace(*ptr1) || *ptr1 == ',')
																break;
														else
																ptr1++;
												}
												if( *ptr1 == '\n' )
												{
													printf("Please input command(i/d/u/f/l/s/w/q) and data.\n");
													break;
												}
												i = 0;
												while( *ptr != *ptr1 )
												{
														idnew[i++] = *ptr;			//insert new student ID	
														ptr++;
												}
												
												while( *ptr != '\n' )
												{
														if(isalpha(*ptr))
																break;
														else
																ptr++;
												}
												ptr1 = ptr;
												if( *ptr == '\n' )
												{
													printf("Please input command(i/d/u/f/l/s/w/q) and data.\n");
													break;
												}
												while( *ptr1 != '\n' )
												{
														if( (isspace(*ptr1)) || *ptr1 == ',' )
																break;
														else
																ptr1++;
												}
												if( *ptr1 == '\n' )
												{
													printf("Please input command(i/d/u/f/l/s/w/q) and data.\n");
													break;
												}
												i = 0;
												while( *ptr != *ptr1 )
												{
														nametmp[i++] = *ptr;		//insert name
														ptr++;
												}
												while( *ptr != '\n' )
												{
														if(isdigit(*ptr))
																break;
														else
																ptr++;
												}
												if( *ptr == '\n' )
												{
													printf("Please input command(i/d/u/f/l/s/w/q) and data.\n");
													break;
												}
												ptr1 = ptr;
												while( *ptr1 != '\n' )
												{
														if( isspace(*ptr1) || *ptr1 == ',' )
																break;
														else
																ptr1++;
												}
												if( *ptr1 == '\n' )
												{
													printf("Please input command(i/d/u/f/l/s/w/q) and data.\n");
													break;
												}	
												i = 0;
												while( ptr != ptr1 )
												{
														phonetmp[i++] = *ptr;		//insert phone number
														ptr++;
												}
												while( *ptr != '\n' )
												{
														if(isdigit(*ptr))
																break;
														else
																ptr++;
												}

												agetmp = atoi(ptr);				//insert age
												
												memset( addrbook[search].id , 0 , sizeof( addrbook[search].id ) );
												memset( addrbook[search].name , 0 , sizeof( addrbook[search].name ) );
												memset( addrbook[search].phone , 0 , sizeof( addrbook[search].phone ) );
												

												strcpy( addrbook[search].id , idnew );
												strcpy( addrbook[search].name , nametmp );
												strcpy( addrbook[search].phone , phonetmp );
												addrbook[search].age = agetmp;
												

												update( addrbook , search );	
												printf("Please input command(i/d/u/f/l/s/w/q) and data.\n");

												memset( idnew, 0 , sizeof( idnew ) );
												memset( idold, 0 , sizeof( idold ) );
												memset( nametmp, 0 , sizeof( nametmp ) );
												memset( phonetmp, 0 , sizeof( phonetmp ) );
												agetmp = 0;
										}
										else
										{
											printf("Please input command(i/d/u/f/l/s/w/q) and data.\n");	
											break;
										}
										break;
								}
								memset(tmp ,0 , sizeof(tmp));
						}
						return 0;
				}

void insert( addr *addrbook , int len )
{
		printf( "%s,%s,%s,%d\n",addrbook[len].id,addrbook[len].name,addrbook[len].phone,addrbook[len].age );

		printf("Please input command(i/d/u/f/l/s/w/q) and data.\n");
}

void list( addr *addrbook , int len )
{
		int i;

		for( i = 0; i < len; i++ )
		{
			printf( "%s,%s,%s,%d\n",addrbook[i].id,addrbook[i].name,addrbook[i].phone,addrbook[i].age );

		}	
			printf("Please input command(i/d/u/f/l/s/w/q) and data.\n");
}

void find( addr *addrbook , int len )
{
	printf( "%s,%s,%s,%d\n",addrbook[len].id,addrbook[len].name,addrbook[len].phone,addrbook[len].age );
}

void update( addr *addrbook , int search )
{
	printf( "%s,%s,%s,%d\n",addrbook[search].id,addrbook[search].name,addrbook[search].phone,addrbook[search].age ); 			
}

void sort_id( addr *addrbook , int len )
{
	int agetmp , i , j;
	char idtmp[20] = {0} , nametmp[20] = {0} , phonetmp[20] = {0};	
	for( i=1 ; i<len ; i++ )
	{
	     agetmp = addrbook[i].age;
	     strcpy( idtmp , addrbook[i].id );
	     strcpy( nametmp , addrbook[i].name );
	     strcpy( phonetmp , addrbook[i].phone );

	        j = i-1 ;
	     	while( (strcmp( idtmp , addrbook[j].id) < 0 ) && ( j >= 0 ) )
	        {
	 	        addrbook[j+1].age = addrbook[j].age;
			    strcpy( addrbook[j+1].id , addrbook[j].id );
			    strcpy( addrbook[j+1].name , addrbook[j].name );	
			    strcpy( addrbook[j+1].phone , addrbook[j].phone );
		        j = j-1;
		    }
		        addrbook[j+1].age = agetmp;
		        strcpy( addrbook[j+1].id , idtmp );
				strcpy( addrbook[j+1].name , nametmp );
			    strcpy( addrbook[j+1].phone , phonetmp );
				
	}

	for( i = 0; i < len; i++ )
	{
		printf( "%s,%s,%s,%d\n",addrbook[i].id,addrbook[i].name,addrbook[i].phone,addrbook[i].age ); 			
	}
}
void sort_name( addr *addrbook , int len )
{
	int agetmp , i , j;
	char idtmp[20] = {0} , nametmp[20] = {0} , phonetmp[20] = {0};	
	for( i=1 ; i<len ; i++ )
	{
	     agetmp = addrbook[i].age;
	     strcpy( idtmp , addrbook[i].id );
	     strcpy( nametmp , addrbook[i].name );
	     strcpy( phonetmp , addrbook[i].phone );

	        j = i-1 ;
	     	while( (strcmp( nametmp , addrbook[j].name ) < 0) && ( j >= 0 ) )
	        {
	 	        addrbook[j+1].age = addrbook[j].age;
			    strcpy( addrbook[j+1].id , addrbook[j].id );
			    strcpy( addrbook[j+1].name , addrbook[j].name );	
			    strcpy( addrbook[j+1].phone , addrbook[j].phone );
		        j = j-1;
		    }
		        addrbook[j+1].age = agetmp;
		        strcpy( addrbook[j+1].id , idtmp );
				strcpy( addrbook[j+1].name , nametmp );
			    strcpy( addrbook[j+1].phone , phonetmp );
				
	}

	for( i = 0; i < len; i++ )
	{
		printf( "%s,%s,%s,%d\n",addrbook[i].id,addrbook[i].name,addrbook[i].phone,addrbook[i].age ); 			
	}
}
void sort_phone( addr *addrbook , int len )
{
	int agetmp , i , j;
	char idtmp[20] = {0} , nametmp[20] = {0} , phonetmp[20] = {0};	
	for( i=1 ; i<len ; i++ )
	{
	     agetmp = addrbook[i].age;
	     strcpy( idtmp , addrbook[i].id );
	     strcpy( nametmp , addrbook[i].name );
	     strcpy( phonetmp , addrbook[i].phone );

	        j = i-1 ;
	     	while( ( atoi(phonetmp) < atoi(addrbook[j].phone) ) && ( j >= 0 ) )
	        {
	 	        addrbook[j+1].age = addrbook[j].age;
			    strcpy( addrbook[j+1].id , addrbook[j].id );
			    strcpy( addrbook[j+1].name , addrbook[j].name );	
			    strcpy( addrbook[j+1].phone , addrbook[j].phone );
		        j = j-1;
		    }
		        addrbook[j+1].age = agetmp;
		        strcpy( addrbook[j+1].id , idtmp );
				strcpy( addrbook[j+1].name , nametmp );
			    strcpy( addrbook[j+1].phone , phonetmp );
				
	}

	for( i = 0; i < len; i++ )
	{
		printf( "%s,%s,%s,%d\n",addrbook[i].id,addrbook[i].name,addrbook[i].phone,addrbook[i].age ); 			
	}
}
void sort_age( addr *addrbook , int len )
{
	int agetmp , i , j;
	char idtmp[20] = {0} , nametmp[20] = {0} , phonetmp[20] = {0};	
	for( i=1 ; i<len ; i++ )
	{
	     agetmp = addrbook[i].age;
	     strcpy( idtmp , addrbook[i].id );
	     strcpy( nametmp , addrbook[i].name );
	     strcpy( phonetmp , addrbook[i].phone );

	        j = i-1 ;
	     	while( ( agetmp < addrbook[j].age ) && ( j >= 0 ) )
	        {
	 	        addrbook[j+1].age = addrbook[j].age;
			    strcpy( addrbook[j+1].id , addrbook[j].id );
			    strcpy( addrbook[j+1].name , addrbook[j].name );	
			    strcpy( addrbook[j+1].phone , addrbook[j].phone );
		        j = j-1;
		    }
		        addrbook[j+1].age = agetmp;
		        strcpy( addrbook[j+1].id , idtmp );
				strcpy( addrbook[j+1].name , nametmp );
			    strcpy( addrbook[j+1].phone , phonetmp );
				
	}

	for( i = 0; i < len; i++ )
	{
		printf( "%s,%s,%s,%d\n",addrbook[i].id,addrbook[i].name,addrbook[i].phone,addrbook[i].age ); 			
	}
}	


