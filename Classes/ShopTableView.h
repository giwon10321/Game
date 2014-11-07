//
//  ShopTableView.h
//  Game
//
//  Created by kwon giwon on 2014. 10. 31..
//
//

#ifndef __Game__ShopTableView__
#define __Game__ShopTableView__

#include <iostream>
#include "cocos2d.h"
#include "Database.h"
#include <extensions/cocos-ext.h>

USING_NS_CC;
USING_NS_CC_EXT;

class ShopTableView : public Layer, public TableViewDelegate, public TableViewDataSource
{
	
public:
	TableView* tableView;
	Size listSize;
	Json::Value data;

	static Scene* createScene();
	virtual bool init();
	
	virtual Size cellSizeForTable(TableView* table);
	virtual TableViewCell* tableCellAtIndex(TableView* table, ssize_t idx);
	virtual ssize_t numberOfCellsInTableView(TableView* table);
	
	void fetchData();
	
	virtual	void tableCellTouched(TableView* table, TableViewCell* cell);
	virtual void scrollViewDidScroll(ScrollView* view);
	virtual void scrollViewDidZoom(ScrollView* view);
	
	CREATE_FUNC(ShopTableView);
};

#endif /* defined(__Game__ShopTableView__) */
