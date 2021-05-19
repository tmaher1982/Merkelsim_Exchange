#include "MerkelMain.h"
#include <iostream>
#include <vector>
#include "OrderBookEntry.h"
#include "CSVReader.h"

MerkelMain::MerkelMain()
{

}

void MerkelMain::init()
{

    int input;
    while(true)
    {   
        printMenu();
        input = getUserOption();
        processUserOption(input);
    }
}



void MerkelMain::printMenu()
{
    // 1 print help
    std::cout << "1: Print help " << std::endl;

    // 2 print exchange stats
    std::cout << "2: Print exchange stats " << std::endl;

    // 3 make an offer
    std::cout << "3: Make an offer " << std::endl;

    // 4 make a bid
    std::cout << "4: Make a bid " << std::endl;

    // 5 print wallet
    std::cout << "5: Print Wallet " << std::endl;

    // 6 continue
    std::cout << "6: Continue " << std::endl;

    // 7 exit
    std::cout << "7: Exit " << std::endl;

    std::cout << "=============== " << std::endl;
    // std::cout << "Type in 1-7 " << std::endl;   
}

void MerkelMain::printHelp()
{
    std::cout << "Your aim is to make money. Analyse the market and make bids and offers." << std::endl;
}

void MerkelMain::printMarketStats()
{
    // std::cout << "OrderBook contains: " << orders.size() << " entries" << std::endl;
    // unsigned int bids = 0;
    // unsigned int asks = 0;
    // for (OrderBookEntry& e : orders)
    // {
    //     if (e.orderType == OrderBookType::ask)
    //     {
    //         asks ++;
    //     }
    //     if (e.orderType == OrderBookType::bid)
    //     {
    //         bids ++;
    //     }
    // }

    // std::cout << "OrderBook asks : " << asks << " bids : " << bids << std::endl;

}

void MerkelMain::enterOffer()
{
    std::cout << "Make an offer - enter the amount" << std::endl;
}

void MerkelMain::enterBid()
{
    std::cout << "Make a bid - enter the amount" << std::endl;
}

void MerkelMain::printWallet()
{
    std::cout << "Your wallet is emply. " << std::endl;
}

void MerkelMain::gotoNextTimeframe()
{
    std::cout << "Going to next time frame.." << std::endl;
}

void MerkelMain::exitMenu()
{
    std::cout << "Exit.." << std::endl;
    exit(0);
}

void MerkelMain::handleOtherOptions()
{
    std::cout << "Enter a valid number 1 - 7 " << std::endl;
}

int MerkelMain::getUserOption() {
    int userOption;

    std::cout << "Type in 1 - 7 " << std::endl;
    std::cin >> userOption;
    std::cout << "You chose: " << userOption << std::endl;

    return userOption;
}

void MerkelMain::processUserOption (int userOption)
{
    if (userOption == 0) // bad input
    {
        std::cout << "Invalid choice. Choose 1 - 6" << std::endl;
    }

    if (userOption == 1) // bad input
    {
        printHelp();
    }

    if (userOption == 2) // bad input
    {
        printMarketStats();
    }

    if (userOption == 3) // bad input
    {
        enterOffer();
    }

    if (userOption == 4) // bad input
    {
        enterBid();
        
    }

    if (userOption == 5) // bad input
    {
        printWallet();   
    }

    if (userOption == 6) // bad input
    {
        gotoNextTimeframe();
    }

    if (userOption == 7)
    {
        exitMenu();
    }

    if (userOption > 7 || userOption < 1)
    {
        handleOtherOptions();
    }
}
