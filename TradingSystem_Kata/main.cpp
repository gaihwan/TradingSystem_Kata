#include "gmock/gmock.h"
#include "kiwer_api.cpp"
#include "nemo_api.cpp"
#include "StockerBrokerDriver.h"

#include <iostream>
#include <string>

class InterfaceMock : public StockerBrokerDriverInterface {
    MOCK_METHOD(void, doLogin, (std::string ID, std::string password), (override));
    MOCK_METHOD(void, buyStock, (std::string stockCode, int count, int price), (override));
    MOCK_METHOD(void, sellStock, (std::string stockCode, int count, int price), (override));
    MOCK_METHOD(int, getCurrentPrice, (std::string stockCode), (override));
    MOCK_METHOD(int, getMarketPriceInMinutue, (std::string stockCode, int minute), (override));
};

TEST(TradingSystemTS, CreateApplicationClass) {
    Application* app = nullptr;
    EXPECT_EQ(app, nullptr);
}


TEST(TradingSystemTS, CreateMockAPIClass) {
    MockAPI* mockAPI = nullptr;
    EXPECT_EQ(mockAPI, nullptr);
}


TEST(StockBrockerDriverInterface, CreateStockBrockerInterface) {
    StockerBrokerDriverInterface* brockerInterface = new InterfaceMock();
    EXPECT_NE(&brockerInterface, nullptr); 
}

int main() {
    ::testing::InitGoogleMock();
    return RUN_ALL_TESTS();
}