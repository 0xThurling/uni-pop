#pragma once

#include <string>
#include <vector>

#include "orderbookentry.h"

class CsvReader
{
    private:
        static std::vector<std::string> tokenise(std::string csvLine, char separator);
        static OrderBookEntry stringToOBE(std::vector<std::string> tokens);

    public:
        CsvReader();

        static std::vector<OrderBookEntry> readCSV(std::string fileName);
};
