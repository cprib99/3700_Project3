#ifndef #SAMPLER_H
#define SAMPLER_H


#include <cstdint>
#include <random>

class Sampler
{
public:
	explicit Sampler(uint32_t n);
	~Sampler();

	uint32_t getSample();

private:
	uint32_t
		*items,
		nItems;

	std::random_device
		*rd;
	std::mt19937
		*mt;

};

#endif //SAMPLER_H