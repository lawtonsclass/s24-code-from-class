#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

/*
int sum(const vector<int>& v) {
  // can't use a loop for the same reason
  // split up the array into index 0 and the rest of the array
  // something like return v.at(0) + sum(smaller vector);
}
*/

int sum(const vector<int>& v, int curIndex) {
  // split up the array into index 0 and the rest of the array
  if (curIndex >= v.size()) {
    return 0; // there's nothing left--invalid index
  } else {
    // recursive case
    return v.at(curIndex) + sum(v, curIndex+1);
  }
}

// Future Lawton: draw the stack blowing up

// tail recursion: making a new stack frame is unneccessary
int sum_tail(const vector<int>& v, int curIndex, int accumulator) {
  // split up the array into index 0 and the rest of the array
  if (curIndex >= v.size()) {
    return accumulator; // there's nothing left--return what we have built up
  } else {
    // recursive case
    // can reuse our current stack frame because there's no need to
    // save any work
    return sum_tail(v, curIndex+1, accumulator + v.at(curIndex));
  }
}

int main() {
  vector<int> v = {1, 2, 3, 4, 5};

  // cout << "Sum: " << sum(v) << endl;
  cout << "Sum: " << sum(v, 0) << endl;
  cout << "Sum: " << sum_tail(v, 0, 0) << endl;

  // pretty much equivalent to sum_tail
  cout << "Sum: " << accumulate(v.begin(), v.end(), 0) << endl;

  return 0;
}
