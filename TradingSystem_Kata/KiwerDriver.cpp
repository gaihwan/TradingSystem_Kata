#include "StockerBrokerDriver.h"
#include "kiwer_api.cpp"

class KiwerDriver : public StockerBrokerDriverInterface {
public:
	void doLogin(std::string ID, std::string password) override {
		objAPI.login(ID, password);
	}

	void buyStock(std::string stockCode, int count, int price) override {
		objAPI.buy(stockCode, count, price);
	}

	void sellStock(std::string stockCode, int count, int price) override {
		objAPI.sell(stockCode, count, price);
	}

	int getCurrentPrice(std::string stockCode) override {
		objAPI.currentPrice(stockCode);
	}

	int getMarketPriceInMinutue(std::string stockCode, int minute) override {
		throw std::runtime_error("Not supoort");
	}

private:
	KiwerAPI objAPI;
};