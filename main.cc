//Jordan Brown
//Cam Pribulsky
//Project 3 - Hex Pathfinder
#include <iostream>
#include "DisjointSet.h"
#include "hexpathfinder.h"
#include "hexoutput.cpp"
#include "Sampler.cpp"
#include "stack.h"

using namespace std;

//Globals

uint8_t maze;
/*maze bit interface:
bits 0-5 are walls, starting at the "bottom" and rotating clockwise
bit 6 is the "visited" bit
bit 7 is the "dead end" bit
*/

const int32_t
  dC[] = {0,1,1,0,-1,-1},
  dReven[] = {-1,-1,0,1,0,-1},
  dRodd[] = {-1,0,1,1,1,0};
int32_t
  *dR;

//Prototypes
void GenerateMaze(int nR,int nC);
void FindPath(uint8_t maze);
int encode(int32_t r, int32_t c, int32_t d, int32_t nR, int32_t nC);
void decode(int32_t e,int32_t nR, int32_t nC, int32_t &r, int32_t &c, int32_t &d);

int main(int argc, int *argv[])
{
    if (argc != 3){
      std::cout << "Usage: " << argv[0] << "nRows nColumns" << std::endl;
    }

    int32_t nR, nC;

    //read data using cin
    nR = atoi(argv[1]);
    nC = atoi(argv[2]);

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
    int i, e, objNum, sampObjNum, r1, r2, c1, c2, d;

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
              (r1, c1, d) = decodeCell(e);

              //Set(r2, c2) to cell adjacent to (r1, c1) in given direction
              maze[r1][c1] = encode(r1, c1, 0);
              maze[r2][c2] = encode(r2, c2, 0);
        }
        while(find(c1) == find(c2));

        join(c1, c2);
        i++;

        //Remove wall between (r1, c1) and (r1, c2);
        maze[r1][c1] = (maze[r1][c1] & ~(1 << (d-1)));
        maze[r2][c2] = (maze[r2][c2] & ~(1 << (d-1)));
    }

}

//Algorithm 5 - Maze solver
void FindPath(maze)
{
    //Variables:

    int r, c, d, r1, c1;
    Stack<int32> S;
    int r, c, d,


    //Code:
    S.push(encode(0, 0, 0));
    //turn off 6th bit to mark visit
    maze[0][0] = (maze[0][0] & ~(1 << (6-1)));

    while(true)
    {
        (r, c, d) = decode(S.peek());
        if((r == nR - 1) && (c =0 nC - 1))
        {
            break;
        }

        if(d == 6)
        {
            //mark cell as dead end
            maze[r][c] = (maze[r][c] & ~(1 << (7-1)));
            S.pop();
        }
        else
        {
            //Let (neighborR, neighborC) be the next cell in the direction d
            dR = (c1 + 1) ? dRodd : dReven;
            for (int i=0; i<6; i++)
            {
              neighborR = r + dR[dir1];
              neighborC = c + dC[dir1];
            }
            //Replace encode(r, c, d) with encode(r, c, d + 1) on top of stack
            S.pop();
            S.push(encode(r, c, d+1));

            //if no wall exists in direction d && (neighborR, neighborC) is not marked as visited
            if()
            {
                S.push(encode(neighborR, neighborC, 0));
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
