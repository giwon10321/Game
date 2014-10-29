//
//  Database.h
//  Game
//
//  Created by kwon giwon on 2014. 10. 16..
//
//

#ifndef __Game__Database__
#define __Game__Database__

#include <iostream>
#include "jsoncpp/json/json.h"

class Database
{
public:
	static Database* getInstance();
	std::string generateID();
	Json::Value addIdToObject(Json::Value object);
	Json::Value getObject(std::vector<std::string> keys);
	
	Json::Value getShopList();
	Json::Value getUnitList();
	Json::Value getUserInventory();
	
	Json::Value find(std::vector<std::string> keys);
	Json::Value find(std::vector<std::string> keys, std::string identifier, std::string value);
	Json::Value find(std::vector<std::string> keys, int index);
	
	void remove(std::vector<std::string> keys, std::string identifier, std::string value);
	
	void update(std::vector<std::string> keys, std::string identifier, std::string value, Json::Value object);
	
	void saveToObject(std::vector<std::string> keys, Json::Value object);
private:
	const std::string dataFileName = "gameData.json";
	Json::Value data;
	Database();
	Json::Value* getpObject(std::vector<std::string> keys);
	void save();
};

#endif /* defined(__Game__Database__) */
