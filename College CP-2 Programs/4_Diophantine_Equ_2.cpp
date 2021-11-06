/* 				
						Logic

Linear Diophantine Equations : ax + by = c. Determine if the equation has a solution 
such that x and y are both integral values.

Solution Approach:

1) Find GCD of a and b
2) Check if c % GCD(a ,b) ==0
3) If yes then print Possible
4) Else print Not Possible

*/
#include<stdio.h>
#include<math.h>

using namespace std;
 
int gcd(int a, int b)
{
	int gcd,i;
	gcd=0;
	for(i=1; i <= a && i <= b; ++i)
    {

        if(a%i==0 && b%i==0)
            gcd = i;
    }

    return gcd;
    //return (a%b == 0)? abs(b) : gcd(b,a%b);
}
 

bool isPossible(int a, int b, int c)
{
    return (c%gcd(a,b) == 0);
}
 
int main()
{
	int a,b,c;

	printf("\n\n\t Enter The Value For A : ");
	scanf("%d",&a);
	printf("\n\n\t Enter The Value For B : ");
	scanf("%d",&b);
	printf("\n\n\t Enter The Value For C : ");
	scanf("%d",&c);

	printf("\n\n=============================================\n\n");

	if(isPossible(a,b,c))
	{
		printf("\n\n\t Diophantine equation Solution is Possible. \n\n");
	}
	else
	{
		printf("\n\n\t Diophantine equation Solution is Not Possible. \n\n");
	}
  
 
    return 0;
}