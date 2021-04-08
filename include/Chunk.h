#pragma once

#include "Tile.h"

class Chunk
{
public:
	static const int CHUNK_SIZE = 16;//2^4

	Tile& getTileAt(int inChunkX, int inChunkY);
	const Tile& getTileAt(int inChunkX, int inChunkY) const;
	

private:
	Tile tiles[CHUNK_SIZE][CHUNK_SIZE];

};

