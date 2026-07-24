#include "Order.hpp"

Order Order::create(double price, double quantity, Side isBuyOrder, time_t timestamp) {
    return Order(Order::generate_order_id(), price, quantity, isBuyOrder, timestamp);
}
Order Order::fromExisting(order_id id, double price, double quantity, Side isBuyOrder, time_t timestamp) {
    return Order(id, price, quantity, isBuyOrder, timestamp);
}