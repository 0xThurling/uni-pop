#pragma once

#include <vector>
#include "orderbookentry.h"

class MerkelMain
{
    private:
        std::vector<OrderBookEntry> orders;

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
