#include <stdio.h>
#include <AGGREGATE.H>


int main()
{
    //Question1
    printf("----------------------------------------------------------\n");
    printf("\t\tOutput for the Question 3\n");
    printf("----------------------------------------------------------\n");
    float data[] = {112.2, 202.3, 98.3, 99.5, 87.2, 66.3, 581.15, 31.32, 53.36, 95.36};
    printf("Minimum number in the array is : %-10f\n", min(data, sizeof(data)/sizeof(data[0])));
    printf("Maximum number present in an array is : %-10f\n", max(data, sizeof(data)/sizeof(data[0])));
    float myFloat = 2.1234;
    float *pf = &myFloat;
    printf("my pointer: %f\n", *pf);
    printf("Value printed by using pointer method is %f\n", *maxPointer(data,sizeof(data)/sizeof(data[0])));
    printf("Sum of the array is given by: %f\n", sum(data, sizeof(data)/sizeof(data[0])));
    printf("Average of an array is given by: %f\n", avg(data, sizeof(data)/sizeof(data[0])));
      // Question 2
    printf("\n\n----------------------------------------------------------\n");
    printf("\t\tOutput for the Question 4\n");
    printf("----------------------------------------------------------\n");
    float (*pmin)(float[], int) = &min;
    float (*pmax)(float[], int) = &max;
    float (*psum)(float[], int) = &sum;
    float (*pavg)(float[], int) = &avg;
    float (*ppseudo_avg)(float[], int) = &pseudo_avg;
    float (*aggregates[])(float[], int) = {pmin, pmax, psum, pavg, ppseudo_avg};
    float data5elements[] = {63.4, 86.65, 25.66, 75.31, 96.65};
    float data10elements[] = {44.12, 96.63, 75.61, 25.36, 75.12, 63.4, 86.65, 25.66, 75.31, 96.65};
    printf("\t\tOutput of an array with 5 elements\n");
    for(int i=0; i<5; i++){
        printf("Function %d: %7f\n",i+1,(*aggregates[i])(data5elements, 5));
    }
    printf("\t\tOutput of an array with 10 elements\n");
    for(int i=0; i<5; i++){
       printf("Function %d: %7f\n",i+1, (*aggregates[i])(data10elements, 5));
    }

    printf("\n\n----------------------------------------------------------\n");
    printf("\t\tOutput for the Question 5 \n");
    printf("----------------------------------------------------------\n");
    typedef float (*funcptr[5])(float data[], int size);


    const char * funcnames[] = {"FMIN", "FMAX", "FSUM", "FAVG", "FPSEUDO_AVG"};














}
