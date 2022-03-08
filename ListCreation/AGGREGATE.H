
#include <stdlib.h>

/*********************************************************
This method returns the minimum float present in the array.
**********************************************************/
float min(float data[], int n){
    if((data == NULL) | (n < 0)){
        printf("FATAL ERROR");
        abort();
    }
    float min = data[0];
    for(int i=0; i<n; i++){
        if(data[i] < min){
            min = data[i];
        }
    }
    return min;
}

/*********************************************************
This method returns the maximum float present in the array.
**********************************************************/
float max(float data[], int n){
    if((data == NULL) | (n < 0)){
        printf("FATAL ERROR");
        abort();
    }
    float max = data[0];
    for(int i=0; i<n; i++){
        if(data[i] > max){
            max = data[i];
        }
    }
    return max;
}

/*********************************************************
This method returns the maximum float present in the array,
using pointers.
**********************************************************/
float* maxPointer(float data[], int n){
    if((data == NULL) | (n < 0)){
        printf("FATAL ERROR");
        abort();
    }
    float *pmax = &data[0];
    for(int i=0; i<n; i++){
         if(data[i] > *pmax){
            pmax = &data[i];
        }
    }
    return pmax;
}

/*********************************************************
This method returns the sum of elements in the given array.
**********************************************************/
float sum(float data[], int n){
    if((data == NULL) | (n < 0)){
        printf("FATAL ERROR");
        abort();
    }
    float totalSum = 0.0;
    for(int i=0; i<n; i++){
        totalSum = totalSum + data[i];
    }
    return totalSum;
}

/************************************************************
This method returns the average of elements in a given array.
************************************************************/
float avg(float data[], int n){
    if((data == NULL) | (n < 0)){
        printf("FATAL ERROR");
        abort();
    }
    float totalSum = 0.0;
    for(int i=0; i<n; i++){
        totalSum = totalSum + data[i];
    }
    return totalSum/n;
}

/************************************************************

************************************************************/
float pseudo_avg(float data[], int n){
    if((data == NULL) | (n < 0)){
        printf("FATAL ERROR");
        abort();
    }
    float pavg = (min(data, n) + max(data, n))/2;
    return pavg;
}
















