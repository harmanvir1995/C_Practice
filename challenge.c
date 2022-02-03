#include <stdio.h>
#include <stddef.h>

int tax();
int gcd(int x, int y);


int main(){
    int result = gcd(30, 100);
    printf("The greatest common factor is :%d\n", result);
    int number = 9976;
    int *pNumber = &number;
    printf("Value of the number is given by: %d\n", number);
    printf("Address of the number variable is given by: %p\n", &number);
    printf("Value of the pointer is: %p\n", pNumber);
    printf("Address of the variable pointer is: %p\n", &pNumber);
    return 0;
}

int gcd(int x, int y){
    int divisor;
    int result = 1;
    if(x>y){
        divisor = y;
    }
    else{
        divisor = x;
    }
    for(int i=1; i<divisor; i++){
        if(x%i == 0 && y%i == 0){
            result = i;
        }
    }
    return result;
}

int tax(){
    int numberOfHours;
    int overTimeHours =0;
    printf("Enter the number of hours you worked: ");
    scanf("%d", &numberOfHours);
    const float basicPayRate = 12.00;
    const float overTimePayRate = 18.00;
    float totalPay = 0.0;
    if(numberOfHours < 40){
        totalPay = numberOfHours * basicPayRate;
    }
    else if(numberOfHours > 40){
        totalPay = 40*basicPayRate;
        overTimeHours = numberOfHours - 40;
        totalPay = totalPay + (overTimeHours * overTimePayRate);
    }

    float taxBracket1 = 0.0, taxBracket2 = 0.0, taxBracket3 = 0.0 ;
    if(totalPay < 300){
        taxBracket1 = (15.0/100.0) * totalPay;
        printf("brac 1 : %d\n", taxBracket1);
    }
    else if(totalPay > 300 && totalPay < 450){
        taxBracket1 = (15.0/100.0) * 300.0;
        taxBracket2 = (20.0/100.0) * (totalPay-300);
    }
    else if(totalPay > 450){
         taxBracket1 = (15.0/100.0) * 300.0;
        taxBracket2 = (20.0/100.0) * 150.0;
        taxBracket3 = (25.0/100.0) * (totalPay-450);
    }
    float totalTaxes = taxBracket1 + taxBracket2 + taxBracket3;
    float netPay = totalPay - totalTaxes;
    printf("Total pay without taxes is: %.2f\n", totalPay);
    printf("Total taxes: %.2f\n", totalTaxes);
    printf("Your net pay is: %.2f\n", netPay);
}
