#ifndef SHOPPING_H_
#define SHOPPING_H_

#include <vector>
#include "./goods.h"

// Shopping class presents List of shopping.
// Example:
//     Shopping tobuylist;
//     Goods obj1;
//     Goods obj2;
//     ...
//     tobuylist.PushList(obj1);
//     tobuylist.PushList(obj2);
//     tobuylist.PrintList();
enum Type
{
	TYPE_PRICE,
	TYPE_INDEX,
};

class Shopping{
 public:
  void PushList(Goods object);
  Goods GetLastElement();
  void PrintList();
  void SortByPrice();
  void SortByIndex();

 private:
  std::vector<Goods> shopping_list_;
  void SortCore(int type);
};

#endif  // SHOPPING_H_
