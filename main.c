#include <stdio.h>
#include <stdlib.h>

int main()
{
   enum company{GOOGLE, FACEBOOK, XEROX, YAHOO, EBAY, MICROSOFT};
   enum company company_1 = XEROX;
   enum company company_2 = GOOGLE;
   enum company company_3 = EBAY;
   printf("%d\n", company_3);

   int numberToTest, remainder;
   printf("Enter the number you want to test: ");
   scanf("%d", &numberToTest);
   remainder = numberToTest%2;
   if(remainder == 0){
    printf("Number You entered is even: %d\n", numberToTest);
   }
   else{
    printf("Number you entered is odd: %d\n", numberToTest);
   }

   enum weekdays{Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday};
   enum weekdays today = Sunday;
   switch(today){
    case Monday:
        printf("Today is Monday.\n");
        break;
    case Tuesday:
        printf("Today is Tuesday.\n");
        break;
    case Wednesday:
        printf("Today is Wednesday.\n");
        break;
    case Thursday:
        printf("Today is Thursday.\n");
        break;
    case Friday:
        printf("Today is Friday.\n");
        break;
    case Saturday:
        printf("Today is Saturday.\n");
        break;
    case Sunday:
        printf("Today is Sunday.\n");
        break;
    default:
        printf("Nothing entered..!!");
   }

   return 0;
}
