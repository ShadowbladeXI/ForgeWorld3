#pragma once

#include "Universe.h"
#include "ResourceList.h"
#include "ResourceManager.h"

class GameSession
{
public:
	GameSession();

private:
	Universe universe;
	ResourceList resourceList;
};

