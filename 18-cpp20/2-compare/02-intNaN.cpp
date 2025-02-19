#include <iostream>
#include <optional>
#include <compare>

struct IntNan 
{
  std::optional<int> val = std::nullopt;

  bool operator==(IntNan const& rhs) const {
    if (!val || !rhs.val) {
      return false;
    }
    return *val == *rhs.val;
  }

  std::partial_ordering operator<=>(IntNan const& rhs) const {
    if (!val || !rhs.val) {
      // we can express the unordered state as a first class value
      return std::partial_ordering::unordered;
    }

    // <=> over int returns strong_ordering, but this is
    // implicitly convertible to partial_ordering
    return *val <=> *rhs.val;
  }
};

int main()
{
  std::cout << std::boolalpha;
  std::cout << ( (IntNan{2} <=> IntNan{4}) < 0 ) << '\n'; // true
  std::cout << ( (IntNan{2} <=> IntNan{}) == std::partial_ordering::unordered ) << '\n'; // true
  std::cout << ( IntNan{2} == IntNan{2} ) << '\n';   // true
  std::cout << ( IntNan{2} == IntNan{4} ) << '\n';   // false
  std::cout << ( IntNan{2} == IntNan{}  ) << '\n';   // false
  std::cout << ( IntNan{2} < IntNan{4}  ) << '\n';   // true
  std::cout << ( IntNan{2} < IntNan{}   ) << '\n';   // false
  std::cout << ( IntNan{2} == IntNan{}  ) << '\n';   // false
  std::cout << ( IntNan{2} <= IntNan{}  ) << '\n';   // false
					    
  return 0;				 
}
