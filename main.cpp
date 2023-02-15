// add your code as appropriate
#include <iostream>
#include "reservoir.h"
int main()
{

  std::cout << get_east_storage("01/01/2018") << " billion gallons" << std::endl;
  std::cout << get_east_storage("03/02/2018") << " billion gallons" << std::endl;
  std::cout << "minimum storage in East basin: " << get_min_east() << " billion gallons" << std::endl;
  std::cout << "maximum storage in East basin: " << get_max_east() << " billion gallons" << std::endl;
}
