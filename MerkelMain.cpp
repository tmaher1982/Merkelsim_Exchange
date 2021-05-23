#include "MerkelMain.h"
#include <iostream>
#include <vector>
#include "OrderBookEntry.h"
#include "CSVReader.h"

/** The MerkelMain class represents the application itself, and it deals with user input and menu printing. */

MerkelMain::MerkelMain()
{

}

void MerkelMain::init()
{

    int input;
    currentTime = OrderBook.getEarliestTime();
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

    std::cout << "Current time is: " << currentTime << std::endl;
}

void MerkelMain::printHelp()
{
    std::cout << "Your aim is to make money. Analyse the market and make bids and offers." << std::endl;
}

void MerkelMain::printMarketStats()
{
    for (std::string const& p : OrderBook.getKnowProducts())
    {
        std::cout << "Product: " << p << std::endl;
        std::vector<OrderBookEntry> entries = OrderBook.getOrders(OrderBookType::ask, 
                                                      p,currentTime);
        std::cout <<"Asks seen: " << entries.size() << std::endl;
        std::cout << "Max ask:: " << OrderBook::getHighPrice(entries) << std::endl;
        std::cout << "Min ask:: " << OrderBook::getLowPrice(entries) << std::endl;
                                                                        
    }


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

void MerkelMain::enterAsk()
{
    std::cout << "Make an ask - enter the amount: product, price, amount, eg ETH/BTC,200,0.5" << std::endl;
    std::string input;
    
    //std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::getline(std::cin, input);

    std::vector<std::string> tokens = CSVReader::tokenise(input, ',');
    if (tokens.size() != 3)
    {
        std::cout << "MerketlMain::enterAsk Bad Input! " << input << std::endl;   
    }
    else {
        try {
            OrderBookEntry obe = CSVReader::stringsToOBE(
                tokens[1],
                tokens[2],
                currentTime, 
                tokens[0],
                OrderBookType::ask
            );
            OrderBook.insertOrder(obe);
        } catch (const std::exception& e)
        {
            std::cout << "MerkelMain::enterAsk Bad input " << std::endl;
        }
    }


    std::cout << "You typed: " << input << std::endl;

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
    std::vector<OrderBookEntry> sales = OrderBook.matchAsksToBids("ETH/BTC", currentTime);
    std::cout << "Sales: " << sales.size() << std::endl;
    for (OrderBookEntry& sale: sales)
    {
        std::cout << "Sale price: " << sale.price << " amount " << sale.amount << std::endl; 
    }
    currentTime = OrderBook.getNextTime(currentTime);
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
    int userOption = 0;
    std::string line;
    std::cout << "Type in 1 - 7 " << std::endl;
    std::getline(std::cin, line);
    try {
        userOption = std::stoi(line);    
    }
    catch(const std::exception& e)
    {
        // 
    }
    

    //std::cin >> userOption;
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
        enterAsk();
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
