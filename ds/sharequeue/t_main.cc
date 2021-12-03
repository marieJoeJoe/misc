#include "sharedqueue.hpp"
#include <cstdlib>
#include <thread>
#include <unistd.h>
#include <cstdio>

SharedQueue<int> img_queue;

void ProducerTask() //
{
  while(1) {
    usleep(500000);
    //printf("%s\n",__FUNCTION__);
    img_queue.push_back(rand());
  }
}

void ConsumerTask() //
{
  while(1) {
    sleep(1);
    printf("%s\n",__FUNCTION__);
    if(img_queue.size()){
      printf("[%s],%d\n", __FUNCTION__, img_queue.front());
      img_queue.pop_front();
    }
  }
}



int main(int argc, char* argv[])
{
  
  std::thread producer(ProducerTask); //
  std::thread consumer(ConsumerTask); //

  producer.join();
  consumer.join();

  return 0;
}
