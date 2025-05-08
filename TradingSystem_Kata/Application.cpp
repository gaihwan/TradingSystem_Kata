#include <iostream>
#include <string>
#include "kiwer_api.cpp"
#include "nemo_api.cpp"

class Application {
public:
	// KiwerAPI
	virtual void login(std::string ID, std::string password) = 0;
	virtual void buy(std::string stockCode, int count, int price) = 0;
	virtual void sell(std::string stockCode, int count, int price) = 0;
	virtual int currentPrice(std::string stockCode) = 0;
	// NemoAPI
	virtual void certification(std::string ID, std::string pass) = 0;
	virtual void purchasingStock(std::string stockCode, int price, int count) = 0;
	virtual void sellingStock(std::string stockCode, int price, int count) = 0;
	virtual int getMarketPrice(std::string stockCode, int minute) = 0;
};

// Factory 
class ApplicationFactory {
public:
    virtual std::unique_ptr<Application> selectStockBrocker() = 0;
};

class KiwerFactory : public ApplicationFactory {
public:
    std::unique_ptr<Application> selectStockBrocker() override {
        return std::make_unique<KiwerAPI>();
    }
};

class NemoFactory : public ApplicationFactory {
public:
    std::unique_ptr<Application> selectStockBrocker() override {
        return std::make_unique<NemoAPI>();
    }
};

// Use example
//auto kiwerFac = std::make_shared<KiwerFactory>();
//auto kiwerApi = kiwerFac->selectStockBrocker();
//kiwerApi->login("ID", "PASSWORD");
