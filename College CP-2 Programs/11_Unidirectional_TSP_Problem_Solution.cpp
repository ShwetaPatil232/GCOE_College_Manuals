#include <iostream>

using namespace std;

int C, R;

bool reached[100][10]; 
int grid[100][10]; 
int bestCost[100][10]; 
int bestTo[100][10]; 

int GetBest(int c, int r)
{
    if (c == C)
        return 0;
    
    int &cost = bestCost[c][r];
    
    if (!reached[c][r])
    {
        reached[c][r] = true;
        int &to = bestTo[c][r];
        to = (r - 1 + R) % R;
        cost = GetBest(c + 1, to);
        
        int newCost = GetBest(c + 1, r);
        if (newCost < cost || (newCost == cost && r < to))
        {
            cost = newCost;
            to = r;
        }
        
        int newR = (r + 1) % R;
        newCost = GetBest(c + 1, newR);
        if (newCost < cost || (newCost == cost && newR < to))
        {
            cost = newCost;
            to = newR;
        }
        
        cost += grid[c][r];
    }
    return cost;
}

int main()
{

        /* Step 1 :  Taking Inout Values.*/
        cout<<"\n\n\t Enter Row Dimension For Graph : ";
        cin>>R;

        cout<<"\n\n\t Enter Column Dimension For Graph : ";
        cin>>C;   

        for (int r = 0; r < R; ++r)
        {
            for (int c = 0; c < C; ++c)
            {
                cin >> grid[c][r];
                reached[c][r] = false;;
            }
        }
        
         /* Step 2 :  Processing On Input Values for finding Output Result..*/
        int bestCost = 1e9, bestStart;
        
        for (int r = 0; r < R; ++r)
        {
            int cost = GetBest(0, r);
            if (cost < bestCost)
            {
                bestStart = r;
                bestCost = cost;
            }
        }
        

         /* Step 3 :  Printing Output Result..*/
        cout<<"\n\n============================= OUTPUT ==============================="; 
        cout << "\n\n Minimum Path is : \t";
        int current = bestStart;
        cout << current + 1;
        current = bestTo[0][current];
        int c = 1;
        while (c < C)
        {
            cout <<"\t"<< (current + 1);
            current = bestTo[c][current];
            ++c;
        }
        cout << "\n\n Minimum Path Cost is : "<< bestCost << '\n';

        cout<<"\n\n============================= End ===============================\n\n"; 
    
    
}