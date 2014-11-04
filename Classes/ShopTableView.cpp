//
//  ShopTableView.cpp
//  Game
//
//  Created by kwon giwon on 2014. 10. 31..
//
//

#include "ShopTableView.h"

Scene* ShopTableView::createScene()
{
	auto scene = Scene::create();
	auto layer = ShopTableView::create();
	scene->addChild(layer);
	return scene;
}

bool ShopTableView::init()
{
	if(!Layer::init()){
		return false;
	}
	
	
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Size winSize = Size((visibleSize.width * 3)/4,(visibleSize.height*3)/4);
	
	listSize = Size(winSize.width, (winSize.height * 9)/10);
	
	TableView* tableView = TableView::create(this, listSize);
	tableView->setDirection(TableView::Direction::HORIZONTAL);
	tableView->setVerticalFillOrder(TableView::VerticalFillOrder::TOP_DOWN);
	tableView->setAnchorPoint(Vec2(0,0));
	tableView->setBounceable(false);
	
	tableView->setDelegate(this);
	addChild(tableView);
	tableView->reloadData();
	
	return true;
}

Size ShopTableView::cellSizeForTable(TableView* table)
{
	return Size(300,listSize.height);
}

TableViewCell* ShopTableView::tableCellAtIndex(cocos2d::extension::TableView *table,ssize_t idx)
{
	TableViewCell* cell = table->dequeueCell();
	
	cell = new TableViewCell();
	cell->autorelease();
	
	auto backgroundColor = Color3B(255,255,255);
	Sprite* bg = Sprite::create();
	bg->setAnchorPoint(Point(0,0));
	bg->setTextureRect(Rect(0,0,300,300));
	bg->setColor(backgroundColor);
	cell->addChild(bg);
	
	std::string id = StringUtils::format("%zd", idx);
	auto *label_1 = LabelTTF::create(id.c_str(), "Arial", 20);
    label_1->setAnchorPoint(Point(0, 0));
    label_1->setPosition(Point(0, 0));
    label_1->setColor(Color3B(0,0,0));
    cell->addChild(label_1);
	
	return cell;
}

ssize_t ShopTableView::numberOfCellsInTableView(cocos2d::extension::TableView *table)
{
	return 10;
}

void ShopTableView::tableCellTouched(cocos2d::extension::TableView *table, cocos2d::extension::TableViewCell *cell)
{

}

void ShopTableView::scrollViewDidScroll(ScrollView* view)
{

}

void ShopTableView::scrollViewDidZoom(ScrollView* view)
{

}
