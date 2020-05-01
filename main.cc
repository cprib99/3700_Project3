//Jordan Brown
//Cam Pribulsky
//Project 3 - Hex Pathfinder

//Prototypes
int SampleNoReplacement(list items, int n);
void DisjointSetUnion(elements, rank, int a, int b);
int DisjointSetFind(elements, rank, a);
void GenerateMaze(nR, nC);
void FindPath(maze);


//Globals

//Main
int main()
{
    //Variables:
    int n, columns, rows, e;


    //Code:
    //Read in here

    n = columns * rows;
    int items[n];
    e = SampleNoReplacement(items, n);



}


//Algorithm 1 - Sampling without replacement
int SampleNoReplacement(list items, int n)
{
    //Variables:
    int i, e;

    //Code:
    i = Rand mod n;                     //select a random position in the list
    e = items[i];                       //Remember the selected item
    n = n-1;                            //Decrement n
    items[i] = items[n];                //Move last item into selected position

    return e;

}

//Algorthm 2 - Disjoint set union
void DisjointSetUnion(elements, rank, int a, int b)
{
    //Variables:

    //Code:
    a = DisjointSetFind(a);
    b = DisjointSetFind(b);

    if(a != b)                          //Only union if a and b are in different sets
    {
        if(rank[a] < rank[b])           //Set with lower rank merged into set with larger rank
        {
            elements[a] = b;
        }
        else
        {
            if(rank[a] == rank[b])      //In case of tie, increment one set's rank
            {
                rank[a] = rank[a] + 1;
            }

            elements[b] = a;
        }
    }

}


//Algorithm 3 - Disjoint set find
int DisjointSetFind(elements, rank, a)
{
    //Variables:

    //Code:
    if(elements[a] != a)                //Connect a directly to the top of intree
    {
        elements[a] = DisjointSetFind(elements[a]);
    }

    return elements[a];                 //Return top of intree
}

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
        while(DisjointSetFind(cell1) == DisjointSetFind(cell2));

        DisjointSetUnion(cell1, cell2);
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

