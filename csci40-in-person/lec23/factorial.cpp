#include <iostream>
using namespace std;

// returns n!
int fact(int n) {
  if (n == 1) {
    // base case: 1! = 1
    return 1;
  } else {
    // recursive case: n! = n * (n-1)!
    return n * fact(n-1);
  }
}

int main() {
  cout << fact(5) << endl;
  cout << fact(-1) << endl;

  return 0;
}
