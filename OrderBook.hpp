#pragma once

#include <map>
#include <unordered_map>
#include "Order.hpp"
#include <vector>
#include <boost/uuid/uuid.hpp>

using order_sptr = std::shared_ptr<Order>;

class OrderBook
{
private:
	//bids and asks are mapped by price
	std::map<double, std::vector<order_sptr>, std::greater<double>> bids;
	std::map<double, std::vector<order_sptr>> asks;

	//one order mapped by uuid
	std::unordered_map<order_id, order_sptr> orderIndex;

public:
	double bestBid() const;
	double bestAsk() const;
	void addOrder(const Order& order);
	void print();
};

