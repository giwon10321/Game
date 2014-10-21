//
//  Database.cpp
//  Game
//
//  Created by kwon giwon on 2014. 10. 16..
//
//

#include "Database.h"
#include <fstream>
#include <stdlib.h>
#include <ctime>

static Database* _instance;

Database::Database()
{
    std::string filePath = FileUtils::getInstance()->fullPathForFilename(FILENAME);
	std::ifstream in(filePath);
	in >> root;
	in.close();
}

Database* Database::getInstance()
{
	if(_instance == NULL){
		_instance = new Database();
	}
	return _instance;
}

//	Json::Value root;
//    root["Name"] = "Hong Gildong";
//    root["Age"] = 26;
//
//    Json::Value friends;//배열
//    friends.append("Im Kkeokjung");
//    friends.append("Elisabeth");
//    root["Friend"] = friends;
//    root["Sex"] = "male";
//
//    Json::StyledWriter writer;
//    std::string strJSON = writer.write(root);
//
//    log("JSON WriteTest : %s" , strJSON.c_str());
//	std::cout<<root;
//	for(Json::Value val : root["shop"]["towers"]){
//		std::cout<<"Value : "<<val<<std::endl;
//	}

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
	Json::Value result;
	result[this->generateID()] = object;
	return result;
}

Json::Value Database::getObject(std::vector<std::string> keys)
{
	if(keys.size() == 0){
		log("there is no key");
		return Json::Value();
	}
	Json::Value result = root;
	for(auto key : keys){
		result = result[key];
	}
	return result;
}

Json::Value Database::getShopList()
{
	return this->getObject(std::vector<std::string>{"shop"});
}

Json::Value Database::getInventoryList()
{
	return this->getObject(std::vector<std::string>{"inventory"});
}

Json::Value Database::getUnitList()
{
	return this->getObject(std::vector<std::string>{"units"});
}

void Database::saveToObject(std::vector<std::string> keys, Json::Value object)
{
//	std::string filePath = FileUtils::getInstance()->fullPathForFilename(FILENAME);
//	std::ofstream out;
//	out.open(filePath,std::ios::trunc);
//	Json::Value* addTo = &root;
//	for(auto key : keys){
//		addTo = &((*addTo)[key]);
//	}
//	(*addTo)[this->generateID()] = object;
//	
//	Json::StyledStreamWriter writer("\t");
//	writer.write(out, root);
//	out.close();
}
