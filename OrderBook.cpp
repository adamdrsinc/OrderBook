#include <iostream>
#include "OrderBook.hpp"
#include "OrderModelling.hpp"

double OrderBook::bestBid() const {
	return bids.empty() ? 0.0 : bids.begin()->first;
}

double OrderBook::bestAsk() const {
	return asks.empty() ? 0.0 : asks.begin()->first;
}