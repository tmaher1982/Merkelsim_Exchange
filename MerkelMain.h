

class MerkelMain
{
    public: 
        MerkelMain();
        void init();
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
};