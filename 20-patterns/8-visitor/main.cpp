#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <memory>
#include <string>

#include "creator.h"
#include "exam.h"
#include "vehicle.h"

void print(const std::unique_ptr<Vehicle>& vp)
{
  std::cout << vp->to_string() << std::endl;
}
int main()
{
  std::list<std::unique_ptr<Vehicle>> vlist;

  Creator creator;
  std::string input;
  while ( std::getline(std::cin, input ) )
  {
    vlist.push_back(creator.create(input));
  }
  Exam e;
  for ( auto& v : vlist ) 
  {
    v->accept(&e);
  }
  return 0;
}
