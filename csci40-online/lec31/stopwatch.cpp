#include <iostream>
#include <ctime>
using namespace std;

class Stopwatch {
  public:
    void start();
    double getTimeElapsed() const;

  private:
    clock_t startTime; 
};

void Stopwatch::start() {
  startTime = clock();
}

double Stopwatch::getTimeElapsed() const {
  clock_t currentTime = clock();
  return static_cast<double>(currentTime - startTime) / CLOCKS_PER_SEC;
}

int main() {
  Stopwatch s; 
  s.start();

  while (true) {
    cout << s.getTimeElapsed() << "\r";
  }

  return 0;
}
