#include <iostream>
#include "./shopping.h"

// Push Goods object to shopping_list_ vector
void Shopping::PushList(Goods object) {
  shopping_list_.push_back(object);
}

// Get Goods object from end of shopping_list_ vector
Goods Shopping::GetLastElement() {
  return shopping_list_.back();
}

// Print shopping_list_ Elements
void Shopping::PrintList() {
  for (std::vector<Goods>::iterator i = shopping_list_.begin();
      i != shopping_list_.end(); i++) {
    std::cout << "Goods #" << i->GetIndex() << " - Price : " <<
    i->GetPrice() << std::endl;
  }
}


// Sort core
// common work for both SortByPrice and SortByIndex
void Shopping::SortCore(int type) {
	std::vector<Goods>::iterator p = shopping_list_.begin();
	std::vector<Goods>::iterator min = shopping_list_.end();
	for (std::vector<Goods>::iterator i = shopping_list_.begin();
		i != shopping_list_.end() - 1; i++) {
		for (std::vector<Goods>::iterator j = i; j != shopping_list_.end(); j++) {
			if (min == shopping_list_.end()) {
				min = j;
				continue;
			}
			switch (type) {
				case TYPE_PRICE:
					if (min->GetPrice() > j->GetPrice()) {
						min = j;
					}
					break;
				case TYPE_INDEX:
					if (min->GetIndex() > j->GetIndex()) {
						min = j;
					}
					break;
			}
		}
		std::iter_swap(i, min);
		min = shopping_list_.end();
	}
}


// Sort shopping_list_ Elements by Price
// Apply Selection Sort algorithm
void Shopping::SortByPrice() {
	SortCore(TYPE_PRICE);
}

// Sort shopping_list_ Elements by Index
// Apply Selection Sort algorithm
void Shopping::SortByIndex() {
	SortCore(TYPE_INDEX);
}
