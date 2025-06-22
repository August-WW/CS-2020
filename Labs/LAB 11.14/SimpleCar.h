#ifndef SIMPLECAR_H_
#define SIMPLECAR_H_

#include <iostream>
using namespace std;

class SimpleCar {
   public:
      SimpleCar();
      void Drive(int dist);
      void Reverse(int dist);
      int GetOdometer();
      void HonkHorn();
      void Report();
   
   private:
      int miles;
};

#endif /* SIMPLECAR_H_ */
