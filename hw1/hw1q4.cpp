#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

int main (int argc, char *argv[]) {
  //open file
  ifstream infile;
  infile.open(argv[1]);
  
  //if the file fails to open
  if (infile.fail()) {
    cout << "Something went wrong with opening the file! Terminating program." << endl;
    return 1;
  }

    //cout << "File successfully opened." << endl;
  
  //n = number of lines in file, indicated on first line of file
  int n;
  infile >> n;
    //cout << "n = " << n << endl;

  //clear the stream
  infile.clear();
  infile.ignore(80, '\n');

  //create a dynamic array and store line data
  string* lineArray = new string[n];
  for(int i = 0; i < n; i++) {
    getline(infile,lineArray[i]);
      //cout << lineArray[i] << endl;
  }

  //output number of words in each line
  int count = 0;
  string temp;
  stringstream ss;
  for (int line = n-1; line >= 0; line--) {
    ss << lineArray[line];
    while (ss >> temp) {
      count++;
        //cout << "temp = " << temp << ", count++ = " << count << endl;
    }
    cout << count << endl;
    ss.clear();
    count = 0;
  }

  //deallocate memory
  delete [] lineArray;
  
  return 0;
}

