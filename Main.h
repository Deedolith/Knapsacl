#pragma once

#include <vector>

#include "goldBar.h"
#include "grid.h"

std::vector<goldBar> knapSack_01(size_t, std::vector<goldBar>&);
std::vector<goldBar> retrieveItems(grid const&, std::vector<goldBar>&);
std::vector<goldBar> knapSack_greedy(size_t, std::vector<goldBar>&);
size_t getSackWeight(std::vector<goldBar> const&);
void removeUsedItems(std::vector<goldBar>&, std::vector<size_t> const&);
void display(grid const&);
