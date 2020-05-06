//Jordan Brown
//Cam Pribulsky
//Project 3 - Hex Pathfinder
#include <iostream>
#include "DisjointSet.h"
#include "hexpathfinder.h"
#include "Sampler.h"
#include "stack.h"

using namespace std;

//Prototypes
void GenerateMaze(nR, nC);
void FindPath(maze);


//Globals
uint8_t maze;

//Main
int main()
{
    //Variables:
    int n, columns, rows, e;

    //read data using cin
    for (int i=0; i<2; i++)
      cin >> columns;
    for (int i=2; i<3; i++)
      //do nothing
    for (int i=3; i<5; i++)
      cin >> rows;


    n = columns * rows;
    int items[n];
    e = SampleNoReplacement(items, n);

    GenerateMaze(rows, columns);
    FindPath(maze);
    printMaze(maze, rows, columns);
}

//Alg 1 is in Sampler header file
//Algs 2 and 3 are in DisjointSet header file

//Algorithm 4 - Generate a maze
void GenerateMaze(in nR, int nC)
{
    //Variables:
    int i, e;

    //Code:
    i=0;

    for(int r = 0; nR - 1; r++)
    {
        for(int c = 0; nC - 1; c++)
        {
            maze[r][c] = 63             //63 = 0b00111111; marks all six walls present
        }
    }

    initialize disjoint set object "ds" with nR * nC elements;
    initialize smlper object "sampler" with 3 * nR * nC elements;

    i = 0;
    while(i < ((nR * nC) - 1))
    {
        do
        {

            do
            {
                e = sampler.getSample()
            }
            while(e referecnces an exterior or nonessential wall);

            (r1, c1, dir1) = decodeCell(e);
            Set(r2, c2) to cell adjacent to (r1, c1) in given direction;
            cell1 = encode(r1, c1, 0);
            cell2 = encode(r2, c2, 0);

        }
        while(find(cell1) == find(cell2));

        join(cell1, cell2);
        i++;

        Remove wall bewtween (r1, c1) and (r1, c2);

    }

}

//Algorithm 5 - Maze solver
void FindPath(maze)
{
    //Variables:
    int r, c, d,

    //Code:
    S.push(encode(0, 0, 0));
    Mark (0, 0) as visited;

    while(true)
    {
        (r, c, d) = decode(S.peek());
        if((r == nR - 1) && (c =0 nC - 1))
        {
            break;
        }

        if(d == 6)
        {
            Mark(r, c) as a dead end;
            S.pop();
        }
        else
        {
            Let (r', c') be the next cell in the direction d;;
            Replace encode(r, c, d) with encode(r, c, d + 1) on top of stack;

            if(no wall exists in direction d && (r', c') is not marked as visited)
            {
                S.push(encode(r', c', 0));
                Mark(r', c') as visited;
            }
        }
    }

}
