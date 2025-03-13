#include <iostream>
#include <cstdlib>
#include "etl/list.h"
#include "etl/vector.h"
#include "etl/string.h"
#include "etl/string_view.h"
#include "etl/to_string.h"
#include "etl/string_utilities.h"
#include "etl/algorithm.h"
#include "etl/optional.h"

#include "vehicle.h"
#include "truck.h"
#include "bus.h"
#include "car.h"

using Token  = etl::optional<etl::string_view>;
using Tokens = etl::vector<etl::string<20>,6>;

void print(const Vehicle* vp)
{
  std::cout << vp->to_string().data() << std::endl;
}
int main()
{
  char buffer[1000];
  char *ptr = buffer;

  etl::list<Vehicle*,10> vlist;

  char input[80];
  while ( std::fgets(input, 80, stdin ) )
  {
    etl::string<80> inp(input);	  
    etl::string<10> type;
    etl::string<20> license;
    etl::string<20> owner;      
    int             wheels;      

    Tokens tokens;
    Token  token;

    while ( (token = etl::get_token(inp, " \t", token, true)) )
    {
      tokens.emplace_back(token.value());
    }      
    type    = tokens[0];
    license = tokens[1];
    owner   = tokens[2];
    wheels  = std::strtol(tokens[3].data(), nullptr, 10);

    if ( "car" == type )
    {
      double emission = std::strtod(tokens[4].data(), nullptr);
      vlist.push_back(new (ptr) Car{license, owner, wheels, emission});
      ptr += sizeof(Car);
    }
    else if ( "bus" == type )
    {
      int passangers = std::strtol(tokens[4].data(), nullptr, 10);
      vlist.push_back(new (ptr) Bus{license, owner, wheels, passangers});
      ptr += sizeof(Bus);
    }
    else if ( "truck" == type )
    {
      double weight = std::strtod(tokens[4].data(), nullptr);
      vlist.push_back(new (ptr) Truck{license, owner, wheels, weight});
      ptr += sizeof(Truck);
    }
  }

  etl::for_each ( vlist.begin(), vlist.end(), print); 
  std::cout << "================================" << '\n';

  return 0;
}
