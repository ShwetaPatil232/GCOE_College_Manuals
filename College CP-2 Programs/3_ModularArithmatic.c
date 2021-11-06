#include <stdio.h>

int main() 
{

    /* Simple Logic for me 
                    
                     QUOTIENT
                     _________
            divisor ) divident
            ___________________________

                     REMINDER  
    */

    int dividend, divisor, quotient, remainder;

    printf("\n\n\t Enter dividend : ");
    scanf("%d", &dividend);

    printf("\n\t Enter divisor : ");
    scanf("%d", &divisor);

   
    quotient = dividend / divisor;
    remainder = dividend % divisor;

    printf("\n\n===========================================\n\n");

    printf("\t Quotient = %d \n", quotient);
    printf("\n\t Remainder = %d \n\n", remainder);

    
    return 0;
}