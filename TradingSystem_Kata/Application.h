#include "StockerBrokerDriver.h"
#include <string>

class Application {
public:
	Application(StockerBrokerDriverInterface* driver);
	void selectStockBrocker(std::string stockName);
	void login(std::string ID, std::string password);
	void buy(std::string stockCode, int count, int price);
	void sell(std::string stockCode, int count, int price);
	int getPrice(std::string stockCode);
	void buyNiceTiming(std::string stockCode, int price);
	void sellNiceTiming(std::string stockCode, int count);

	const int MAX_COUNT = 100;

protected:
	StockerBrokerDriverInterface* driver;
};

class selectStockBrockerFail : public std::exception {
public:
	const char* what() const noexcept override {
		return "Stock brocker select failed.";
	}
};