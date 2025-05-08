#include "gmock/gmock.h"
#include "kiwer_api.cpp"
#include "nemo_api.cpp"
#include "StockerBrokerDriver.h"
#include "MockApi.h"

#include <iostream>
#include <string>

using namespace testing;

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

TEST(MockDriverTC, doLoginTC) {
    MockDriver mock;
    EXPECT_CALL(mock, doLogin("Anonymous", "1234"));
    mock.doLogin("Anonymous", "1234");
}

TEST(MockDriver, sellStockTC) {
    MockDriver mock;
    EXPECT_CALL(mock, sellStock("00700", 100, 10000));

    //MockAdapter adapter{ &mock }
    mock.sellStock("00700", 100, 10000);
}

TEST(MockDriver, buyStockTC) {
    MockDriver mock;
    EXPECT_CALL(mock, buyStock("00700", 500, 12000));

    //MockAdapter adapter{ &mock }
    mock.buyStock("00700", 500, 12000);
}

TEST(MockDriver, getCurrentPriceTC) {
    MockDriver mock;
    EXPECT_CALL(mock, getCurrentPrice("00700"))
        .WillOnce(Return(9900))
        .WillOnce(Return(10000))
        .WillRepeatedly(Return(10100));

    //MockAdapter adapter{ &mock }
    int expected = 0;
    expected = mock.getCurrentPrice("00700");
    EXPECT_EQ(expected, 9900);
    expected = mock.getCurrentPrice("00700");
    EXPECT_EQ(expected, 10000);
    expected = mock.getCurrentPrice("00700");
    EXPECT_EQ(expected, 10100);
}

TEST(MockDriver, getMarketPriceInMinutueTC) {
    MockDriver mock;
    EXPECT_CALL(mock, getMarketPriceInMinutue("00700", 1))
        .WillOnce(Return(11000))
        .WillOnce(Return(11100))
        .WillRepeatedly(Return(11200));

    //MockAdapter adapter{ &mock }
    int expected = 0;
    expected = mock.getMarketPriceInMinutue("00700", 1);
    EXPECT_EQ(expected, 11000);
    expected = mock.getMarketPriceInMinutue("00700", 1);
    EXPECT_EQ(expected, 11100);
    expected = mock.getMarketPriceInMinutue("00700", 1);
    EXPECT_EQ(expected, 11200);
}


//TEST(StockBrockerDriverInterface, CreateStockBrockerInterface) {
//    StockerBrokerDriverInterface* brockerInterface = new StockerBrokerDriverInterface();
//    EXPECT_NE(&brockerInterface, nullptr); 
//}

int main() {
    ::testing::InitGoogleMock();
    return RUN_ALL_TESTS();
}