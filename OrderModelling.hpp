#pragma once

#include <cstdint>
#include <ctime>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>

using order_id = boost::uuids::uuid;

enum class Side {Bid, Ask};

class Order{
public:
    order_id id;
    double price;
    double quantity;
    Side isBuyOrder;
    time_t timestamp;

    static Order create(double price, double quantity, Side isBuyOrder, time_t timestamp) {
        return Order(generate_order_id(), price, quantity, isBuyOrder, timestamp);
    }
    static Order fromExisting(order_id id, double price, double quantity, Side isBuyOrder, time_t timestamp) {
        return Order(id, price, quantity, isBuyOrder, timestamp);
    }

private:
    static order_id generate_order_id() {
        static boost::uuids::random_generator gen;
        return gen();
    }

    Order(order_id id, double price, double quantity, Side isBuyOrder, time_t timestamp) : id(id), price(price), quantity(quantity), isBuyOrder(isBuyOrder), timestamp(timestamp) {};
};

// Will use this later to cache aggregate data for each price level in the order book
/*struct PriceLevel {
	double price;
	double totalQuantity;
};*/