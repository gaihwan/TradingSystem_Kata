#include "StockerBrokerDriver.h"

class MockApi {
public:
    virtual void doLogin(std::string ID, std::string password) = 0;
    virtual void buyStock(std::string stockCode, int count, int price) = 0;
    virtual void sellStock(std::string stockCode, int count, int price) = 0;
    virtual int getCurrentPrice(std::string stockCode) = 0;
    virtual int getMarketPriceInMinutue(std::string stockCode, int minute) = 0;
};
