#include "gmock/gmock.h"
#include "kiwer_api.cpp"
#include "nemo_api.cpp"
#include "StockerBrockerDriver.h"

#include <iostream>
#include <string>

class InterfaceMock : public StockerBrockerDriverInterface {
    MOCK_METHOD(void, login, (std::string ID, std::string password), (override));
    MOCK_METHOD(void, buy, (std::string stockCode, int count, int price), (override));
    MOCK_METHOD(void, sell, (std::string stockCode, int count, int price), (override));
    MOCK_METHOD(int, currentPrice, (std::string stockCode), (override));
    MOCK_METHOD(int, getMarketPrice, (std::string stockCode, int minute), (override));
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
    StockerBrockerDriverInterface* brockerInterface = new InterfaceMock();
    EXPECT_NE(&brockerInterface, nullptr); 
}

int main() {
    ::testing::InitGoogleMock();
    return RUN_ALL_TESTS();
}