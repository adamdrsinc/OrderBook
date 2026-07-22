#include <cstdint>;

using ui64 = std::uint64_t;

struct Order {
	ui64 id;
	double price;
	double quantity;
	bool isBuyOrder;
};

struct PriceLevel {
	double price;
	double totalQuantity;
};