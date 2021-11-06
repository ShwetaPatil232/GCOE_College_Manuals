#include<stdio.h>

int main()
{

    int no,i,flag;

    flag=1;

    printf("\n\n\t Enter Number : ");
    scanf("%d",&no);

    for(i=2;i<no;i++)
    {
        if((no%i)==0)
        {
            flag=0;
            break;
        }
    }

    if(no==1)
    {
        printf("1 is Not Prime & Not Composite.\n\n");
    }
    else if(flag==1)
    {
        printf("\n\n\t Entered Number %d is Prime Number. \n\n",no);
    }
    else
    {
        printf("\n\n\t Entered Number %d is Not Prime Number. \n\n",no);
    }

    return 0;
}