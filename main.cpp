// add your code as appropriate
#include <iostream>
#include "reservoir.h"
#include "reverseorder.h"
int main()
{

  std::cout << get_east_storage("01/01/2018") << " billion gallons" << std::endl;
  std::cout << get_east_storage("03/02/2018") << " billion gallons" << std::endl;
  std::cout << "minimum storage in East basin: " << get_min_east() << " billion gallons" << std::endl;
  std::cout << "maximum storage in East basin: " << get_max_east() << " billion gallons" << std::endl;
  std::cout << compare_basins("01/01/2018") << std::endl;
  std::cout << compare_basins("02/01/2018") << std::endl;
  std::cout << compare_basins("03/01/2018") << std::endl;
  std::cout << compare_basins("04/01/2018") << std::endl;
  std::cout << "The data in reverse order from the interval is displayed below:" << std::endl;
  reverse_order("01/01/2018", "01/05/2018");
  std::cout << "The data in reverse order from the interval is displayed below:" << std::endl;
  reverse_order("01/01/2018", "01/15/2018");
}
