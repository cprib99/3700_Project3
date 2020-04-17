//Jordan Brown
//Cam Pribulsky
//Project 3 - Hex Pathfinder

//Prototypes
int SampleNoReplacement(list items, int n);
void DisjointSetUnion(elements, rank, int a, int b);


//Globals

//Main
int main()
{

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


}

//Algorithm 4 - 

