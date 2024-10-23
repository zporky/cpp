#include <iostream>

struct date_t
{
  int year_ = 1970;
  int month_ = 1;
  int day_ = 1;  
};

date_t make_date( int year, int month = 1, int day = 1)
{
  return { year, month, day };	
}
void print(date_t d) 
{
  std::cout << "[" << d.year_ << ":" 
	            << d.month_ << ":"
	            << d.day_ << "]";	    
};


int main()
{
  date_t d = make_date(2023);
  print(d);
  	
  return 0;	
}
