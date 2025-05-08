#include "StockerBrokerDriver.h"
#include "nemo_api.cpp"

class NemoDriver : public StockerBrokerDriverInterface {
public:
	void doLogin(std::string ID, std::string password) override {
		objAPI.certification(ID, password);
	}

	void buyStock(std::string stockCode, int count, int price) override {
		objAPI.purchasingStock(stockCode, price, count);
	}

	void sellStock(std::string stockCode, int count, int price) override {
		objAPI.sellingStock(stockCode, price, count);
	}

	int getCurrentPrice(std::string stockCode) override {
		throw std::runtime_error("Not supoort");
	}

	int getMarketPriceInMinutue(std::string stockCode, int minute) override {
		objAPI.getMarketPrice(stockCode, minute);
	}

private:
	NemoAPI objAPI;
};