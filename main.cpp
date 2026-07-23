#include <iostream>
#include "OrderBook.hpp"
#include "OrderModelling.hpp"
#include "ctime"

Order makeFakeOrder(double price,
	double quantity,
	bool isBuyOrder,
	std::time_t timestamp) {

	return Order(price, quantity, isBuyOrder, timestamp);
}

int main()
{
	OrderBook order_book = OrderBook();

	std::time_t t = std::time(0);
	auto order1 = makeFakeOrder(120.5, 2, true, t);
	auto order2 = makeFakeOrder(130.5, 3, true, t);
	auto order3 = makeFakeOrder(130.5, 4, true, t);
	auto order4 = makeFakeOrder(110.5, 1, false, t);
	auto order5 = makeFakeOrder(155.5, 4, false, t);

	order_book.addOrder(order1);
	order_book.addOrder(order2);
	order_book.addOrder(order3);
	order_book.addOrder(order4);
	order_book.addOrder(order5);
}