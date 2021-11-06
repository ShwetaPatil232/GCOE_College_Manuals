#include <iostream>

using namespace std;

const int Skipped = 6; // Total Number of Faces/ Sides for each  cube = 6

int N; // Total Number of Cube We Give As Input Value in Main Function.


int cubes[500][6]; // 500: Total Max Cube. && 6: Total No. of faces of cube

int numberCanStack[500][100];   // Temperory Array to find Cube which satisfy condition or cube is visited or not.
int bestTopFaceToUse[500][100]; // TO store Answer Cube & its Faces Matrix which Satisfy 3 Conditons.
/*

1)  500 : Total Number Of Cubes
2)  100 : Total Number of Color for Faces.  { A cube is described by giving the colors of its faces in the
        following order: front, back, left, right, top and bottom face. For your convenience colors are identified
        by integers in the range 1 to 100.
}

3)  Answer cube : Cube which used in Building Tower 

4)  Most Important Condition : The bottom face of every cube (except the bottom cube, which is lying on the floor) 
    must have the same color as the top face of the cube below it.

5)  Top Face Color of Bottom Cube ===== Must Be Equal TO ===== Bottom Face Color of Top Cube 

*/


string ToFace(int facePos)
{
    switch (facePos)
    {
    case 0:
        return "front";
    case 1:
        return "back";
    case 2:
        return "left";
    case 3:
        return "right";
    case 4:
        return "top";
    default:
        return "bottom";
    }
}

void PrintOut(int cube, int color) // Simple Function to Print Output recursively
{
    if (cube == N) // here we check that if [ Current_Cube_Index == Total_Cube_Size +1 ] then return;
        return;

    if (bestTopFaceToUse[cube][color] == Skipped) //Here We check if [ Face_Side == 6 ] then move to next Cube for Print 
    {
        PrintOut(cube + 1, color); // move to next Cube 
    }

    else
    {
        int faceUsed = bestTopFaceToUse[cube][color];

        PrintOut(cube + 1, cubes[cube][faceUsed]);

        // Their numbering is weird
        cout << "\t" << (N - cube) << ' ' << "\t |  \t\t" << ToFace(faceUsed) << '\n';
    }
}

int NumCanStack(int cube, int color) // Actual Logic Function For checking Conditions
{
    if (cube == N) // here we check that if [ Current_Cube_Index == Total_Cube_Size +1 ] then return;
        return 0;

    int &num = numberCanStack[cube][color];

    if (num == -1) // if Number/ current cube is not visited then proceed check whether it is bestTopFaceUse
    {
        num = 0;
        int &bestTopFace = bestTopFaceToUse[cube][color];
        bestTopFace = Skipped;

        for (int face = 0; face < 6; ++face)
        {
            if (cubes[cube][face] == color)
            {
                int topFace = face ^ 1;
                int amount = NumCanStack(cube + 1, cubes[cube][topFace]) + 1;

                if (amount > num)
                {
                    num = amount;
                    bestTopFace = topFace;
                }
            }
        }

        // Attempt to skip
        int amount = NumCanStack(cube + 1, color);
        if (amount > num)
        {
            num = amount;
            bestTopFace = Skipped;
        }
    }

    return num;
}

int main()
{
    //int T = 1;
    int i = 1;

    cout << "\n\n\t Enter Number of Cubes You Want : ";

    while (cin >> N, N)
    {
        // Part 1:  Take Input for Each Cube Faces them in reverse
        if (i == 1)
        {
            cout << "\n\n========================================================";
            cout << "\n Enter the Values for Faces OR Side Of Cubes :  \n\n";
            cout << "front \t back \t left \t right \t top \t bottom \n";
            i++;
        }
        for (int cube = N - 1; cube >= 0; --cube)
        {
            for (int face = 0; face < 6; ++face)
                cin >> cubes[cube][face];
            cout << "\t";
        }

        // Part 2 : Clear data in Temperory Array NumberCanStack for chech cube is visited or not.
        for (int cube = 0; cube < N; ++cube)
        {
            for (int color = 0; color < 105; ++color)
                numberCanStack[cube][color] = -1;
        }



        /*Part 3 : Top Face Color of Bottom Cube ===== Must Be Equal TO ===== Bottom Face Color of Top Cube */
        int bestNum = 0, bestStartCube = -1, bestColor;
        for (int cube = 0; cube < N; ++cube)
        {
            for (int face = 0; face < 6; ++face)
            {
                int num = NumCanStack(cube, cubes[cube][face]);
                if (num > bestNum)
                {
                    bestNum = num;
                    bestStartCube = cube;
                    bestColor = cubes[cube][face];
                }
            }
        }



        /* Part 4: Simply Print Output Of Program .*/
        cout << "\n\n************** Output ***********************\n\n";
        cout << '\n';
        cout << "\nTotal Height Of Tower : " << bestNum << "\n\n"; // this line Show hight of our Tower + How many Total Blocks Are Used To Build Tower.

        cout << "\n\n--------------------------------------------------------\n";
        cout << "Index Of Cube \t |"<< "   Face Of Cube Attache To Upper Cube"<< "\n";
        cout << "--------------------------------------------------------\n\n";

        PrintOut(bestStartCube, bestColor); //Simple Print Function

        cout << "\n-------------------------------------------------------\n\n";

        exit(0);
    }
}

/*
 Input Values For Program  1;

1         2         2         2         1         2
3         3         3         3         3        3
3         2         1         1         1       1


*/

/*
 Input Values For Program  2;

1         2         2         2         1         2
3         1         3         3         3        3
3         2         1         1         1       1


*/