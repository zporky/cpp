#include "deq.h"
#include "CppUTest/TestHarness.h"

TEST_GROUP(DeqInit) { };

TEST(DeqInit, Create)
{
   Deq<int>  di;	
   CHECK_EQUAL (0, di.size() );
   CHECK( di.empty() );
}
TEST(DeqInit, Template)
{
   Deq<int>  di;	
   CHECK_EQUAL (0, di.size() );
   CHECK( di.empty() );

   Deq<double> dd;
   CHECK_EQUAL (0, dd.size() );
   CHECK( dd.empty() );
}
TEST(DeqInit, Const)
{
   const Deq<int>  di;	
   CHECK_EQUAL(0, di.size() );
   CHECK( di.empty() );

   const Deq<double> dd;
   CHECK_EQUAL (0, dd.size() );
   CHECK( dd.empty() );
}

TEST_GROUP(DeqPushBack) { };

TEST(DeqPushBack, OneAfterCreate)
{
  Deq<int>  di;

  di.push_back(42);
  
  CHECK_EQUAL(1, di.size() );
  CHECK( !di.empty() );

  CHECK_EQUAL(42, di.front() );
  CHECK_EQUAL(42, di.back() );

//  const Deq<int> dc = di;
 
//  CHECK_EQUAL(1, dc.size() );
//  CHECK( !dc.empty() );

//  CHECK_EQUAL(42, dc.front() );
//  CHECK_EQUAL(42, dc.back() );
}

TEST(DeqPushBack, ManyAfterCreate)
{
  const int toInsert = 96;
  Deq<int> di;

  for ( int i = 0; i < toInsert; ++i)
  {
    di.push_back(i*i);
    CHECK_EQUAL(0, di.front() );
    CHECK_EQUAL(i*i, di.back() );
    CHECK_EQUAL(i+1, di.size() );
  }  

  for ( int i = 0; i < toInsert; ++i)
  {
    CHECK_EQUAL( i*i, di[i] );
  }

  CHECK_EQUAL( di.front(), di[0] );
  CHECK_EQUAL( di.back(), di[di.size()-1] );
}

TEST_GROUP(DeqPopBack) 
{ 
  void setup()
  {
    for ( int i = 0; i < toInsert; ++i)
    {	    
      di.push_back(i*i);
    }      
  }
  const int toInsert = 85;
  Deq<int> di;
};

TEST(DeqPopBack, ManyPushBackPop)
{
  CHECK( ! di.empty() );

  for ( int i = di.size()-1; i > 0; --i)
  {
    CHECK_EQUAL( i*i, di.back() );
    di.pop_back(); 
    CHECK_EQUAL( i, di.size() );    
    CHECK( ! di.empty() );
  }
  CHECK_EQUAL( 0, di.back() );
  di.pop_back();
  CHECK( di.empty() );
}

TEST(DeqPopBack, ManyPushPopPushOne)
{
  CHECK( ! di.empty() );

  const int toPop = 20;
  for ( int i = 0; i < toPop; ++i)
  {
    di.pop_back(); 
  }
  CHECK_EQUAL( toInsert - toPop, di.size() );    
  di.push_back(99);
  CHECK_EQUAL( toInsert - toPop + 1, di.size() );
  CHECK_EQUAL( 99, di.back() ); 	  
}
