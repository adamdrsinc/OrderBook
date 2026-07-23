#include <iostream>
#include "OrderBook.hpp"
#include "OrderModelling.hpp"
#include <algorithm>
#include <boost/uuid/uuid_io.hpp>

double OrderBook::bestBid() const {
	return bids.empty() ? 0.0 : bids.begin()->first;
}

double OrderBook::bestAsk() const {
	return asks.empty() ? 0.0 : asks.begin()->first;
}

void OrderBook::addOrder(const Order& order) {
	auto shared_order = std::make_shared<Order>(order);

	orderIndex[shared_order->id] = shared_order;

	if (shared_order->isBuyOrder == Side::Bid) { 
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
	std::cout << "Bids:\n" << std::endl;
	for (const auto& [price, orders] : bids) {
		auto sorted = orders;

		std::cout << std::format("Orders at price {}\n----------------------\n", price) << std::endl;
		std::sort(sorted.begin(), sorted.end(), [](order_sptr a, order_sptr b) {return a->timestamp < b->timestamp;});

		for (const auto& order : sorted) {
			std::cout << std::format("id: {}, quantity: {}\n", boost::uuids::to_string(order->id), order->quantity);
		}

		std::cout << std::endl;
	}

	std::cout << "--------------------------------------\n\nAsks:\n" << std::endl;
	for (const auto& [price, orders] : asks) {
		auto sorted = orders;

		std::cout << std::format("Orders at price {}\n----------------------\n", price);
		std::sort(sorted.begin(), sorted.end(), [](order_sptr a, order_sptr b) {return a->timestamp < b->timestamp;});

		for (const auto& order : sorted) {
			std::cout << std::format("id: {}, quantity: {}\n", boost::uuids::to_string(order->id), order->quantity);
		}

		std::cout << std::endl;
	}
}