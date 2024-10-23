#include <iostream>

void f(const int *, short) { std::cout << "1\n"; }
void f(int *, int)         { std::cout << "1\n"; }


int main()
{
  int   i = 0;
  short s = 0;
  long  l = 10L;

  f( &i, l);   // (1) &i->int* > &i->const int* (2) l->int = l->short 
               // calls f(int *, int)

  f( &i, 'c'); // (1) &i->int* > &i->const int* (2) 'c'->int > 'c'->short     
               // calls f(int *, int)

//  f( &i, s);   // (1) &i->int* > &i->const int* (2) s->int < s->short        
               // compiler error
}

