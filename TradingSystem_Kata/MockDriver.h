#include "StockerBrokerDriver.h"

class MockAdapter : public StockerBrokerDriverInterface {
    void doLogin(std::string ID, std::string password) override;
    void buyStock(std::string stockCode, int count, int price) override;
    void sellStock(std::string stockCode, int count, int price) override;
    int getCurrentPrice(std::string stockCode) override;
    int getMarketPriceInMinutue(std::string stockCode, int minute) override;
};