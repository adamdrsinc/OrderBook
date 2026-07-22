#pragma once

#include <cstdint>
#include <ctime>

struct Order{
    std::uint64_t id;
    double price;
    double quantity;
    bool isBuyOrder;
    time_t timestamp;

    Order(std::uint64_t id,
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