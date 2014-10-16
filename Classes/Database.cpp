//
//  Database.cpp
//  Game
//
//  Created by kwon giwon on 2014. 10. 16..
//
//

#include "Database.h"

using namespace std;
Database::Database()
{
    std::string path = FileUtils::getInstance()->getWritablePath()+"test.db";
    cout << "path : " <<path<<endl;
    Kompex::SQLiteDatabase *pDatabase = new Kompex::SQLiteDatabase(path,SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE, 0);
    Kompex::SQLiteStatement *pStmt = new Kompex::SQLiteStatement(pDatabase);
    
    pStmt->SqlStatement("CREATE TABLE if not exists user (userID INTEGER NOT NULL PRIMARY KEY, lastName VARCHAR(50) NOT NULL, firstName VARCHAR(50), age INTEGER, weight DOUBLE)");
//    pStmt->SqlStatement("INSERT INTO user (userID, lastName, firstName, age, weight) VALUES (1, 'Lehmann', 'Jamie', 20, 65.5)");
//    pStmt->SqlStatement("INSERT INTO user (userID, lastName, firstName, age, weight) VALUES (2, 'Burgdorf', 'Peter', 55, NULL)");
//    pStmt->SqlStatement("INSERT INTO user (userID, lastName, firstName, age, weight) VALUES (3, 'Lehmann', 'Fernando', 18, 70.2)");
//    pStmt->SqlStatement("INSERT INTO user (userID, lastName, firstName, age, weight) VALUES (4, 'Lehmann', 'Carlene ', 17, 50.8)");
}