#include "gmock/gmock.h"
#include "kiwer_api.cpp"
#include "nemo_api.cpp"

TEST(TradingSystemTS, CreateApplicationClass) {
    Application* app = nullptr;
    EXPECT_EQ(app, nullptr);
}


TEST(TradingSystemTS, CreateMockAPIClass) {
    MockAPI* mockAPI = nullptr;
    EXPECT_EQ(mockAPI, nullptr);
}


TEST(StockBrockerDriverInterface, CreateStockBrockerInterface) {
    StockBrockerInterface* brockerInterface = nullptr;
    EXPECT_EQ(mockAPI, nullptr);
}

int main() {
    ::testing::InitGoogleMock();
    return RUN_ALL_TESTS();
}