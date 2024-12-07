#include "MerkelMain.h"
#include "CsvReader.h"

#include <vector>
#include <string>
#include <iostream>

void MerkelMain::printMenu()
{
    std::cout << "1: Print help" << std::endl;
    std::cout << "2: Print exchange stats" << std::endl;
    std::cout << "3: Place an ask" << std::endl;
    std::cout << "4: Place a bid" << std::endl;
    std::cout << "5: Print wallet" << std::endl;
    std::cout << "6: Continue" << std::endl;
}

int MerkelMain::getUserOption()
{
    int option;
    std::cout << "Type in 1-6" << std::endl;
    std::cin >> option;
    return option;
}

void MerkelMain::printHelp()
{
    std::cout << "Help - choose options from the menu" << std::endl;
    std::cout << "and follow the on screen instructions" << std::endl;
}

void MerkelMain::printMarketStats()
{

    int bids = 0;
    int asks = 0;
    for (size_t i = 0; i < orders.size(); i++)
    {
        if (orders[i].type == OrderBookType::bid)
        {
            bids++;
        }
        else if (orders[i].type == OrderBookType::ask)
        {
            asks++;
        }
    }
    
    std::cout << "Bids: " << bids << std::endl;
    std::cout << "Asks: " << asks << std::endl;
}

void MerkelMain::enterOffer()
{
    std::cout << "Make an offer" << std::endl;
}

void MerkelMain::enterBid()
{
    std::cout << "Make a bid" << std::endl;
}

void MerkelMain::printWallet()
{
    std::cout << "Some amount of money" << std::endl;
}

void MerkelMain::gotoNextTimeFrame()
{
    std::cout << "Doing financial things in the background" << std::endl;
}

void MerkelMain::processUserOption(int userOption)
{
    switch (userOption)
    {
    case 1:
        printHelp();
        break;
    case 2:
        printMarketStats();
        break;
    case 3:
        enterOffer();
        break;
    case 4:
        enterBid();
        break;
    case 5:
        printWallet();
        break;
    case 6:
        gotoNextTimeFrame();
        break;
    default:
        std::cout << "Invalid choice. Choose 1-6" << std::endl;
        break;
    }
}

void MerkelMain::loadOrderBook() {
    orders = CsvReader::readCSV("20200317.csv");
}

void MerkelMain::init(){
    loadOrderBook();
    int input;
    while (true)
    {
        printMenu();
        input = getUserOption();
        processUserOption(input);
    }
}