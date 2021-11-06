#include<iostream>
#include<algorithm>
using namespace std;


int dp[1000]; // Temperory store  all elephant element path that is used to store 
int path[1000];  // This store Solution Path that means all elephant object of structure which satisfying Conditions
int pos; // index of elach elephant object 
int ans; // Length Of Longest comman Subsequent of Elephants
int ii=1; // temp index

struct ele{
	int w; // weight of elephant
	int iq; // iq of elephant
	int id; // index of elephant

}e[1000]; // The data will contain information for at most 1000 elephants.


bool cmp(struct ele a,struct ele b) 
{
	if(a.w==b.w)
	{
		return a.iq>b.iq;
	}
	else
	{
		return a.w<b.w;
	}
}

void print(int x){

	if(ii==1)
	{
		printf("   Elephant ID  | Elephant Weight  \t| Elephant IQ \n");
		printf("---------------------------------------------------------\n");
	}
	ii++;
	if(ans--){
		print(path[x]);
		printf("\t%d\t|\t %d   \t|\t %d  \n",e[x].id,e[x].w,e[x].iq);
		
	}
}
int main()
{
	int cnt=0; 
	int N;

	printf("\n\n\t Enter How many Elephant : ");
	scanf("%d",&N);

	printf("\n\n=============================================================\n\n");


	printf("\n\n\t Enter value of Weight & IQ for each Elephant : ");

	printf("\n\nWeight \t  IQ \n");

	for(int i=0;i<N;i++)
	{
		
		scanf("%d%d",&e[cnt].w,&e[cnt].iq);
		e[cnt].id=cnt+1;
		dp[cnt]=1;
		++cnt;
	}
	// ctn == Last Elephant Index



	sort(e,e+cnt,cmp);
	/* 1) startaddress
	   2) endaddress
	   3) sort() takes a third parameter that is used to specify the order in which elements are to be sorted.
	*/

	for(int i=0;i<cnt;i++)
	{
		for(int j=0;j<i;j++)
		{
			if(e[i].w>e[j].w  &&  e[i].iq<e[j].iq  &&  dp[j]+1>dp[i])//Strictly increasing weight (some weights are equal, Special judgment required) 
			{
				dp[i]=dp[j]+1;
				 path[i]=j;// Answer Elephant path sequence  
			}

		}
			
		 if(ans<=dp[i])//The equal sign cannot be saved, our n is the largest possible value 
		{
			pos=i;
			ans=dp[i];
		}
	}


	printf("\n\n=========================== OUTPUT ================================= \n\n");

	printf("\n\n\t Length Of Longest comman Subsequent of Elephants : %d \n\n\n",ans);


	print(pos);//recursive output sequence 
	
	return 0;
 }

/*  Input : 1


6008 	  1300
6000      2100
500 	  2000
1000 	  4000
1100 	  3000
6000 	  2000
8000 	  1400
6000 	  1200
2000 	  1900




*/