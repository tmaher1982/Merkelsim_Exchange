#pragma once

#include <vector>
#include "OrderBookEntry.h"
#include "OrderBook.h"
#include "Wallet.h"

class MerkelMain
{
    public: 
        MerkelMain();
        /** Call this to start the sim */
        void init();
        
    private:  
        void printMenu();
        void printHelp();
        void printMarketStats();
        void enterAsk();
        void enterBid();
        void printWallet();
        void gotoNextTimeframe();
        void exitMenu();
        void handleOtherOptions();
        int getUserOption();
        void processUserOption (int userOption);

        std::string currentTime;
        
        //OrderBook OrderBook{"20200317.csv"};
        OrderBook OrderBook{"test.csv"};

        Wallet wallet;
        
        
};