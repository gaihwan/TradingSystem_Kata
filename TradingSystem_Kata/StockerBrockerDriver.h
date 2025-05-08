#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

class StockerBrockerDriverInterface {
public:
	virtual void login(std::string ID, std::string password) = 0;
	virtual void buy(std::string stockCode, int count, int price) = 0;
	virtual void sell(std::string stockCode, int count, int price) = 0;
	virtual int currentPrice(std::string stockCode) = 0;
	virtual int getMarketPrice(std::string stockCode, int minute) = 0;
};