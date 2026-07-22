#pragma once

#include <cstdint>
#include <ctime>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>

struct Order{
    boost::uuids::uuid id;
    double price;
    double quantity;
    bool isBuyOrder;
    time_t timestamp;

    Order(double price,
        double quantity,
        bool isBuyOrder,
        std::time_t timestamp)
        :price(price),
        quantity(quantity),
        isBuyOrder(isBuyOrder),
        timestamp(timestamp)
    {
        id = boost::uuids::random_generator()();
    }

    Order(boost::uuids::uuid id,
        double price,
        double quantity,
        bool isBuyOrder,
        std::time_t timestamp)
        : id(id),
        price(price),
        quantity(quantity),
        isBuyOrder(isBuyOrder),
        timestamp(timestamp)
    {
    }
};

// Will use this later to cache aggregate data for each price level in the order book
/*struct PriceLevel {
	double price;
	double totalQuantity;
};*/