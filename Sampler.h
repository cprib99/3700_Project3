#include <cstdint>
#include <iostream>

#ifndef _SAMPLER_H
#define _SAMPLER_H

class Sampler
{
	int *array;

public:
	//Constructor & Destructor num/den
	Sampler(int n)
	{
		for(int i = 0; i<=n; i++)
			array[i] = i;
	}
	~Sampler(void)
	{
		//add destructor
	}

	//Algorithm 1 - Sampling without replacement
	int getSample(list items, int n)
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
};


#endif
