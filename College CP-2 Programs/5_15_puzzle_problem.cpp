// C++ program to check if a given instance of N*N-1
// puzzle is solvable or not
#include <iostream>
#define N 4
using namespace std;

// A utility function to count inversions in given
// array 'arr[]'. Note that this function can be
// optimized to work in O(n Log n) time. The idea
// here is to keep code small and simple.
int getInvCount(int arr[])
{
	int inv_count = 0;
	for (int i = 0; i < N * N - 1; i++)
	{
		for (int j = i + 1; j < N * N; j++)
		{
			// count pairs(i, j) such that i appears
			// before j, but i > j.
			if (arr[j] && arr[i] && arr[i] > arr[j])
				inv_count++;
		}
	}
	return inv_count;
}

// find Position of blank from bottom
int findXPosition(int puzzle[N][N])
{
	// start from bottom-right corner of matrix
	for (int i = N - 1; i >= 0; i--)
		for (int j = N - 1; j >= 0; j--)
			if (puzzle[i][j] == 0)
				return N - i;
}

// This function returns true if given
// instance of N*N - 1 puzzle is solvable
bool isSolvable(int puzzle[N][N])
{
	// Count inversions in given puzzle
	int invCount = getInvCount((int*)puzzle);

	// If grid is odd, return true if inversion
	// count is even.
	if (N & 1)
		return !(invCount & 1);

	else	 // grid is even
	{
		int pos = findXPosition(puzzle);
		if (pos & 1)
			return !(invCount & 1);
		else
			return invCount & 1;
	}
}

/* Driver program to test above functions */
int main()
{

	int puzzle[N][N] ={

		{12, 1, 10, 2},
		{7, 11, 4, 14},
		{5, 0, 9, 15}, // Value 0 is used for empty space
		{8, 13, 6, 3},
	};


	cout<<"\n\t Entered Matrix is :\n";
	for(int i=0;i < N;i++)
	{
		for(int j=0;j < N ;j++)
			cout<<puzzle[i][j]<<"\t ";
		cout<<"\n";
	}

    cout<<"\n\t Target Matrix is :\n";
    int count=1;
	for(int i=0;i < N;i++)
	{
		for(int j=0;j < N ;j++)
        {
            if(count==16)
            {
                cout<<0<<"\t ";
                break;
            }
			cout<<count<<"\t ";
            count++;
        }
		cout<<"\n";
	}

    cout<<"\n\n\t ********************  OUTPUT ********************** \n\n\t ";
	isSolvable(puzzle)? cout << "Solvable":
						cout << "Not Solvable";

    cout<<"\n\n\t End Of Program \n\n";
	return 0;
}
