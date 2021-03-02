#pragma once

#include <vector>
#include <tuple>

#include "Chunk.h"
#include "Spot.h"

class Territory
{
public:
	Territory(int width, int height);

	Spot getSpotAt(int x, int y);

	Chunk getChunkAt(int x, int y);

	std::tuple<Chunk, Spot> getChunkAndSpotAt(int x, int y);

private:
	unsigned int width, height;
	int chunkGridMinX, chunkGridMaxX, chunkGridMinY, chunkGridMaxY;
	int spotGridMinX, spotGridMaxX, spotGridMinY, spotGridMaxY;
	std::vector<std::vector<Chunk>> chunks;
};

