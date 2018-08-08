Chapter 2
================
Abhishek Nandy

Insertion sort
--------------

The insertion sort algorithm along with the pseudo code is provided in Section 2.1 of the book. We provide a function in C to implement an insertion sort and execute it to sort a randomly generated array of integers. To keep things simple we limit our computations to integers.

Merge sort
----------

``` rcpp
#include <stdio.h>

#define LARGE 10000000

 

#define ARRAY_LEN 20

 

void merge_fn( int* A, int p, int q, int r );

void merge_sort( int *A, int p, int r );

 

void main(){

int i;

int A[11] = {4, 5, 6, 1, 2, 3, 9, 8, 15, 13, 14};

for( i = 0; i < 11; ++i)

                printf("%d ", *(A + i));

                printf("\n");

merge_sort( A, 0, 10);

for( i = 0; i < 11; ++i)

                printf("%d ", *(A + i));

                printf("\n");

 

}

 

void merge_fn( int* A, int p, int q, int r ){

               

                int L[ q - p  + 2], R[ r - q +1];

                int i = 0, j = 0, k = 0;

 

                for( i = 0; i < (q - p +1); ++i ){

                                *( L + i ) = *( A + p + i );

                                }

                for( i = 0; i < (r - q ); ++i ){

                                *( R + i ) = *( A + q + 1 + i );

                                }

                *( L + q - p + 1 ) = *( R + r - q ) = LARGE;

                for( i = p; i <= r; ++i ){

                               

                                if( *( L + j ) < *( R + k ) ){

                                                *( A + i ) = *( L + j );

                                                ++j;

                                                }

                                else{

                                                *( A + i ) = *( R + k );

                                                ++k;

                                                }

                                               

                                }

 

}

 

void merge_sort( int* A, int p, int r ){

                int q;

                if( p < r ){

                q = (p + r)/2;

                merge_sort( A, p, q);

                merge_sort( A, q+1, r);

                merge_fn( A, p, q, r);

                }

}
```
