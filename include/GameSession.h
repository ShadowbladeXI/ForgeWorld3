#pragma once

#include "Universe.h"
#include "ResourceList.h"
#include "ResourceManager.h"
#include "MapObjectTypesManager.h"

class GameSession
{
public:
	GameSession();

private:
	Universe universe;
	ResourceList resourceList;
	MapObjectTypesManager mapObjectTypesManager;
};

