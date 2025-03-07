#include "deq.h"
#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"
#include <iostream>

template <typename T>
struct MockVector
{
  size_t size() const { return vec_.size(); }
  
  T& front() { return vec_.front(); }
  const T& front() const { return vec_.front(); }

  T& operator[](size_t idx) { return vec_[idx]; }	  
  const T& operator[](size_t idx) const { return vec_[idx]; }	  

  typename std::vector<T>::iterator begin() { return vec_.begin(); }

  void push_back(T&& t)	
  {
    std::cerr << "mock push_back()\n";    
    vec_.push_back(std::move(t));	  
  }
  void insert( typename std::vector<T>::iterator it, T&& t)
  {
    vec_.insert(it,std::move(t));	  
  }
  void erase( typename std::vector<T>::iterator it)
  {
    vec_.erase(it);	  
  }
  std::vector<T>& getVec() { return vec_; }

  std::vector<T> vec_{};
};


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

TEST(DeqPopBack, ManyPushBackPopBack)
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

TEST(DeqPopBack, ManyPushBackPopBackPushBackOne)
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

TEST_GROUP(DeqPopFront) 
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

TEST(DeqPopFront, PushBackPopFront)
{
  CHECK( ! di.empty() );

  for ( int i = 0; i < toInsert-1; ++i)
  {
    CHECK_EQUAL( i*i, di.front() );
    di.pop_front(); 
    CHECK_EQUAL( toInsert-i-1, di.size() );    
    CHECK( ! di.empty() );
  }
  CHECK_EQUAL( (toInsert-1)*(toInsert-1), di.front() );
  di.pop_front();
  CHECK( di.empty() );
}

TEST(DeqPopFront, PushBackPopFrontPushBackOne)
{
  CHECK( ! di.empty() );

  for ( int i = 0; i < toInsert-1; ++i)
  {
    di.pop_front(); 
  }
  CHECK_EQUAL( (toInsert-1)*(toInsert-1), di.front() );
  di.pop_front();
  CHECK( di.empty() );

  const int rePush = 20;
  for ( int i = 0; i < rePush; ++i)
  {
    di.push_back(i*i); 
  }
  CHECK_EQUAL( rePush, di.size() );    
  CHECK_EQUAL( (rePush-1)*(rePush-1), di.back() ); 	  
}

TEST_GROUP( PushFront ) { };

TEST( PushFront, AfterEmpty )
{
  Deq<int> di;

  di.push_front(49);
  
  CHECK ( !di.empty() );
  CHECK_EQUAL( 1,  di.size() );
  CHECK_EQUAL( 49, di.front() );
  CHECK_EQUAL( 49, di[0] );
}	

TEST(PushFront, ManyAfterCreate)
{
  const int toInsert = 77;
  Deq<int> di;

  for ( int i = 0; i < toInsert; ++i)
  {
    di.push_front(i*i);
    CHECK_EQUAL(i*i, di.front() );
    CHECK_EQUAL(0, di.back() );
    CHECK_EQUAL(i+1, di.size() );
  }  

  for ( int i = 0; i < toInsert; ++i)
  {
    int val = toInsert-1-i;	  
    CHECK_EQUAL( val*val, di[i] );
  }

  CHECK_EQUAL( di.front(), (toInsert-1)*(toInsert-1) );
  CHECK_EQUAL( di.back(), 0 );
}

TEST(PushFront, BackFrontMixed)
{
  const int toInsert = 73;
  Deq<int> di;

  for ( int i = 0; i < toInsert; ++i)  
  {
    di.push_front(-i-1);
    di.push_back(i);
    CHECK_EQUAL( -i-1, di.front() );
    CHECK_EQUAL(    i, di.back() );
  }
  CHECK_EQUAL( 2*toInsert, di.size() );

  for ( int i = 0; i < di.size(); ++i)
  {
    CHECK_EQUAL( -toInsert+i, di[i] );
  }	  
}	

TEST_GROUP( Exception )
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

TEST( Exception, NoException)
{
  for ( int i = 0; i < toInsert; ++i)
  {
    // CHECK_NO_THROWS(di[i]);
    CHECK_EQUAL( i*i, di.at(i) );
  }	  
  CHECK_THROWS( std::out_of_range, di.at(di.size()) );
//  CHECK_THROWS( std::out_of_range, di.at(-1) );	 ugly trick
  CHECK_THROWS( std::out_of_range, di.at(123456) );		  
}

TEST_GROUP( Mocking ) 
{ 
  void teardown()
  {
    mock().clear();
  }
};

using MockType = std::unique_ptr<std::array<int,ChunkSize_>>;

TEST(Mocking, BackFrontMixed)
{
  const int toInsert = 73;
  Deq<int,MockVector<MockType>> di;

  for ( int i = 0; i < toInsert; ++i)  
  {
    di.push_front(-i-1);
    di.push_back(i);
    CHECK_EQUAL( -i-1, di.front() );
    CHECK_EQUAL(    i, di.back() );
  }
  CHECK_EQUAL( 2*toInsert, di.size() );

  for ( int i = 0; i < di.size(); ++i)
  {
    CHECK_EQUAL( -toInsert+i, di[i] );
  }	  
}	

