#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

#include "orderbookentry.h"
#include "MerkelMain.h"
#include "CsvReader.h"

double computerAveragePrice(std::vector<OrderBookEntry>& entries) {
    double sum;

    for (unsigned i = 0; i < entries.size(); i++)
    {
        sum += entries[i].price;
    }

    return sum / entries.size();
}

double computeLowPrice(std::vector<OrderBookEntry>& entries) {
    double minPrice = 0;

    for (unsigned int i = 0; i < entries.size(); i++)
    {
        if (minPrice == 0 || entries[i].price < minPrice)
        {
            minPrice = entries[i].price;
        }
    }

    return minPrice;
}

double computeHighPrice(std::vector<OrderBookEntry>& entries) {
    double maxPrice = 0;

    for (unsigned int i = 0; i < entries.size(); i++)
    {
        if (entries[i].price > maxPrice)
        {
            maxPrice = entries[i].price;
        }
    }

    return maxPrice;
}

double computePriceSpread(std::vector<OrderBookEntry>& entries){
    return computeHighPrice(entries) - computeLowPrice(entries);
}

int main(int argc, char *argv[]) {
    MerkelMain app{};
    app.init();
    return 0;
}