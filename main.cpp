#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>

enum class OrderBookType{bid, ask};

class OrderBookEntry
{
    public: 
        double price;
        double amount;
        std::string timestamp;
        std::string product;
        OrderBookType orderType;

};


void printMenu()
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

void printHelp()
{
    std::cout << "Your aim is to make money. Analyse the market and make bids and offers." << std::endl;
}

void printMarketStats()
{
    std::cout << "Market looks good" << std::endl;
}

void enterOffer()
{
    std::cout << "Make an offer - enter the amount" << std::endl;
}

void enterBid()
{
    std::cout << "Make a bid - enter the amount" << std::endl;
}

void printWallet()
{
    std::cout << "Your wallet is emply. " << std::endl;
}

void gotoNextTimeframe()
{
    std::cout << "Going to next time frame.." << std::endl;
}

void exitMenu()
{
    std::cout << "Exit.." << std::endl;
    exit(0);
}

void handleOtherOptions()
{
    std::cout << "Enter a valid number 1 - 7 " << std::endl;
}

int getUserOption() {
    int userOption;

    std::cout << "Type in 1 - 7 " << std::endl;
    std::cin >> userOption;
    std::cout << "You chose: " << userOption << std::endl;

    return userOption;
}

void processUserOption (int userOption)
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

int main()
{
    

    // double price = 5319.450228;
    // double amount = 0.00020075;
    // std::string timestamp{"2020/03/17 17:01:24.884492"};
    // std::string product{"BTC/USDT"};
    // OrderBookType orderType = OrderBookType::ask;

    // std::vector<double> prices;
    // std::vector<double> amounts;
    // std::vector<std::string> timestamps;
    // std::vector<std::string> products;
    // std::vector<OrderBookType> orderTypes;

    // prices.push_back(5000.01);
    // amounts.push_back(0.001);
    // timestamps.push_back("2020/03/17 17:01:24.884492");
    // products.push_back("BTC/USDT");
    // orderTypes.push_back(OrderBookType::bid);

    // prices.push_back(10.01);
    // amounts.push_back(0.001);
    // timestamps.push_back("2020/03/17 17:01:24.884492");
    // products.push_back("BTC/USDT");
    // orderTypes.push_back(OrderBookType::ask);

    // std::cout << "prices: " << prices[0] << std::endl;
    // std::cout << "prices: " << prices[1] << std::endl;
    



    // while(true)
    // {
    //     printMenu();
    //     int userOption = getUserOption();
    //     processUserOption(userOption);
    // }

    // return 0;

    OrderBookEntry order1;

    order1.price = 10000;
    order1.amount = 10000;
    order1.timestamp = "2020/03/17 17:01:24.884492";
    order1.product = "BTC/USDT";
    order1.orderType = OrderBookType::bid;

    std::cout << "The price is " << order1.price << std::endl;

}