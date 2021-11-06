#include<stdio.h>

int main()
{

    int no,i,flag,limit,count;  

    printf("\n\n\t Enter Number : ");
    scanf("%d",&limit);

    count=0;

    printf("\n\n==============================================\n\n");

    for(no=1;no<=limit;no++)
    {
        flag=1;

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
            continue;
        }
        if(flag==1)
        {
            count++;
            printf("\t %d ",no);
        }

    }

    printf("\n\n\t Total Number Of Prime Number is : %d \n\n",count);
    return 0;
}