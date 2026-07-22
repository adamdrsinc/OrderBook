#pragma once

#include <map>
#include "OrderModelling.hpp"
#include <vector>

class OrderBook
{
	std::map<double, std::vector<Order>, std::greater<double>> bids;
	std::map<double, std::vector<Order>, std::less<double>> asks;
};

