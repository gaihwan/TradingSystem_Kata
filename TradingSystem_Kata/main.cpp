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

class MockDriver : public MockAdapter {
    MOCK_METHOD(void, doLogin, (std::string ID, std::string password), (override));
    MOCK_METHOD(void, buyStock, (std::string stockCode, int count, int price), (override));
    MOCK_METHOD(void, sellStock, (std::string stockCode, int count, int price), (override));
    MOCK_METHOD(int, getCurrentPrice, (std::string stockCode), (override));
    MOCK_METHOD(int, getMarketPriceInMinutue, (std::string stockCode, int minute), (override));
};

TEST(MockDriver, CreateMockDriver) {
    MockDriver* mockAPI = new MockDriver;
    EXPECT_NE(&mockAPI, nullptr);
}

TEST(MockDriver, LoginMockDriver) {
    MockDriver* mockAPI = new MockDriver;
    EXPECT_CALL(mockAPI, doLogin(_, _));
    mockAPI->doLogin("Anonymous", "1234");
}

TEST(MockDriver, LoginMockDriver) {
    MockDriver mock;
    EXPECT_CALL(mock, doLogin(_, _));
    
    MockAdapter adapter{ &mock }
    adapter.doLogin("Anonymous", "1234");
}

TEST(MockDriver, SellMockDriver) {
    MockDriver mock;
    EXPECT_CALL(mock, sellStock(_, _, _));

    MockAdapter adapter{ &mock }
    adapter.sellStock("00700", 100, 10000);
}

TEST(MockDriver, buyMockDriver) {
    MockDriver mock;
    EXPECT_CALL(mock, buyStock(_, _, _));

    MockAdapter adapter{ &mock }
    adapter.buyStock("00700", 100, 12000);
}


TEST(StockBrockerDriverInterface, CreateStockBrockerInterface) {
    StockerBrokerDriverInterface* brockerInterface = new InterfaceMock();
    EXPECT_NE(&brockerInterface, nullptr); 
}

int main() {
    ::testing::InitGoogleMock();
    return RUN_ALL_TESTS();
}