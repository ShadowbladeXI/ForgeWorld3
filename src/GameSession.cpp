#include "../include/GameSession.h"

#include <iostream>

GameSession::GameSession()
	: universe(Universe()) 
	, resourceList(ResourceList())
{
	//TODO: Remove
	//Only for test purposes
	ResourceManager testResourceManager = ResourceManager(resourceList);
	testResourceManager.printResourceQuantities();
	std::string testString = testResourceManager.get(0).getQuantity().getString();

	ResourceManagerReturn errFlag;
	auto coal100g = resourceList.generateNewResource(0, resourceList.massGramm.generateQuantity(100));//Create a resource quantity which represents 100 g
	errFlag = testResourceManager.add(0, coal100g);
	testString = testResourceManager.get(0).getQuantity().getString();

	auto coal200g = resourceList.generateNewResource(0, resourceList.massGramm.generateQuantity(200));//Create a resource quantity which represents 200 g
	errFlag = testResourceManager.add(0, -coal200g);
	testString = testResourceManager.get(0).getQuantity().getString();

}
