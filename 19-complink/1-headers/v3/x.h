#include <cstddef>
class X
{
public:
  X( const char *s);
  ~X();
  X(const X&);
  X& operator=(const X&);

  void add( const char *s);
  void print() const;
private:
  static const size_t impl_size_ = 24;  // 20
  alignas (std::max_align_t) char impl_[impl_size_];
};
