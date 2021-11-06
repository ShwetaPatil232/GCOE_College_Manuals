#include<stdio.h>
#include<math.h>

int main()
{
	int  x,y,z,c1,c2,x1,y1,z1;
	float result=0;

	/*			Approach 1 According to Formula  x^2 + y^2 = z^2
		2) Find Y^2 =

			We have given any two values ------->: then ------->: we have to find 3rd value 
	*/
	printf("\n\n\t *****   Diophantine equation ******  \n");
	printf("\n\t 1) X ");
	printf("\n\t 2) Y ");
	printf("\n\t 3) Z ");
	printf("\n\n==========================================");
	printf("\n\n\t Which 1st Variable Value You Want To Enter (Choose From Above Menu : 1 , 2 or 3: ");
	scanf("%d",&c1);
    printf("\n\n\t Which 2nd Variable Value You Want To Enter (Choose From Above Menu : 1 , 2 or 3: ");
	scanf("%d",&c2);

	if(c1==1 && c2==2)
	{
		printf("\n\n\t Enter Values For X : ");
		scanf("%d",&x);
		printf("\n\t  Enter Values For Y : ");
		scanf("%d",&y);
		/*Here We Find Value Of Z */
		x1=x*x;
		y1=y*y;
		result=sqrt(abs(x1+y1));
		printf("\n\n\t Value Of Z is : %f \n\n",result);
	}
	else if(c1==2 && c2==3)
	{
		printf("\n\n\t Enter Values For Y : ");
		scanf("%d",&y);
		printf("\n\t  Enter Values For Z : ");
		scanf("%d",&z);
		/*Here We Find Value Of X */
		z1=z*z;
		y1=y*y;
		result=sqrt(abs(z1-y1));
		printf("\n\n\t Value Of X is : %f \n\n",result);
	}

	else if(c1==1 && c2==3)
	{
		printf("\n\n\t Enter Values For X : ");
		scanf("%d",&x);
		printf("\n\t  Enter Values For Z : ");
		scanf("%d",&z);	
		/*Here We Find Value Of Y */
		z1=z*z;
		x1=x*x;
		result=sqrt(abs(z1-x1));
		printf("\n\n\t Value Of Y is : %f \n\n",result);
	}
	else
	{
		printf("\n\n\t Sorry You Are Entered Wrong Choice !!!  \n\n\t Try Again. \n\n");
	}


	return 0;

}
