#include "Territory.h"

Territory::Territory(unsigned int width, unsigned int height)
{
	unsigned int widthChunks = width/Chunk::CHUNK_SIZE + (width%Chunk::CHUNK_SIZE != 0);
	unsigned int heightChunks = height/Chunk::CHUNK_SIZE + (height%Chunk::CHUNK_SIZE != 0);
	chunks = std::vector<std::vector<Chunk>>();
	chunks.reserve(widthChunks);
	for (int i = 0; i < widthChunks; ++i) {
		std::vector<Chunk> chunkRow = std::vector<Chunk>();
		chunkRow.reserve(heightChunks);
		for (int j = 0; j < heightChunks; ++j) {
			Chunk newChunk = Chunk();
			chunkRow.push_back(newChunk);
		}
		chunks.push_back(chunkRow);
	}
}
