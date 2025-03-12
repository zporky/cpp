#include <iostream>

struct Rational
{
  Rational(int i) : x_(i), y_(1) {}
  Rational( int x, int y) : x_(x), y_(y) {} 
  int x_;
  int y_;
  std::weak_ordering operator<=> (const Rational &r) const;
};

std::weak_ordering Rational::operator<=> (const Rational &r) const
{
  return y_*r.y_ < 0 ? ( y_*r.x_ <=> x_*r.y_) : (x_*r.y_ <=> y_*r.x_);
}

Rational operator""_rat(unsigned long long y)
{
    //return Rational{0,static_cast<int>(y)};
    return Rational{0, static_cast<int>(y)};
}
Rational operator/(int x, Rational r)
{
    return Rational{x, r.y_};
}


int main()
{
  Rational q{2,5};
  Rational z = 2/5_rat;

  int x, y;
  while ( std::cin >> x >> y )
  {
    Rational r{x,y};
    std::cout << x << "/" << y << " <= " << "2/5: " << std::boolalpha << ( (r <=> 2/5_rat) <= 0) << '\n';
  }
  return 0;
}