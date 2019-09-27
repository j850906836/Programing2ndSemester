#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define SIZE (1<<32)

void mode_bubble ( int [] , int [] , int );
void mode_insertion ( int [] , int [] , int );
void mode_selection ( int [] , int[] , int );
int mycompare ( const void *x , const void *y );
int main()
{
	int i , j = 0 , len = 1000;
	int *array = {0};
	int *arrayold = {0};
	clock_t start_t1 , start_t2 , end_t1 , end_t2;
	double total_t1 , total_t2 , qsort_t[10] = {0} , merge_t[10] = {0};

	while( len < 1000001 )
	{
		
		for( len = 1000; len < 100001; len = len*10 )
		{
		
		array = ( int * ) malloc (sizeof (int) * len );
		arrayold = ( int * ) malloc (sizeof (int) * len );

			srand(1);
			for( i = 0 ; i < len ; i++ )
			{
			array[i] = rand();
			}
			srand(1);
			for( i = 0 ; i < len ; i++ )
			{
			arrayold[i] = rand();
			}
			mode_insertion( array , arrayold , len );
		}
		for( len = 1000; len < 100001; len = len*10 )
		{
		
		array = ( int * ) malloc (sizeof (int) * len );
		arrayold = ( int * ) malloc (sizeof (int) * len );

			srand(1);
			for( i = 0 ; i < len ; i++ )
			{
			array[i] = rand();
			}
			srand(1);
			for( i = 0 ; i < len ; i++ )
			{
			arrayold[i] = rand();
			}

			mode_bubble( array , arrayold , len ) ;
		}
		for( len = 1000; len < 100001; len = len*10 )
		{
		
		array = ( int * ) malloc (sizeof (int) * len );
		arrayold = ( int * ) malloc (sizeof (int) * len );

			srand(1);
			for( i = 0 ; i < len ; i++ )
			{
			array[i] = rand();
			}
			srand(1);
			for( i = 0 ; i < len ; i++ )
			{
			arrayold[i] = rand();
			}
			mode_selection( array , arrayold , len ) ;

		}
	
		
		for( len = 1000; len < 1000001; len = len*10 ) 
		{
			
			array = ( int * ) malloc (sizeof (int) * len );
			arrayold = ( int * ) malloc (sizeof (int) * len );
			
			
			srand(1);
			for( i = 0; i < len; i++ )
			{
			array[i] = rand();
			}
			srand(1);
			for( i = 0; i < len; i++ )
			{
			arrayold[i] = rand();
			}

			start_t1 = clock();
			
			qsort( array ,len , sizeof(array[0]) , mycompare );
			
			end_t1 = clock();
			total_t1 = (end_t1 - start_t1)/(double)CLOCKS_PER_SEC; 
			
			qsort_t[j] = total_t1;
			printf("n = %d\n",len);
			printf("Quick Sort\n");
			printf("Before\t\tAfter\n");
			
			for( i=0; i<10; i++ )
			{
				printf( "%-12d\t%-12d\n" , arrayold[i] , array[i] );
			}
			printf("CPU TIME by %lf\n" , qsort_t[j] );
			j++;
		}
		for( len = 1000; len < 1000001; len = len*10 )
		{
			array = ( int * ) malloc (sizeof (int) * len );
			arrayold = ( int * ) malloc (sizeof (int) * len );

			srand(2);
			for( i = 0; i < len; i++ )
			{
			array[i] = rand();
			}
			srand(2);
			for( i = 0; i < len; i++ )
			{
			arrayold[i] = rand();
			}

			start_t2 = clock();
			
			mergesort( array ,len , sizeof(array[0]) , mycompare );
			end_t2 = clock();
						
			total_t2 =(end_t2 - start_t2)/(double)CLOCKS_PER_SEC;
		
			merge_t[j] = total_t2;
			printf("n = %d\n",len);	
			printf("Merge Sort\n");
			printf("Before\t\tAfter\n");
			for( i=0; i<10; i++ )
			{
				printf( "%-12d\t%-12d\n" , arrayold[i] , array[i] );
			}
			
			
			printf("CPU TIME by merge:%lf\n", merge_t[j]);
			j++;
		}
	break;
	}
	
			
		
		return 0;
}

void mode_bubble( int array[] , int arrayold[] , int len )
{
	int i ,j , k , temp;
	clock_t start_t , end_t;
	double total_t;

	start_t = clock();
    if( len < 5000 )
	{
		for( k = 0 ; k < 100 ; k++ )
		{
		for( i=0; i<len-1;i++ )
		{
			for(j=0; j<len-i-1; j++ )
			{
				if( array[j]>array[j+1]	)
				{
					temp = array[j+1];
					array[j+1] = array[j];
					array[j] = temp;
				}
			}
		}
		}

	end_t = clock();
	total_t = (( end_t - start_t )/100.0)/(double)CLOCKS_PER_SEC;
	}
	else
	{
		for( i=0; i<len-1;i++ )
		{
			for(j=0; j<len-i-1; j++ )
			{
				if( array[j]>array[j+1]	)
				{
					temp = array[j+1];
					array[j+1] = array[j];
					array[j] = temp;
				}
			}
		}

	end_t = clock();
	total_t = ( end_t - start_t )/(double)CLOCKS_PER_SEC;
	}
	
	printf("n = %d\n",len);
	printf("Bubble Sort\n");
	printf("Before\t\tAfter\n");
	for( i=0; i<10; i++ )
	{
			printf("%-12d\t%-12d\n" , arrayold[i] , array[i] );
	}
	printf( "CPU TIME:%lf\n" , total_t );

}

void mode_insertion( int array[] , int arrayold[] , int len )
{
	int i , j , k , temp;
	clock_t start_t , end_t;
	double total_t;
	start_t = clock();
	if( len < 5000 )
	{
	for(k=0 ; k<100 ;k++)
	{
		for( i=1 ; i<len ; i++ )
		{
	     	temp = array[i] ;
	        j = i-1 ;
	     	while( ( temp<array[j]) && (j>=0) )
	        {
	 	        array[j+1] = array[j];
		        j = j-1;
		    }
		        array[j+1] = temp;
		}
	}
	end_t = clock();
	total_t = (double)(( end_t - start_t )/100.0)/CLOCKS_PER_SEC; 
	}
	
	else
	{
		for( i=1 ; i<len ; i++ )
		{
	     	temp = array[i] ;
	        j = i-1 ;
	     	while( ( temp<array[j]) && (j>=0) )
	        {
	 	        array[j+1] = array[j];
		        j = j-1;
		    }
		        array[j+1] = temp;
		}
		end_t = clock();
		total_t =(double)( end_t - start_t )/CLOCKS_PER_SEC;
	
	}
	printf("n = %d\n",len);
	printf("Insertion Sort\n");
	printf("Before\t\tAfter\n");
		for(i=0;i<10;i++)
	{
		printf( "%-12d\t%-12d\n" , arrayold[i] , array[i] ) ;	
	}
	printf( "CPU TIME:%lf\n",total_t );
}

void mode_selection( int array[] , int arrayold[] , int len )
{
	int i , j , k ,m , temp ;
	clock_t start_t , end_t;
	double total_t;
	start_t = clock();
    if( len < 5000 )
	{
    for( k=0 ; k<100 ; k++ )
	{
		for( i = 0 ; i < len ; i++ )
		{
			m=i;

			for( j=i+1; j <= len; j++ )
			{
				if ( array[j] < array[m] )
				{		
					m = j;
				}
			}

				temp = array[i];
				array[i] = array[m];
				array[m] = temp;
		}

	}
	end_t = clock();
	total_t = ((end_t - start_t )/100.0)/(double)CLOCKS_PER_SEC;
	}	
	else
	{
		for( i = 0 ; i < len ; i++ )
		{
	
			m = i;

			for( j=i+1; j <= len; j++ )
			{
				if( array[j] < array[m] )
				{
					m = j;
				}
			}
				temp = array[i];
				array[i] = array[m];
				array[m] = temp;

		}
		end_t = clock();
		total_t = (end_t - start_t )/(double)CLOCKS_PER_SEC;
	}
	printf("n = %d\n",len);
	printf("Selection Sort\n");
	printf("Before\t\tAfter\n");

	for ( i=0; i < 10; i++ )
	{
		printf( "%-12d\t%-12d\n", arrayold[i] , array[i] );
	}
	printf("CPU TIME:%lf\n",total_t);
}


int mycompare( const void *x ,const void *y )
{
	return *(int *)x - *(int *)y ;
}
