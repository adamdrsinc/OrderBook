#include <iostream>
#include "OrderBook.hpp"
#include "OrderModelling.hpp"

double OrderBook::bestBid() const {
	return bids.empty() ? 0.0 : bids.begin()->first;
}

double OrderBook::bestAsk() const {
	return asks.empty() ? 0.0 : asks.begin()->first;
}

void OrderBook::addOrder(const Order& order) {
	auto shared_order = std::make_shared<Order>(order);

	orderIndex[shared_order->id] = shared_order;

	if (shared_order->isBuyOrder) { 
		// Add to bids
		auto& bids_bucket = bids[shared_order->price];
		bids_bucket.push_back(shared_order);
	}
	else { 
		// Add to asks
		auto& asks_bucket = asks[shared_order->price];
		asks_bucket.push_back(shared_order);
	}
}

void OrderBook::print() {

}