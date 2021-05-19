#pragma once

#include <vector>
#include "OrderBookEntry.h"
#include "OrderBook.h"

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
        void enterOffer();
        void enterBid();
        void printWallet();
        void gotoNextTimeframe();
        void exitMenu();
        void handleOtherOptions();
        int getUserOption();
        void processUserOption (int userOption);

        OrderBook OrderBook{"2020317.csv"};
        
};