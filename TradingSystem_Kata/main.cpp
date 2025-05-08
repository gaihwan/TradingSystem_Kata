#include "gmock/gmock.h"
#include "kiwer_api.cpp"
#include "nemo_api.cpp"
#include "StockerBrokerDriver.h"
#include "MockApi.h"

#include <iostream>
#include <string>

class MockDriver : public MockApi, public StockerBrokerDriverInterface {
public:
    MOCK_METHOD(void, doLogin, (std::string ID, std::string password), (override));
    MOCK_METHOD(void, buyStock, (std::string stockCode, int count, int price), (override));
    MOCK_METHOD(void, sellStock, (std::string stockCode, int count, int price), (override));
    MOCK_METHOD(int, getCurrentPrice, (std::string stockCode), (override));
    MOCK_METHOD(int, getMarketPriceInMinutue, (std::string stockCode, int minute), (override));
};


TEST(MockDriverTS, CreateMockDriverTC) {
    MockDriver* mock = new MockDriver;
    EXPECT_NE(&mock, nullptr);
}

TEST(MockDriverTC, LoginMockDriverTC) {
    MockDriver mock;
    EXPECT_CALL(mock, doLogin("Anonymous", "1234"));
    mock.doLogin("Anonymous", "1234");
}

TEST(MockDriver, SellMockDriver) {
    MockDriver mock;
    EXPECT_CALL(mock, sellStock("00700", 100, 10000));

    //MockAdapter adapter{ &mock }
    mock.sellStock("00700", 100, 10000);
}

TEST(MockDriver, buyMockDriver) {
    MockDriver mock;
    EXPECT_CALL(mock, buyStock("00700", 500, 12000));

    //MockAdapter adapter{ &mock }
    mock.buyStock("00700", 500, 12000);
}

//TEST(StockBrockerDriverInterface, CreateStockBrockerInterface) {
//    StockerBrokerDriverInterface* brockerInterface = new StockerBrokerDriverInterface();
//    EXPECT_NE(&brockerInterface, nullptr); 
//}

int main() {
    ::testing::InitGoogleMock();
    return RUN_ALL_TESTS();
}