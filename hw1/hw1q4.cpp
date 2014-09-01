#include <iostream>
#include <fstream>
using namespace std;

int main (int argc, char *argv[]) {

  ifstream infile;
  infile.open(argv[1]);
  
  int numlines;
  infile >> numlines;
  // cout << numlines;

  return 0;
}

