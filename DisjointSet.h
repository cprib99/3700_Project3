#include <cstdint>
#include <iostream>

#ifndef _DISJOINTSET_H
#define _DISJOINTSET_H

using namespace std;

class DisjointSet
{
  int *rank, *elements, n;

public:
  //constructor
  DisjointSet(int n)
  {
    rank = new int[n];
    element = new int[n];
    setInitialize();
  }
  //destructor
  ~DisjointSet():
  {

  }

  //function to place data into elements & rank array
  void setInitialize()
  {
    for (int i = 0; i < n; i++)
    {
      elements[i] = i;
      rank[i] = 0;
    }
  }

  //Algorithm 3 - Disjoint set find
  int find(a)
  {
      if(elements[a] != a)                //Connect a directly to the top of intree
      {
          elements[a] = find(elements[a]);
      }

      return elements[a];                 //Return top of intree
  }

  //Algorthm 2 - Disjoint set union
  void join(int a, int b)
  {
      a = find(a);
      b = find(b);

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
};
#endif
