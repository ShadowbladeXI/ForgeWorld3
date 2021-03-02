#pragma once

#include "Spot.h"

class Chunk
{
public:
	static const int CHUNK_SIZE = 16;//2^4

private:
	Spot spots[CHUNK_SIZE][CHUNK_SIZE];

};

