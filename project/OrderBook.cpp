#include "OrderBook.h"
#include "CsvReader.h"

#include <iostream>
#include <map>

OrderBook::OrderBook(std::string filename) {
    orders = CsvReader::readCSV(filename);
}

std::vector<std::string> OrderBook::getKnownProducts(){
    std::map<std::string, bool> prodMap;

    for(const OrderBookEntry &e: orders){
        prodMap[e.product] = true;
    }

    std::vector<std::string> products;
    for (const auto & productPair :prodMap) {
        products.push_back(productPair.first);
    }

    return products;
}

std::vector<OrderBookEntry> OrderBook::getOrders(OrderBookType type,
                                                 std::string product,
                                                 std::string timestamp){
    std::vector<OrderBookEntry> filteredOrders;

    for (const OrderBookEntry& e : orders) {
        if (e.type == type && e.timestamp == timestamp && e.product == product)
        {
            filteredOrders.push_back(e);
        }
    }

    return filteredOrders;
}

double OrderBook::getHighPrice(std::vector<OrderBookEntry> &orders){
    double maxPrice = 0;

    for (unsigned int i = 0; i < orders.size(); i++)
    {
        if (orders[i].price > maxPrice)
        {
            maxPrice = orders[i].price;
        }
    }

    return maxPrice;
}

double OrderBook::getLowPrice(std::vector<OrderBookEntry> &orders){
    double minPrice = 0;

    for (unsigned int i = 0; i < orders.size(); i++)
    {
        if (minPrice == 0 || orders[i].price < minPrice)
        {
            minPrice = orders[i].price;
        }
    }

    return minPrice;
}