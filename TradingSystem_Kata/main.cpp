#include "gmock/gmock.h"
#include "kiwer_api.cpp"
#include "nemo_api.cpp"

TEST(TradingSystemTS, CreateApplicationClass) {
    Application* app = nullptr;
    EXPECT_EQ(app, nullptr);
}

int main() {
    ::testing::InitGoogleMock();
    return RUN_ALL_TESTS();
}