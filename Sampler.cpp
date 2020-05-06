#include "Sampler.h"

Sampler::Sampler(uint32_t n)
{

    items = new uint32_t [n];

    nItems = n;

    for (items i = 0; i < n; i++)
        items[i] = i;

    rd = new std::random_device;
    mt = new std::mt19937(sd:(*rd)());

}

