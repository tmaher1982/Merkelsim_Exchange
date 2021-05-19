#include "OrderBook.h"
#include "CSVReader.h"


/** The OrderBook class presents a high level interface on all the orders in the order book data set, including query functions to find out which products are in the data set, and to retrieve a subset of the orders using filters.
*/

/** construct, reading a csv data file */
OrderBook::OrderBook(std::string filename)
{
    orders = CSVReader::readCSV(filename);
}
/** return vector of all known products in the dataset */
std::vector<std::string> OrderBook::getKnowProducts()
{
    std::vector<std::string> products;
    return products;
}
/** return vector of orders according to the sent filters */
std::vector<OrderBookEntry> OrderBook::getOrders(OrderBookType type,
                                        std::string product, 
                                        std::string timestamp)
{
    std::vector<OrderBookEntry> orders_sub;
    return orders_sub;
}
