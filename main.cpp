#include <iostream>
#include "OrderBook.hpp"
#include "Order.hpp"
#include "ctime"

int main()
{
	OrderBook order_book = OrderBook();

	std::time_t t = std::time(0);
	auto order1 = Order::create(120.5, 2, Side::Bid, t);
	auto order2 = Order::create(130.5, 3, Side::Bid, t);
	auto order3 = Order::create(130.5, 4, Side::Bid, t);
	auto order4 = Order::create(110.5, 1, Side::Ask, t);
	auto order5 = Order::create(155.5, 4, Side::Ask, t);

	order_book.addOrder(order1);
	order_book.addOrder(order2);
	order_book.addOrder(order3);
	order_book.addOrder(order4);
	order_book.addOrder(order5);

	order_book.print();
}