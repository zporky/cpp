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
  struct Ximpl* pimpl_; 
};
