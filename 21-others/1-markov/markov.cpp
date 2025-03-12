
/* 
 * From:
 * Kernighan-Pike: Practice of Programming, 1998
 * Addison-Wesley
 */

#include <iostream>
#include <cstdlib>
#include <string>

#include <deque>
#include <vector>
#include <map>

const size_t order = 2;
const size_t maxgen = 100;
typedef std::map<std::deque<std::string>, std::vector<std::string> > map_t;
map_t states;

void add_word( std::deque<std::string>& prefix, const std::string& s);
void build_db( std::deque<std::string>& prefix, std::istream& is);
void gener_out(size_t max);

void add_word( std::deque<std::string>& prefix, const std::string& s)
{
  if ( prefix.size() == order )
  {
    states[prefix].push_back(s);
    prefix.pop_front();
  }
  prefix.push_back(s);
}

void build_db( std::deque<std::string>& prefix, std::istream& is)
{
  std::string w;
  
  while ( is >> w )
  {
    add_word(prefix, w);
  }
}

void gener_out(size_t max)
{
  std::deque<std::string> prefix;
  size_t len = 0;

  for (size_t i = 0; i < order; ++i)
    add_word(prefix, "***");

  std::srand(time(0));
  for( size_t i = 0; i < max; ++i)
  {
    const std::vector<std::string>& suffix = states[prefix];
    const std::string& word = suffix[std::rand()%suffix.size()];

    if ( word == "***" )
      break;

    if ( len + word.size() > 70 )
    { 
      std::cout << std::endl;
      len = 0;
    }
    std::cout << word << " ";
    len += word.size() + 1;

    prefix.pop_front();
    prefix.push_back(word);
  }
}

int main()
{  
  std::deque<std::string> prefix;
  for ( size_t i = 0; i < order; ++i)
    add_word( prefix, "***");

  build_db( prefix, std::cin);
  add_word( prefix, "***");

  gener_out(maxgen);

  return 0;  
}
