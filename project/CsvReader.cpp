#include "CsvReader.h"
#include <string>
#include <vector>
#include <iostream>

#include <fstream>

#include "orderbookentry.h"

CsvReader::CsvReader() {}

std::vector<OrderBookEntry> CsvReader::readCSV(std::string filename) {
    std::vector<OrderBookEntry> entries;

    std::string csvFilename{filename};

    std::ifstream csvFile {csvFilename};
    
    if (csvFile.is_open())
    {
        std::cout << "Opened file " << csvFilename << std::endl;
    }
    else
    {
        std::cout << "Problem opening file " << csvFilename << std::endl;
    }

    std::string line;
    while (std::getline(csvFile, line))
    {
        try
        {
            std::vector<std::string> tokens = tokenise(line, ',');
            entries.push_back(stringToOBE(tokens));
        }
        catch(const std::exception& e)
        {
            std::cout << "Bad Line: " << std::endl;
            continue;
        }
    }

    csvFile.close();
    return entries;
}

std::vector<std::string> CsvReader::tokenise(std::string csvLine, char separator){
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

OrderBookEntry CsvReader::stringToOBE(std::vector<std::string> tokens)
{
    if (tokens.size() != 5)
    {
        throw std::exception();
    }
    try
    {
        double price = std::stod(tokens[3]);
        double amount = std::stod(tokens[4]);
        std::string timestamp = tokens[0];
        std::string product = tokens[1];
        OrderBookType type = OrderBookEntry::stringToOrderBookType(tokens[2]);
        OrderBookEntry entry{
            price,
            amount,
            timestamp,
            product,
            type};
        return entry;
    }
    catch(const std::exception& e)
    {
        std::cout << "Error" << std::endl;
    }
}