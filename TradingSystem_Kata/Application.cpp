#include "Application.h"
#include "kiwer_api.cpp"
#include "nemo_api.cpp"
#include "MockApi.h"
#include <windows.h>


Application::Application(StockerBrokerDriverInterface* driver) : driver{ driver }
{
}

void Application::selectStockBrocker(std::string stockBrockerName) {
    if ("Kiwer" == stockBrockerName) {
        // driver = new KiwerAPI();
    }
    else if ("Nemo" == stockBrockerName) {
        // driver = new NemoAPI();
    }
    else { // exception
        throw selectStockBrockerFail();
    }
}

void Application::login(std::string ID, std::string password) {
    driver->doLogin(ID, password);
}

void Application::buy(std::string stockCode, int count, int price) {
    driver->buyStock(stockCode, count, price);
}

void Application::sell(std::string stockCode, int count, int price) {
    driver->sellStock(stockCode, count, price);
}

int Application::getPrice(std::string stockCode) {
    return driver->getCurrentPrice(stockCode);
}

void Application::buyNiceTiming(std::string stockCode, int price) {
    int beforeValue = driver->getCurrentPrice(stockCode);
    int tempValue = 0;

    for (int i = 0; i <= 2; i++) {
        Sleep(1000);
        tempValue = driver->getCurrentPrice(stockCode);
        if (beforeValue >= tempValue) {
            return;
        }
        beforeValue = tempValue;
    }

    driver->buyStock(stockCode, MAX_COUNT, price);
}

void Application::sellNiceTiming(std::string stockCode, int count) {
    int beforeValue = driver->getCurrentPrice(stockCode);
    int tempValue = 0;

    for (int i = 0; i <= 2; i++) {
        Sleep(1000);
        tempValue = driver->getCurrentPrice(stockCode);
        if (tempValue >= beforeValue) {
            return;
        }
        beforeValue = tempValue;
    }

    driver->sellStock(stockCode, count, driver->getCurrentPrice(stockCode));
}