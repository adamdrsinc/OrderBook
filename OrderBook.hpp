#pragma once

#include <map>
#include <unordered_map>
#include "OrderModelling.hpp"
#include <vector>
#include <boost/uuid/uuid.hpp>

class OrderBook
{
private:
	//bids and asks are mapped by price
	std::map<double, std::vector<std::shared_ptr<Order>>, std::greater<double>> bids;
	std::map<double, std::vector<std::shared_ptr<Order>>> asks;

	//one order mapped by uuid
	std::unordered_map<boost::uuids::uuid, std::shared_ptr<Order>> orderIndex;

public:
	double bestBid() const;
	double bestAsk() const;
	void addOrder(const Order& order);
};

