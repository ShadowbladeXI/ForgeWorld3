#pragma once

#include "Tile.h"

class Chunk
{
public:
	static const int CHUNK_SIZE = 16;//2^4

	Tile& getTileAt(int inChunkX, int inChunkY);

private:
	Tile tiles[CHUNK_SIZE][CHUNK_SIZE];

};

