#include <iostream>
#include <thread>
#include <queue>
#include <mutex>
#include <condition_variable>


std::deque<int> deq;
std::mutex mut;
std::condition_variable cv;

void produce()
{
  for( int i = 0; i < 1000000; ++i)
  {	  
    const int r = std::rand();
    {
      std::lock_guard<std::mutex>  lg{mut};
      deq.push_back(r);
      cv.notify_one();
    }
  }
}

void consume()
{
  int i = 0;	
  while ( true )
  {	    
    std::unique_lock<std::mutex>  ul{mut};
    cv.wait( ul, []{ return !deq.empty(); } );

    int res = deq.front();
    deq.pop_front();
    ul.unlock();
    ++i;

    if ( 0 == res % 100000 )
    {
      std::cerr << i << " " << res << '\n';
      break;
    }
  }
}

int main()
{
  std::thread t1{produce};
  std::thread t2{consume};

  t1.join();
  t2.join();
}
