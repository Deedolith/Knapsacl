#include <string>
#include <iostream>
#include <memory>
#include <algorithm>
#include <iomanip>

#include "Main.h"
#include "coordinates.h"

int main()
{
	std::vector<goldBar> storage;
	storage.push_back(goldBar{ "476479", "041000", 395.018f, "XXX-10" });
	storage.push_back(goldBar{ "476494", "041000", 392.826f, "XXX-10" });
	storage.push_back(goldBar{ "476495", "041000", 377.036f, "XXX-10" });
	storage.push_back(goldBar{ "476499", "041000", 392.951f, "XXX-10" });
	storage.push_back(goldBar{ "476500", "041000", 372.653f, "XXX-10" });
	storage.push_back(goldBar{ "476503", "041000", 392.901f, "XXX-10" });
	storage.push_back(goldBar{ "476504", "041000", 395.391f, "XXX-10" });
	storage.push_back(goldBar{ "476505", "041000", 394.342f, "XXX-10" });
	storage.push_back(goldBar{ "476562", "041000", 412.717f, "XXX-10" });
	storage.push_back(goldBar{ "476620", "041000", 390.841f, "XXX-10" });
	storage.push_back(goldBar{ "476621", "041000", 402.651f, "XXX-10" });
	size_t bagCapacity{ 1500 };

	//storage.push_back(goldBar{ "476479", "041000", 15.0f / 1000.0f, "XXX-10" });
	//storage.push_back(goldBar{ "476494", "041000", 12.0f / 1000.0f, "XXX-10" });
	//storage.push_back(goldBar{ "476495", "041000", 13.0f / 1000.0f, "XXX-10" });
	//size_t bagCapacity{ 25 };

	std::cout << "Max weight: " << bagCapacity << std::endl;
	{
		std::cout << "Knapsack_01:" << std::endl;
		auto onBoardItems = knapSack_01(bagCapacity * 1000, storage);
		std::cout << "items list:" << std::endl;
		float totalWeight{ 0.0f };
		for (auto const& item : onBoardItems)
		{
			std::cout << item.IDMAT() << std::endl;
			totalWeight += item.LBMAFOZ();
		}
		std::cout << "Total weight: " << totalWeight << std::endl;
	}
	std::cout << "------------------------------------------------" << std::endl;
	{
		std::cout << "Knapsack_greedy:" << std::endl;
		auto onBoardItems = knapSack_greedy(bagCapacity * 1000, storage);
		std::cout << "items list:" << std::endl;
		float totalWeight{ 0.0f };
		for (auto const& item : onBoardItems)
		{
			std::cout << item.IDMAT() << std::endl;
			totalWeight += item.LBMAFOZ();
		}
		std::cout << "Total weight: " << totalWeight << std::endl;
	}
	return EXIT_SUCCESS;
}

std::vector<goldBar> knapSack_01(size_t sackCapacity, std::vector<goldBar>& items)
{
	grid grid{ sackCapacity + 1, items.size() + 1 };

	for (size_t y{ 1 }; y <= items.size(); ++y)
	{
		for (size_t x{ 1 }; x <= sackCapacity; ++x)
		{
			if (items[y-1].weight() <= x)
				grid.set(coordinates(x, y), std::max(items[y - 1].weight() + grid[coordinates(x - items[y - 1].weight(), y - 1)], grid[coordinates(x, y - 1)]));
			else
				grid.set(coordinates(x, y), grid[coordinates(x, y - 1)]);
		}
	}
	return retrieveItems(grid, items);
}

std::vector<goldBar> retrieveItems(grid const& grid, std::vector<goldBar>& items)
{
	unsigned onboardWeight{ grid[coordinates(grid.width()-1, items.size())] };
	size_t x{ grid.width() - 1 };
	std::vector<goldBar> returnList;
	std::vector<size_t> indexsToRemove;
	for (size_t y{ items.size() }; y != static_cast<size_t>(-1); --y)
	{
		if (onboardWeight == grid[coordinates(x, y - 1)])
			continue;
		else
		{
			onboardWeight -= items[y - 1].weight();
			x -= items[y - 1].weight();
			returnList.push_back(std::move(items[y - 1]));
			indexsToRemove.push_back(y - 1);
		}
	}
	removeUsedItems(items, indexsToRemove);
	return returnList;
}

std::vector<goldBar> knapSack_greedy(size_t sackCapacity, std::vector<goldBar>& items)
{
	std::sort(items.begin(), items.end(), [](auto& left, auto& right) {
		return left.weight() > right.weight();
		});
	std::vector<goldBar> sack;
	std::vector<size_t> indexsToRemove;
	for (size_t i{ 0 }; i < items.size(); ++i)
	{
		size_t totalWeight{ getSackWeight(sack) };
		if ((items[i].weight() + totalWeight) <= sackCapacity)
		{
			sack.push_back(std::move(items[i]));
			indexsToRemove.push_back(i);
		}
	}
	removeUsedItems(items, indexsToRemove);
	return sack;
}

void removeUsedItems(std::vector<goldBar>& items, std::vector<size_t> const& indexsToRemove)
{
	for (auto index : indexsToRemove)
		items.erase(items.begin() + index);
}

size_t getSackWeight(std::vector<goldBar> const& sack)
{
	size_t weight{ 0 };
	for (auto const& item : sack)
		weight += item.weight();
	return weight;
}

void display(grid const& grid)
{
	for (size_t y{ 0 }; y < grid.height(); ++y)
	{
		for (size_t x{ 0 }; x < grid.width(); ++x)
			std::cout << std::setw(3) << grid[coordinates(x, y)];
		std::cout << std::endl;
	}
}