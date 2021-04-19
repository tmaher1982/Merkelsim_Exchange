#include <iostream>
#include <cstdlib>

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
    
    while(true)
    {
        printMenu();
        int userOption = getUserOption();
        processUserOption(userOption);
    }

    return 0;
}