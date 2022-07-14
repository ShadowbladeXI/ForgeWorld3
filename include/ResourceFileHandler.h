#pragma once

#include <filesystem>
#include "ResourceType.h"
#include "dimensionUnitSystem/Dimensions.h"
#include <unordered_map>

class ResourceFileHandler{
private:
	std::filesystem::path basePath;
	std::filesystem::path resourcesPath;
public:
	ResourceFileHandler();

	void getAllResources_fromFiles(std::vector<ResourceType_Abstract*>&) const;
private:
	
};

