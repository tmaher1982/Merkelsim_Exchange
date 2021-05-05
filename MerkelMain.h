

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
};