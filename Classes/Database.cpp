//
//  Database.cpp
//  Game
//
//  Created by kwon giwon on 2014. 10. 16..
//
//

#include "Database.h"
#include "cocos2d.h"
#include <fstream>
#include <stdlib.h>
#include <ctime>

USING_NS_CC;

static Database* _instance;

Database::Database()
{
	FileUtils* fileUtils = FileUtils::getInstance();
	std::string dataFilePath = fileUtils->getWritablePath()+this->dataFileName;
	std::cout<<dataFilePath<<std::endl;
	if(fileUtils->isFileExist(dataFilePath)){
		std::ifstream inStream(dataFilePath);
		inStream >> this->data;
		inStream.close();
	}else{
		std::ifstream initDataStream(fileUtils->fullPathForFilename(this->dataFileName));
		initDataStream >> this->data;
		initDataStream.close();
		
		std::ofstream outStream(dataFilePath);
		Json::StyledStreamWriter writer("\t");
		writer.write(outStream, this->data);
		outStream.close();
	}
}

Database* Database::getInstance()
{
	if(_instance == NULL){
		_instance = new Database();
	}
	return _instance;
}

std::string Database::generateID()
{
	srand(time(NULL));
	time_t rawtime;
	struct tm* timeinfo;
	time(&rawtime);
	timeinfo = localtime(&rawtime);
	
	std::string timeString = asctime(timeinfo);
	
	std::stringstream sstm;
	sstm<<timeString<<rand();
	
	std::string idString = sstm.str();
	std::hash<std::string> str_hash;
	
	sstm.str("");
	sstm<<str_hash(idString);
	
	return sstm.str();
}

Json::Value Database::addIdToObject(Json::Value object)
{
	object["id"] = this->generateID();
	return object;
}

Json::Value Database::getObject(std::vector<std::string> keys)
{
	if(keys.size() == 0){
		log("there is no key");
		return Json::Value();
	}
	Json::Value result = data;
	for(auto key : keys){
		result = result[key];
	}
	return result;
}

Json::Value Database::getShopList()
{
	return this->getObject(std::vector<std::string>{"shop"});
}

Json::Value Database::getUnitList()
{
	return this->getObject(std::vector<std::string>{"units"});
}

Json::Value Database::getUserInventory()
{
	return this->getObject(std::vector<std::string>{"inventory"});
}

Json::Value Database::getUserInfo()
{
	return this->getObject(std::vector<std::string>{"userInfo"});
}

Json::Value Database::find(std::vector<std::string> keys)
{
	return this->getObject(keys);
}
Json::Value Database::find(std::vector<std::string> keys, int index)
{
	return Json::Value();
}
Json::Value Database::find(std::vector<std::string> keys, std::string identifier, std::string value)
{
	for(auto data : this->getObject(keys)){
		if(data[identifier].asString().compare(value) == 0){
			return data;
		}
	}
	return Json::Value();
}

void Database::remove(std::vector<std::string> keys, std::string identifier, std::string value)
{
	Json::Value originalData = this->getObject(keys);
	Json::Value newData;
	newData.append(Json::Value::null);
	newData.clear();
	
	for(auto data : originalData){
		if(data[identifier].asString().compare(value) != 0){
			newData.append(data);
		}
	}
	
	this->getpObject(keys)->swap(newData);
	
}

void Database::update(std::vector<std::string> keys, std::string identifier, std::string value, Json::Value object)
{
	this->remove(keys, identifier, value);
	this->saveToObject(keys, object);
}

void Database::saveToObject(std::vector<std::string> keys, Json::Value object)
{
	Json::Value* addTo = this->getpObject(keys);
	(*addTo).append(object);
	this->save();
}

Json::Value* Database::getpObject(std::vector<std::string> keys)
{
	Json::Value* pData = &this->data;
	for(auto key : keys){
		pData = &(*pData)[key];
	}
	return pData;
}

void Database::save()
{
	Json::StyledStreamWriter writer("\t");
	std::string dataFilePath = FileUtils::getInstance()->getWritablePath()+this->dataFileName;
	std::ofstream outStream;
	outStream.open(dataFilePath,std::ios::trunc);
	writer.write(outStream, this->data);
	outStream.close();
}