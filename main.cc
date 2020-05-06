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
void encode(cell);
void decode(cell);


//Globals
uint8_t maze;
stack S;
int nR, nC;
const int32_t
  dC[] = {0,1,1,0,-1,-1},
  dReven[] = {-1,-1,0,1,0,-1},
  dRodd[] = {-1,0,1,1,1,0};
int32_t
  *dR;

int main(int argc, int *argv[])
{
    if (argc != 3){
      std::cout << "Usage: " << argv[0] << "nRows nColumns" << std::endl;
    }

    //read data using cin
    nR = atoi(nptr:argv[1]);
    nC = atoi(nptr:argv[2]);

    GenerateMaze(nR, nC);
    FindPath(maze);
    printMaze(maze, nR, nC);
}

//Alg 1 is in Sampler header file
//Algs 2 and 3 are in DisjointSet header file

//Algorithm 4 - Generate a maze
void GenerateMaze(int nR, int nC)
{
    //Variables:
    int i, e, objNum, sampObjNum;

    //Code:
    i=0;

    for(int r = 0; nR - 1; r++)
    {
        for(int c = 0; nC - 1; c++)
        {
            maze[r][c] = 63             //63 = 0b00111111; marks all six walls present
        }
    }

    //number of objects for classes below
    objNum = nR * nC;
    sampObjNum = 3 * objNum;

    //initialize disjoint set object "ds" with nR * nC elements;
    DisjointSet ds(objNum);

    //initialize samlper object "sampler" with 3 * nR * nC elements;
    Sampler sampler(sampObjNum);

    i = 0;
    while(i < ((nR * nC) - 1))
    {
        do
        {

            do
            {
                e = sampler.getSample()
            }
            while(//e referecnces an exterior or nonessential wall)
              (r1, c1, dir1) = decodeCell(e);

              //Set(r2, c2) to cell adjacent to (r1, c1) in given direction
              dR = (c1 + 1) ? dRodd : dReven;
              for (int i=0; i<6; i++)
              {
                neighborR = r + dR[dir1];
                neighborC = c + dC[dir1];
              }



              cell1 = encode(r1, c1, 0);
              cell2 = encode(r2, c2, 0);
        }
        while(find(cell1) == find(cell2));

        join(cell1, cell2);
        i++;

        //Remove wall bewtween (r1, c1) and (r1, c2);
        maze[r1][c1]
    }

}

//Algorithm 5 - Maze solver
void FindPath(maze)
{
    //Variables:
    int r, c, d,

    //Code:
    S.push(encode(0, 0, 0));
    //Mark (0, 0) as visited;

    while(true)
    {
        //fix this crap below
        (r, c, d) = decode(S.peek());
        if((r == nR - 1) && (c =0 nC - 1))
        {
            break;
        }

        if(d == 6)
        {
            //Mark(r, c) as a dead end;
            S.pop();
        }
        else
        {
            //Let (r', c') be the next cell in the direction d;;
            //Replace encode(r, c, d) with encode(r, c, d + 1) on top of stack;

            if(//no wall exists in direction d && (r', c') is not marked as visited)
            {
                S.push(encode(r', c', 0));
                //Mark(r', c') as visited;
            }
        }
    }

}

int encode(int32_t r, int32_t c, int32_t d, int32_t nR, int32_t nC)
{
  return e = c + nC * (r + nR * d);
}

void decode(int32_t e,int32_t nR, int32_t nC, int32_t &r, int32_t &c, int32_t &d)
{
  c = e % nC;
  e /= nC;
  r = e % nR;
  d = e / nR;
}
