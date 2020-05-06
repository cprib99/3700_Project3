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

Sampler::~Sampler()
{
    delete[] items;
}

uint32_t Sampler::getSample()
{
    uint32_t
        r,
        tmp;
    std::uniform_int_distribution<>
        dis(a:0, b:nItems-1);

    //step1:
    r = (uint32_t)dis(&:*mt);

    //step2:
    tmp = items[r];

    //step3:
    nItems--;

    //step4:
    items[r] = items[nItems];

    //step5:
    return tmp;


}
