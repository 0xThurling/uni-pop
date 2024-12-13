#pragma once

#include <vector>
#include "orderbookentry.h"
#include "OrderBook.h"
#include "CsvReader.h"

class MerkelMain
{
    private:
        // std::vector<OrderBookEntry> orders;

        OrderBook orderBook {"20200317.csv"};

        void loadOrderBook();
        void printMenu();
        void printHelp();
        void printMarketStats();
        void enterOffer();
        void enterBid();
        void printWallet();
        void gotoNextTimeFrame();
        int getUserOption();
        void processUserOption(int userOption);
    public:
        MerkelMain() = default;

        void init();
};
