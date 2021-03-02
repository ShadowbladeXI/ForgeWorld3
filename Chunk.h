#pragma once

#include "Spot.h"

class Chunk
{
public:
	static const unsigned short CHUNK_SIZE = 2 ^ 4;

private:
	Spot spots[CHUNK_SIZE][CHUNK_SIZE];

};

