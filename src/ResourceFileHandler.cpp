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
	
	//TODO: Remove, for testing only
	//Read Test File
	std::filesystem::path testFilePath(resourcesPath/"testFile_XML.xml");
	rapidxml::file<> testFile = rapidxml::file<>(testFilePath.generic_string());
	rapidxml::xml_document<> testDocument;
	testDocument.parse<rapidxml::parse_default>(testFile.data());

}
