/*!
    \file matching.cpp
    \brief Matching engine performance with custom inputs
    \author Apostolis Kasselouris
    \date 27.04.2021
    \copyright MIT License
*/

#include "trader/matching/market_manager.h"

#include "system/stream.h"
#include "time/timestamp.h"
#include "benchmark/reporter_console.h"

#include <iostream>
#include <regex>
#include <string>

using namespace CppTrader::Matching;

class MyMarketHandler : public MarketHandler
{
public:
    MyMarketHandler()
        : _updates(0),
          _symbols(0),
          _max_symbols(0),
          _order_books(0),
          _max_order_books(0),
          _max_order_book_levels(0),
          _max_order_book_orders(0),
          _orders(0),
          _max_orders(0),
          _add_orders(0),
          _update_orders(0),
          _delete_orders(0),
          _execute_orders(0),
          _total_messages(0)
    {}

    size_t updates() const { return _updates; }
    size_t max_symbols() const { return _max_symbols; }
    size_t max_order_books() const { return _max_order_books; }
    size_t max_order_book_levels() const { return _max_order_book_levels; }
    size_t max_order_book_orders() const { return _max_order_book_orders; }
    size_t max_orders() const { return _max_orders; }
    size_t add_orders() const { return _add_orders; }
    size_t update_orders() const { return _update_orders; }
    size_t delete_orders() const { return _delete_orders; }
    size_t execute_orders() const { return _execute_orders; }
    size_t total_messages() const { return _total_messages; }

protected:
    void onAddSymbol(const Symbol& symbol) override { ++_updates; ++_symbols; _max_symbols = std::max(_symbols, _max_symbols); ++_total_messages; }
    void onDeleteSymbol(const Symbol& symbol) override { ++_updates; --_symbols; ++_total_messages; }
    void onAddOrderBook(const OrderBook& order_book) override { ++_updates; ++_order_books; _max_order_books = std::max(_order_books, _max_order_books); ++_total_messages; }
    void onUpdateOrderBook(const OrderBook& order_book, bool top) override { _max_order_book_levels = std::max(std::max(order_book.bids().size(), order_book.asks().size()), _max_order_book_levels); }
    void onDeleteOrderBook(const OrderBook& order_book) override { ++_updates; --_order_books; ++_total_messages; }
    void onAddLevel(const OrderBook& order_book, const Level& level, bool top) override { ++_updates; }
    void onUpdateLevel(const OrderBook& order_book, const Level& level, bool top) override { ++_updates; _max_order_book_orders = std::max(level.Orders, _max_order_book_orders); }
    void onDeleteLevel(const OrderBook& order_book, const Level& level, bool top) override { ++_updates; }
    void onAddOrder(const Order& order) override { ++_updates; ++_orders; _max_orders = std::max(_orders, _max_orders); ++_add_orders; ++_total_messages; }
    void onUpdateOrder(const Order& order) override { ++_updates; ++_update_orders; }
    void onDeleteOrder(const Order& order) override { ++_updates; --_orders; ++_delete_orders; }
    void onExecuteOrder(const Order& order, uint64_t price, uint64_t quantity) override { ++_updates; ++_execute_orders; }

private:
    size_t _updates;
    size_t _symbols;
    size_t _max_symbols;
    size_t _order_books;
    size_t _max_order_books;
    size_t _max_order_book_levels;
    size_t _max_order_book_orders;
    size_t _orders;
    size_t _max_orders;
    size_t _add_orders;
    size_t _update_orders;
    size_t _delete_orders;
    size_t _execute_orders;
    size_t _total_messages;
};

void AddSymbol(MarketManager& market, const std::string& command)
{
    static std::regex pattern("^add symbol (\\d+) (.+)$");
    std::smatch match;

    if (std::regex_search(command, match, pattern))
    {
        uint32_t id = std::stoi(match[1]);

        char name[8];
        std::string sname = match[2];
        std::memcpy(name, sname.data(), std::min(sname.size(), sizeof(name)));

        Symbol symbol(id, name);

        ErrorCode result = market.AddSymbol(symbol);
        if (result != ErrorCode::OK)
            std::cerr << "Failed 'add symbol' command: " << result << std::endl;

        return;
    }

    std::cerr << "Invalid 'add symbol' command: " << command << std::endl;
}

void DeleteSymbol(MarketManager& market, const std::string& command)
{
    static std::regex pattern("^delete symbol (\\d+)$");
    std::smatch match;

    if (std::regex_search(command, match, pattern))
    {
        uint32_t id = std::stoi(match[1]);

        ErrorCode result = market.DeleteSymbol(id);
        if (result != ErrorCode::OK)
            std::cerr << "Failed 'delete symbol' command: " << result << std::endl;

        return;
    }

    std::cerr << "Invalid 'delete symbol' command: " << command << std::endl;
}

void AddOrderBook(MarketManager& market, const std::string& command)
{
    static std::regex pattern("^add book (\\d+)$");
    std::smatch match;

    if (std::regex_search(command, match, pattern))
    {
        uint32_t id = std::stoi(match[1]);

        char name[8];
        std::memset(name, 0, sizeof(name));

        Symbol symbol(id, name);

        ErrorCode result = market.AddOrderBook(symbol);
        if (result != ErrorCode::OK)
            std::cerr << "Failed 'add book' command: " << result << std::endl;

        return;
    }

    std::cerr << "Invalid 'add book' command: " << command << std::endl;
}

void DeleteOrderBook(MarketManager& market, const std::string& command)
{
    static std::regex pattern("^delete book (\\d+)$");
    std::smatch match;

    if (std::regex_search(command, match, pattern))
    {
        uint32_t id = std::stoi(match[1]);

        ErrorCode result = market.DeleteOrderBook(id);
        if (result != ErrorCode::OK)
            std::cerr << "Failed 'delete book' command: " << result << std::endl;

        return;
    }

    std::cerr << "Invalid 'delete book' command: " << command << std::endl;
}

void AddMarketOrder(MarketManager& market, const std::string& command)
{
    static std::regex pattern("^add market (buy|sell) (\\d+) (\\d+) (\\d+)$");
    std::smatch match;

    if (std::regex_search(command, match, pattern))
    {
        uint64_t id = std::stoi(match[2]);
        uint32_t symbol_id = std::stoi(match[3]);
        uint64_t quantity = std::stoi(match[4]);

        Order order;
        if (match[1] == "buy")
            order = Order::BuyMarket(id, symbol_id, quantity);
        else if (match[1] == "sell")
            order = Order::SellMarket(id, symbol_id, quantity);
        else
        {
            std::cerr << "Invalid market order side: " << match[1] << std::endl;
            return;
        }

        ErrorCode result = market.AddOrder(order);
        if (result != ErrorCode::OK)
            std::cerr << "Failed 'add market' command: " << result << std::endl;

        return;
    }

    std::cerr << "Invalid 'add market' command: " << command << std::endl;
}

void AddSlippageMarketOrder(MarketManager& market, const std::string& command)
{
    static std::regex pattern("^add slippage market (buy|sell) (\\d+) (\\d+) (\\d+) (\\d+)$");
    std::smatch match;

    if (std::regex_search(command, match, pattern))
    {
        uint64_t id = std::stoi(match[2]);
        uint32_t symbol_id = std::stoi(match[3]);
        uint64_t quantity = std::stoi(match[4]);
        uint64_t slippage = std::stoi(match[5]);

        Order order;
        if (match[1] == "buy")
            order = Order::BuyMarket(id, symbol_id, quantity, slippage);
        else if (match[1] == "sell")
            order = Order::SellMarket(id, symbol_id, quantity, slippage);
        else
        {
            std::cerr << "Invalid market order side: " << match[1] << std::endl;
            return;
        }

        ErrorCode result = market.AddOrder(order);
        if (result != ErrorCode::OK)
            std::cerr << "Failed 'add slippage market' command: " << result << std::endl;

        return;
    }

    std::cerr << "Invalid 'add slippage market' command: " << command << std::endl;
}

void AddLimitOrder(MarketManager& market, const std::string& command)
{
    static std::regex pattern("^add limit (buy|sell) (\\d+) (\\d+) (\\d+) (\\d+)$");
    std::smatch match;

    if (std::regex_search(command, match, pattern))
    {
        uint64_t id = std::stoi(match[2]);
        uint32_t symbol_id = std::stoi(match[3]);
        uint64_t price = std::stoi(match[4]);
        uint64_t quantity = std::stoi(match[5]);

        Order order;
        if (match[1] == "buy")
            order = Order::BuyLimit(id, symbol_id, price, quantity);
        else if (match[1] == "sell")
            order = Order::SellLimit(id, symbol_id, price, quantity);
        else
        {
            std::cerr << "Invalid limit order side: " << match[1] << std::endl;
            return;
        }

        ErrorCode result = market.AddOrder(order);
        if (result != ErrorCode::OK)
            std::cerr << "Failed 'add limit' command: " << result << std::endl;

        return;
    }

    std::cerr << "Invalid 'add limit' command: " << command << std::endl;
}

void AddIOCLimitOrder(MarketManager& market, const std::string& command)
{
    static std::regex pattern("^add ioc limit (buy|sell) (\\d+) (\\d+) (\\d+) (\\d+)$");
    std::smatch match;

    if (std::regex_search(command, match, pattern))
    {
        uint64_t id = std::stoi(match[2]);
        uint32_t symbol_id = std::stoi(match[3]);
        uint64_t price = std::stoi(match[4]);
        uint64_t quantity = std::stoi(match[5]);

        Order order;
        if (match[1] == "buy")
            order = Order::BuyLimit(id, symbol_id, price, quantity, OrderTimeInForce::IOC);
        else if (match[1] == "sell")
            order = Order::SellLimit(id, symbol_id, price, quantity, OrderTimeInForce::IOC);
        else
        {
            std::cerr << "Invalid limit order side: " << match[1] << std::endl;
            return;
        }

        ErrorCode result = market.AddOrder(order);
        if (result != ErrorCode::OK)
            std::cerr << "Failed 'add ioc limit' command: " << result << std::endl;

        return;
    }

    std::cerr << "Invalid 'add ioc limit' command: " << command << std::endl;
}

void AddFOKLimitOrder(MarketManager& market, const std::string& command)
{
    static std::regex pattern("^add fok limit (buy|sell) (\\d+) (\\d+) (\\d+) (\\d+)$");
    std::smatch match;

    if (std::regex_search(command, match, pattern))
    {
        uint64_t id = std::stoi(match[2]);
        uint32_t symbol_id = std::stoi(match[3]);
        uint64_t price = std::stoi(match[4]);
        uint64_t quantity = std::stoi(match[5]);

        Order order;
        if (match[1] == "buy")
            order = Order::BuyLimit(id, symbol_id, price, quantity, OrderTimeInForce::FOK);
        else if (match[1] == "sell")
            order = Order::SellLimit(id, symbol_id, price, quantity, OrderTimeInForce::FOK);
        else
        {
            std::cerr << "Invalid limit order side: " << match[1] << std::endl;
            return;
        }

        ErrorCode result = market.AddOrder(order);
        if (result != ErrorCode::OK)
            std::cerr << "Failed 'add fok limit' command: " << result << std::endl;

        return;
    }

    std::cerr << "Invalid 'add fok limit' command: " << command << std::endl;
}

void AddAONLimitOrder(MarketManager& market, const std::string& command)
{
    static std::regex pattern("^add aon limit (buy|sell) (\\d+) (\\d+) (\\d+) (\\d+)$");
    std::smatch match;

    if (std::regex_search(command, match, pattern))
    {
        uint64_t id = std::stoi(match[2]);
        uint32_t symbol_id = std::stoi(match[3]);
        uint64_t price = std::stoi(match[4]);
        uint64_t quantity = std::stoi(match[5]);

        Order order;
        if (match[1] == "buy")
            order = Order::BuyLimit(id, symbol_id, price, quantity, OrderTimeInForce::AON);
        else if (match[1] == "sell")
            order = Order::SellLimit(id, symbol_id, price, quantity, OrderTimeInForce::AON);
        else
        {
            std::cerr << "Invalid limit order side: " << match[1] << std::endl;
            return;
        }

        ErrorCode result = market.AddOrder(order);
        if (result != ErrorCode::OK)
            std::cerr << "Failed 'add aon limit' command: " << result << std::endl;

        return;
    }

    std::cerr << "Invalid 'add aon limit' command: " << command << std::endl;
}

void AddStopOrder(MarketManager& market, const std::string& command)
{
    static std::regex pattern("^add stop (buy|sell) (\\d+) (\\d+) (\\d+) (\\d+)$");
    std::smatch match;

    if (std::regex_search(command, match, pattern))
    {
        uint64_t id = std::stoi(match[2]);
        uint32_t symbol_id = std::stoi(match[3]);
        uint64_t stop_price = std::stoi(match[4]);
        uint64_t quantity = std::stoi(match[5]);

        Order order;
        if (match[1] == "buy")
            order = Order::BuyStop(id, symbol_id, stop_price, quantity);
        else if (match[1] == "sell")
            order = Order::SellStop(id, symbol_id, stop_price, quantity);
        else
        {
            std::cerr << "Invalid stop order side: " << match[1] << std::endl;
            return;
        }

        ErrorCode result = market.AddOrder(order);
        if (result != ErrorCode::OK)
            std::cerr << "Failed 'add stop' command: " << result << std::endl;

        return;
    }

    std::cerr << "Invalid 'add stop' command: " << command << std::endl;
}

void AddStopLimitOrder(MarketManager& market, const std::string& command)
{
    static std::regex pattern("^add stop-limit (buy|sell) (\\d+) (\\d+) (\\d+) (\\d+) (\\d+)$");
    std::smatch match;

    if (std::regex_search(command, match, pattern))
    {
        uint64_t id = std::stoi(match[2]);
        uint32_t symbol_id = std::stoi(match[3]);
        uint64_t stop_price = std::stoi(match[4]);
        uint64_t price = std::stoi(match[5]);
        uint64_t quantity = std::stoi(match[6]);

        Order order;
        if (match[1] == "buy")
            order = Order::BuyStopLimit(id, symbol_id, stop_price, price, quantity);
        else if (match[1] == "sell")
            order = Order::SellStopLimit(id, symbol_id, stop_price, price, quantity);
        else
        {
            std::cerr << "Invalid stop-limit order side: " << match[1] << std::endl;
            return;
        }

        ErrorCode result = market.AddOrder(order);
        if (result != ErrorCode::OK)
            std::cerr << "Failed 'add stop-limit' command: " << result << std::endl;

        return;
    }

    std::cerr << "Invalid 'add stop-limit' command: " << command << std::endl;
}

void AddTrailingStopOrder(MarketManager& market, const std::string& command)
{
    static std::regex pattern("^add trailing stop (buy|sell) (\\d+) (\\d+) (\\d+) (\\d+) (\\d+) (\\d+)$");
    std::smatch match;

    if (std::regex_search(command, match, pattern))
    {
        uint64_t id = std::stoi(match[2]);
        uint32_t symbol_id = std::stoi(match[3]);
        uint64_t stop_price = std::stoi(match[4]);
        uint64_t quantity = std::stoi(match[5]);
        int64_t trailing_distance = std::stoi(match[6]);
        int64_t trailing_step = std::stoi(match[7]);

        Order order;
        if (match[1] == "buy")
            order = Order::TrailingBuyStop(id, symbol_id, stop_price, quantity, trailing_distance, trailing_step);
        else if (match[1] == "sell")
            order = Order::TrailingSellStop(id, symbol_id, stop_price, quantity, trailing_distance, trailing_step);
        else
        {
            std::cerr << "Invalid stop order side: " << match[1] << std::endl;
            return;
        }

        ErrorCode result = market.AddOrder(order);
        if (result != ErrorCode::OK)
            std::cerr << "Failed 'add trailing stop' command: " << result << std::endl;

        return;
    }

    std::cerr << "Invalid 'add trailing stop' command: " << command << std::endl;
}

void AddTrailingStopLimitOrder(MarketManager& market, const std::string& command)
{
    static std::regex pattern("^add trailing stop-limit (buy|sell) (\\d+) (\\d+) (\\d+) (\\d+) (\\d+) (\\d+) (\\d+)$");
    std::smatch match;

    if (std::regex_search(command, match, pattern))
    {
        uint64_t id = std::stoi(match[2]);
        uint32_t symbol_id = std::stoi(match[3]);
        uint64_t stop_price = std::stoi(match[4]);
        uint64_t price = std::stoi(match[5]);
        uint64_t quantity = std::stoi(match[6]);
        int64_t trailing_distance = std::stoi(match[7]);
        int64_t trailing_step = std::stoi(match[8]);

        Order order;
        if (match[1] == "buy")
            order = Order::TrailingBuyStopLimit(id, symbol_id, stop_price, price, quantity, trailing_distance, trailing_step);
        else if (match[1] == "sell")
            order = Order::TrailingSellStopLimit(id, symbol_id, stop_price, price, quantity, trailing_distance, trailing_step);
        else
        {
            std::cerr << "Invalid stop-limit order side: " << match[1] << std::endl;
            return;
        }

        ErrorCode result = market.AddOrder(order);
        if (result != ErrorCode::OK)
            std::cerr << "Failed 'add trailing stop-limit' command: " << result << std::endl;

        return;
    }

    std::cerr << "Invalid 'add trailing stop-limit' command: " << command << std::endl;
}

void ReduceOrder(MarketManager& market, const std::string& command)
{
    static std::regex pattern("^reduce order (\\d+) (\\d+)$");
    std::smatch match;

    if (std::regex_search(command, match, pattern))
    {
        uint64_t id = std::stoi(match[1]);
        uint64_t quantity = std::stoi(match[2]);

        ErrorCode result = market.ReduceOrder(id, quantity);
        if (result != ErrorCode::OK)
            std::cerr << "Failed 'reduce order' command: " << result << std::endl;

        return;
    }

    std::cerr << "Invalid 'reduce order' command: " << command << std::endl;
}

void ModifyOrder(MarketManager& market, const std::string& command)
{
    static std::regex pattern("^modify order (\\d+) (\\d+) (\\d+)$");
    std::smatch match;

    if (std::regex_search(command, match, pattern))
    {
        uint64_t id = std::stoi(match[1]);
        uint64_t new_price = std::stoi(match[2]);
        uint64_t new_quantity = std::stoi(match[3]);

        ErrorCode result = market.ModifyOrder(id, new_price, new_quantity);
        if (result != ErrorCode::OK)
            std::cerr << "Failed 'modify order' command: " << result << std::endl;

        return;
    }

    std::cerr << "Invalid 'modify order' command: " << command << std::endl;
}

void MitigateOrder(MarketManager& market, const std::string& command)
{
    static std::regex pattern("^mitigate order (\\d+) (\\d+) (\\d+)$");
    std::smatch match;

    if (std::regex_search(command, match, pattern))
    {
        uint64_t id = std::stoi(match[1]);
        uint64_t new_price = std::stoi(match[2]);
        uint64_t new_quantity = std::stoi(match[3]);

        ErrorCode result = market.MitigateOrder(id, new_price, new_quantity);
        if (result != ErrorCode::OK)
            std::cerr << "Failed 'mitigate order' command: " << result << std::endl;

        return;
    }

    std::cerr << "Invalid 'mitigate order' command: " << command << std::endl;
}

void ReplaceOrder(MarketManager& market, const std::string& command)
{
    static std::regex pattern("^replace order (\\d+) (\\d+) (\\d+) (\\d+)$");
    std::smatch match;

    if (std::regex_search(command, match, pattern))
    {
        uint64_t id = std::stoi(match[1]);
        uint64_t new_id = std::stoi(match[2]);
        uint64_t new_price = std::stoi(match[3]);
        uint64_t new_quantity = std::stoi(match[4]);

        ErrorCode result = market.ReplaceOrder(id, new_id, new_price, new_quantity);
        if (result != ErrorCode::OK)
            std::cerr << "Failed 'replace order' command: " << result << std::endl;

        return;
    }

    std::cerr << "Invalid 'replace order' command: " << command << std::endl;
}

void DeleteOrder(MarketManager& market, const std::string& command)
{
    static std::regex pattern("^delete order (\\d+)$");
    std::smatch match;

    if (std::regex_search(command, match, pattern))
    {
        uint64_t id = std::stoi(match[1]);

        ErrorCode result = market.DeleteOrder(id);
        if (result != ErrorCode::OK)
            std::cerr << "Failed 'delete order' command: " << result << std::endl;

        return;
    }

    std::cerr << "Invalid 'delete order' command: " << command << std::endl;
}

int main(int argc, char** argv)
{
    MyMarketHandler market_handler;
    MarketManager market(market_handler);

    uint64_t timestamp_start = CppCommon::Timestamp::nano();
    // Perform text input
    std::string line;
    while (getline(std::cin, line))
    {
        if (line == "help")
        {
            std::cout << "Supported commands: " << std::endl;
            std::cout << "add symbol {Id} {Name} - Add a new symbol with {Id} and {Name}" << std::endl;
            std::cout << "delete symbol {Id} - Delete the symbol with {Id}" << std::endl;
            std::cout << "add book {Id} - Add a new order book for the symbol with {Id}" << std::endl;
            std::cout << "delete book {Id} - Delete the order book with {Id}" << std::endl;
            std::cout << "add market {Side} {Id} {SymbolId} {Quantity} - Add a new market order of {Type} (buy/sell) with {Id}, {SymbolId} and {Quantity}" << std::endl;
            std::cout << "add slippage market {Side} {Id} {SymbolId} {Quantity} {Slippage} - Add a new slippage market order of {Type} (buy/sell) with {Id}, {SymbolId}, {Quantity} and {Slippage}" << std::endl;
            std::cout << "add limit {Side} {Id} {SymbolId} {Price} {Quantity} - Add a new limit order of {Type} (buy/sell) with {Id}, {SymbolId}, {Price} and {Quantity}" << std::endl;
            std::cout << "add ioc limit {Side} {Id} {SymbolId} {Price} {Quantity} - Add a new 'Immediate-Or-Cancel' limit order of {Type} (buy/sell) with {Id}, {SymbolId}, {Price} and {Quantity}" << std::endl;
            std::cout << "add fok limit {Side} {Id} {SymbolId} {Price} {Quantity} - Add a new 'Fill-Or-Kill' limit order of {Type} (buy/sell) with {Id}, {SymbolId}, {Price} and {Quantity}" << std::endl;
            std::cout << "add aon limit {Side} {Id} {SymbolId} {Price} {Quantity} - Add a new 'All-Or-None' limit order of {Type} (buy/sell) with {Id}, {SymbolId}, {Price} and {Quantity}" << std::endl;
            std::cout << "add stop {Side} {Id} {SymbolId} {StopPrice} {Quantity} - Add a new stop order of {Type} (buy/sell) with {Id}, {SymbolId}, {StopPrice} and {Quantity}" << std::endl;
            std::cout << "add stop-limit {Side} {Id} {SymbolId} {StopPrice} {Price} {Quantity} - Add a new stop-limit order of {Type} (buy/sell) with {Id}, {SymbolId}, {StopPrice}, {Price} and {Quantity}" << std::endl;
            std::cout << "add trailing stop {Side} {Id} {SymbolId} {StopPrice} {Quantity} {TrailingDistance} {TrailingStep} - Add a new trailing stop order of {Type} (buy/sell) with {Id}, {SymbolId}, {StopPrice}, {Quantity}, {TrailingDistance} and {TrailingStep}" << std::endl;
            std::cout << "add trailing stop-limit {Side} {Id} {SymbolId} {StopPrice} {Price} {Quantity} {TrailingDistance} {TrailingStep} - Add a new trailing stop-limit order of {Type} (buy/sell) with {Id}, {SymbolId}, {StopPrice}, {Price}, {Quantity}, {TrailingDistance} and {TrailingStep}" << std::endl;
            std::cout << "reduce order {Id} {Quantity} - Reduce the order with {Id} by the given {Quantity}" << std::endl;
            std::cout << "modify order {Id} {NewPrice} {NewQuantity} - Modify the order with {Id} and set {NewPrice} and {NewQuantity}" << std::endl;
            std::cout << "mitigate order {Id} {NewPrice} {NewQuantity} - Mitigate the order with {Id} and set {NewPrice} and {NewQuantity}" << std::endl;
            std::cout << "replace order {Id} {NewId} {NewPrice} {NewQuantity} - Replace the order with {Id} and set {NewId}, {NewPrice} and {NewQuantity}" << std::endl;
            std::cout << "delete order {Id} - Delete the order with {Id}" << std::endl;
            std::cout << "exit/quit - Exit the program" << std::endl;
        }
        else if ((line == "exit") || (line == "quit"))
            break;
        else if ((line.find("#") == 0) || (line == ""))
            continue;
        else if (line == "enable matching")
            market.EnableMatching();
        else if (line == "disable matching")
            market.DisableMatching();
        else if (line.find("add symbol") != std::string::npos)
            AddSymbol(market, line);
        else if (line.find("delete symbol") != std::string::npos)
            DeleteSymbol(market, line);
        else if (line.find("add book") != std::string::npos)
            AddOrderBook(market, line);
        else if (line.find("delete book") != std::string::npos)
            DeleteOrderBook(market, line);
        else if (line.find("add market") != std::string::npos)
            AddMarketOrder(market, line);
        else if (line.find("add slippage market") != std::string::npos)
            AddSlippageMarketOrder(market, line);
        else if (line.find("add limit") != std::string::npos)
            AddLimitOrder(market, line);
        else if (line.find("add ioc limit") != std::string::npos)
            AddIOCLimitOrder(market, line);
        else if (line.find("add fok limit") != std::string::npos)
            AddFOKLimitOrder(market, line);
        else if (line.find("add aon limit") != std::string::npos)
            AddAONLimitOrder(market, line);
        else if (line.find("add stop-limit") != std::string::npos)
            AddStopLimitOrder(market, line);
        else if (line.find("add stop") != std::string::npos)
            AddStopOrder(market, line);
        else if (line.find("add trailing stop-limit") != std::string::npos)
            AddTrailingStopLimitOrder(market, line);
        else if (line.find("add trailing stop") != std::string::npos)
            AddTrailingStopOrder(market, line);
        else if (line.find("reduce order") != std::string::npos)
            ReduceOrder(market, line);
        else if (line.find("modify order") != std::string::npos)
            ModifyOrder(market, line);
        else if (line.find("mitigate order") != std::string::npos)
            MitigateOrder(market, line);
        else if (line.find("replace order") != std::string::npos)
            ReplaceOrder(market, line);
        else if (line.find("delete order") != std::string::npos)
            DeleteOrder(market, line);
        else
            std::cerr << "Unknown command: "  << line << std::endl;
    }
    uint64_t timestamp_stop = CppCommon::Timestamp::nano();

    size_t total_messages = market_handler.total_messages();
    size_t total_updates = market_handler.updates();

    //Print results
    std::cout << "Processing time: " << CppBenchmark::ReporterConsole::GenerateTimePeriod(timestamp_stop - timestamp_start) << std::endl;
    std::cout << "Total messages: " << total_messages << std::endl;
    std::cout << "Message latency: " << CppBenchmark::ReporterConsole::GenerateTimePeriod((timestamp_stop - timestamp_start) / total_messages) << std::endl;
    std::cout << "Message throughput: " << total_messages * 1000000000 / (timestamp_stop - timestamp_start) << " msg/s" << std::endl;
    std::cout << "Total market updates: " << total_updates << std::endl;
    std::cout << "Market update latency: " << CppBenchmark::ReporterConsole::GenerateTimePeriod((timestamp_stop - timestamp_start) / total_updates) << std::endl;
    std::cout << "Market update throughput: " << total_updates * 1000000000 / (timestamp_stop - timestamp_start) << " upd/s" << std::endl;


    std::cout << std::endl;

    std::cout << "Market statistics: " << std::endl;
    std::cout << "Max symbols: " << market_handler.max_symbols() << std::endl;
    std::cout << "Max order books: " << market_handler.max_order_books() << std::endl;
    std::cout << "Max order book levels: " << market_handler.max_order_book_levels() << std::endl;
    std::cout << "Max order book orders: " << market_handler.max_order_book_orders() << std::endl;
    std::cout << "Max orders: " << market_handler.max_orders() << std::endl;

    std::cout << std::endl;

    std::cout << "Order statistics: " << std::endl;
    std::cout << "Add order operations: " << market_handler.add_orders() << std::endl;
    std::cout << "Update order operations: " << market_handler.update_orders() << std::endl;
    std::cout << "Delete order operations: " << market_handler.delete_orders() << std::endl;
    std::cout << "Execute order operations: " << market_handler.execute_orders() << std::endl;
    
    return 0;
}