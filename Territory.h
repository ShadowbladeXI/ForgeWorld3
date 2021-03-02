#pragma once

#include <vector>

#include "Chunk.h"

class Territory
{
public:
	Territory(unsigned int width, unsigned int height);

private:
	std::vector<std::vector<Chunk>> chunks;
};

