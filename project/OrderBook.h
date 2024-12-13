#pragma once
#include "orderbookentry.h"
#include "CsvReader.h"
#include <string>
#include <vector>

class OrderBook
{
private:
    std::vector<OrderBookEntry> orders;

public:
    OrderBook(std::string filename);

    std::vector<std::string> getKnownProducts();

    std::vector<OrderBookEntry> getOrders(OrderBookType type,
                                          std::string product,
                                          std::string timestamp);

    static double getHighPrice(std::vector<OrderBookEntry> &orders);

    static double getLowPrice(std::vector<OrderBookEntry> &orders);
};