#include "..\include\ResourceFileHandler.h"

#include "../include/rapidxml-1.13/rapidxml_utils.hpp"
#include "../include/rapidxml-1.13/rapidxml.hpp"
#include <Windows.h>
#include <iostream>

ResourceFileHandler::ResourceFileHandler(){
	//Get Base Folder
	std::vector<wchar_t> pathBuffer(1024);
	int exePathNameSize = GetModuleFileName(nullptr, &pathBuffer[0], pathBuffer.size());
	std::wstring exePathName(pathBuffer.begin(), pathBuffer.end());
	std::filesystem::path exePath(exePathName);
	basePath = exePath.parent_path().parent_path();


	//Define main paths relative to base path
	resourcesPath = basePath/"resources";
	
}

void ResourceFileHandler::getAllResources_fromFiles(std::vector<ResourceType_Abstract*>& resources) const{
	//TODO: Remove, for testing only
	//Read Test File
	std::filesystem::path testFilePath(resourcesPath/"testFile_XML.xml");
	rapidxml::file<> testFile = rapidxml::file<>(testFilePath.generic_string());
	auto* testDocument_ptr = new rapidxml::xml_document<>();
	testDocument_ptr->parse<rapidxml::parse_default>(testFile.data());

	char resourceLib_node_name[] = "Resources";
	char resource_node_name[] = "Resource";
	char resource_name_node_name[] = "Name";
	char resource_dimension_node_name[] = "Dimension";

	auto* resourceLib_node_ptr = testDocument_ptr->first_node(resourceLib_node_name);

	for (rapidxml::xml_node<>* resource_node_ptr = resourceLib_node_ptr->first_node(resource_node_name); resource_node_ptr!=0; resource_node_ptr = resource_node_ptr->next_sibling(resource_node_name)) {
		//Add a resource to the list
		
		auto resource_name_node = resource_node_ptr->first_node(resource_name_node_name);
		std::string resource_name(resource_name_node->value(), resource_name_node->value_size());
		
		auto resource_dimension_node = resource_node_ptr->first_node(resource_dimension_node_name);
		std::string resource_dimension_string(resource_dimension_node->value(), resource_dimension_node->value_size());
		//const Dimension<ResourcesInternalType>& resource_dimension = dimensions.find(resource_dimension_string);

		if(resource_dimension_string == "mass"){
			auto* newResource_ptr = new ResourceType<Mass>(resource_name);
			resources.push_back(newResource_ptr);
		} else {
			//TODO: Error handling for not findable resource
		}
		
	}

	resources.shrink_to_fit();

	delete testDocument_ptr;
}
