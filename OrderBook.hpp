#pragma once

#include <map>
#include <unordered_map>
#include "OrderModelling.hpp"
#include <vector>

class OrderBook
{
private:
	std::map<double, std::vector<std::shared_ptr<Order>>, std::greater<double>> bids;
	std::map<double, std::vector<std::shared_ptr<Order>>> asks;
	std::unordered_map<uint64_t, std::shared_ptr<Order>> orderIndex;

public:
	double bestBid() const;
	double bestAsk() const;
	void addOrder(const Order& order);
};

