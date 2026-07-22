
#include <iostream>
#include "OrderBook.hpp"
#include "OrderModelling.hpp"
#include <algorithm>
#include <format>

void printByPrice(std::vector<Order> orders) {
	sort(orders.begin(), orders.end(), [](const Order& a, const Order& b) {return a.price > b.price;});

	for (const auto& order : orders) {
		std::cout << std::format("Order {}\nprice: {}\nquantity: {}, buy order: {}\ntimestamp: {}\n", 
			order.id, order.price, order.quantity, order.isBuyOrder, order.timestamp) << std::endl;
	}
}

int main()
{
	time_t timestamp;
	time(&timestamp);
	Order order1 = { 1, 12.4, 2, true, timestamp };
	time(&timestamp);
	Order order2 = { 2, 13.6, 3, true, timestamp };
	time(&timestamp);
	Order order3 = { 3, 11.2, 2, true, timestamp };

	std::vector<Order> orders = { order1, order2, order3 };

	printByPrice(orders);
}