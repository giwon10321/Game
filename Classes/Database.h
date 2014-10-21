//
//  Database.h
//  Game
//
//  Created by kwon giwon on 2014. 10. 16..
//
//

#ifndef __Game__Database__
#define __Game__Database__

#include "cocos2d.h"
#include <iostream>
#include "jsoncpp/json/json.h"

USING_NS_CC;


#define FILENAME "data.json"

class Database
{
public:
	static Database* getInstance();
	std::string generateID();
	Json::Value addIdToObject(Json::Value object);
	Json::Value getObject(std::vector<std::string> keys);
	Json::Value getShopList();
	Json::Value getInventoryList();
	Json::Value getUnitList();
	void saveToObject(std::vector<std::string> keys, Json::Value object);
private:
	Json::Value root;
	Database();
};

#endif /* defined(__Game__Database__) */
