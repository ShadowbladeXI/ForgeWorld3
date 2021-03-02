#pragma once

#include <vector>
#include <tuple>

#include "Chunk.h"
#include "Tile.h"

class Territory
{
public:
	Territory(int width, int height);

	void getTileAt(int x, int y, Tile&);

	void getChunkAt(int x, int y, Chunk&);

	void getChunkAndTileAt(int x, int y, Chunk& chunkOut, Tile& tileOut);

private:
	unsigned int width, height;
	int chunkGridMinX, chunkGridMaxX, chunkGridMinY, chunkGridMaxY;
	int tileGridMinX, tileGridMaxX, tileGridMinY, tileGridMaxY;
	std::vector<std::vector<Chunk>> chunks;
};

