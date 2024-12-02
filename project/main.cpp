#include <iostream>
#include <vector>
#include <algorithm>

#include "orderbookentry.h"
#include "MerkelMain.h"

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


std::vector<std::string> tokenise(std::string csvLine, char separator) {
    std::vector<std::string> tokens;

    signed int start, end;
    std::string token;

    start = csvLine.find_first_not_of(separator, 0);

    do
    {
        end = csvLine.find_first_of(separator, start);

        if (start == csvLine.length() || start == end)    
        {
            break;
        } 

        if (end >= 0)
        {
            token = csvLine.substr(start, end - start);
        }
        else
        {
            token = csvLine.substr(start, csvLine.length() - start);
        }

        start = end + 1;

        tokens.push_back(token);
    } while (end > 0);

    return tokens;
}

int main(int argc, char *argv[]) {

    std::string csvLine = "thing1,thing2,thing3";

    std::vector<std::string> tokens = tokenise(csvLine, ',');

    for (size_t i = 0; i < tokens.size(); i++)
    {
        std::cout << tokens[i] << std::endl;
    }

    MerkelMain app{};
    app.init();
    return 0;
}