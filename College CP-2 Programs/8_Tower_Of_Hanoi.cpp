#include <stdio.h>

void towers(int, char, char, char);
int main()
{
    int num;
    printf("\n\n\t Enter the number of disks : ");
    scanf("%d", &num);
    printf("\n\n=============================================================\n");
    printf("\n\t The sequence of moves involved in the Tower of Hanoi are :\n\n");
    towers(num, 'A', 'C', 'B');
    
    printf("\n\n");
    return 0;
}
void towers(int num, char A, char B, char C)
{
    if (num == 1)
    {
        printf("\n Move disk 1 from Rod %c to Rod %c", A, B);
        return;
    }
    towers(num - 1, A, C, B);
    printf("\n Move disk %d from Rod %c to Rod %c", num, A, B);
    towers(num - 1, C, B, A);
}