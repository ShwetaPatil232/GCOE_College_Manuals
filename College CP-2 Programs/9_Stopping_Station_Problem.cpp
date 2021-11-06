#include<stdio.h>
int main(){
   int n = 16, s = 6;

   printf("\n\n\t Enter Total No. Of Stations Value : ");
   scanf("%d",&n);
   printf("\n\n\t Enter Total No. Of Stopping Stations Value : ");
   scanf("%d",&s);
   
   int p = s;
   int num = 1, dem = 1;
   while (p!=1) {
      dem*=p;
      p--;
   }
   int t = n-s+1;
   while (t!=(n-2*s+1)) {
      num *= t;
      t--;
   }
   if ((n-s+1) >= s)
      printf("\n\n\t Possible ways = %d \n\n", num / dem);
   else
      printf("\n\n\t No possible ways \n\n");

      return 0;
}