#include <iostream>
#include <compare>

class Date
{
public:
  Date( int y, int m, int d) { set(y,m,d); }	
  int year()  const { return year_; }
  int month() const { return month_;  }
  int day()   const { return day_; }
  void set( int y, int m, int d) { year_ = y; month_ = m; day_ = d; } 

  bool operator==(const Date &d) const = default;
  std::strong_ordering operator<=>( const Date& d) const;
private:
  int year_;
  int month_;
  int day_;  
};

std::strong_ordering Date::operator<=>( const Date& d) const
{
  if (auto c = year_  <=> d.year_;  c != 0 ) return c;  	
  if (auto c = month_ <=> d.month_; c != 0 ) return c;  	
  return day_ <=> d.day_;
}

int main()
{
  std::cout << std::boolalpha;	
  std::cout << ( Date{2025,2,20} ==  Date{2025,2,20} ) << '\n'; // true  	
  std::cout << ( Date{2025,2,20} ==  Date{2025,2,21} ) << '\n'; // false 	
  std::cout << ( Date{2025,2,20} <   Date{2025,2,20} ) << '\n'; // false 	
  std::cout << ( Date{2025,2,20} <   Date{2025,2,21} ) << '\n'; // true 	
  std::cout << ( Date{2025,2,20} !=  Date{2025,2,20} ) << '\n'; // false 	
  std::cout << ( Date{2025,2,20} !=  Date{2025,2,21} ) << '\n'; // true 	
  std::cout << ( Date{2025,2,20} <=  Date{2025,2,20} ) << '\n'; // true 	
  std::cout << ( Date{2025,2,20} <=  Date{2026,2,21} ) << '\n'; // true 	

  return 0;
}
