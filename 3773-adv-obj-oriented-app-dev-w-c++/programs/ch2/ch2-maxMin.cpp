  // Tomasz Muldner, September 2001
  // A program for the book:
  //  "C++ Programming with Design Patterns Revealed", published by Addison-Wesley, 2002
  // File: ch2-maxMin.cpp

  bool maxMin(double arr[], int size, double& max, double& min) {
    if(size <= 0)
      return false;

    int i;
    for(max = min = arr[0], i = 1; i < size; ++i) {
      if(max < arr[i])
        max = arr[i];
      if(min > arr[i])
        min = arr[i];
    }

    return true;
  }
 

  bool maxMinConst(const double arr[], int size, double& max, double& min) {
    if(size <= 0)
      return false;

    int i;
    for(max = min = arr[0], i = 1; i < size; ++i) {
      if(max < arr[i])
        max = arr[i];
      if(min > arr[i])
        min = arr[i];
    }

    return true;
  }
 
#include <iostream>
using namespace std;

int main() {

  const double arr[] = {1.3, 1.2, 1.1}; // initialization
  double maxi, mini;
  if(!maxMin(const_cast<double*>(arr), 3, maxi, mini)) {
    cerr << "maxMin failed" << endl;
    return 1;
  }
  if(!maxMinConst(arr, 3, maxi, mini)) {
    cerr << "maxMin failed" << endl;
    return 1;
  }
  cout << "array is: ";
  for(int i = 0; i < 3; i++)  
     cout << arr[i] << "\t";
  cout << endl;
  cout << " max = " << maxi << " min = " << mini << endl;
}

