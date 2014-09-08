#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//prototype functions (commands)
void empty(int i); //where i is the number of the bucket
void put(int bucket); //finish this function parameter list later
void output(int i); //where i is the number of the bucket

int main(int argc, char *argv[]) {
  //open file and failcheck
  ifstream infile;
  infile.open(argv[1]);
  if (infile.fail()) {
    cout << "Could not open file. Terminating program." << endl;
    return 1;
  }

  //declare bucket array (buckets start out empty), command counter,
  //number of buckets, number of elements array, and other variables
  int **b, c, i, *k;
  string command;
  int n;

  //read the number of buckets and declare array of i empty buckets with 0 elements
  infile >> i;
  b = new int* [i];
  k = new int [i];
  for (int x = 0; x < i; x++) {
    //initialize to nothing
    b[x] = 0;
    k[x] = 0;
  }
  //read in the number of commands
  infile >> c;
  //clear stream
  infile.clear();
  infile.ignore(100, '\n');

  //for loop to read all the commands
  for (int line = 0; line < c; line++) {
    //read in the command and the bucket index
    infile >> command >> n;
    
    //see which command it is
    if (command == "EMPTY") {
      //EMPTY = empty a bucket
      if (n < 1 || n > i) {
	//if there is no bucket n, output error "Error - bucket n does not exist"
	cout << "Error - bucket " << n << " does not exist" << endl;
      } //end if
      else {
	//delete current bucket and set to NULL/empty
        delete [] b[n-1];
        b[n-1] = 0;
      } //end else
    }

    else if (command == "PUT") {
      //PUT = put a new sequence of integers into an empty bucket
      if (b[n-1] != 0) {
	//if bucket n is not empty, output error "Error - bucket n is not empty"
	cout << "Error - bucket " << n << " is not empty" << endl;
      } //end if
      else {
	//delete current empty bucket and remake "bigger" bucket to fit all ints
	delete b[n-1];
	infile >> k[n-1]; //get number of elements to store
	b[n-1] = new int[ k[n-1] ];
	for (int x = 0; x < k[n-1]; x++) {
	  infile >> b[n-1][x];
	}
      } //end else
    }

    else {
      //can only get here if command is OUTPUT
      if (n < 1 || n > c) {
	//if bucket n does not exist, output error "Error - bucket n does not exist"
	cout << "Error - bucket " << n << " does not exist" << endl;
      }
      else if (b[n-1] == 0) {
	//output "empty" if bucket is empty
	cout << "empty" << endl;
      }
      else {
	//OUTPUT = output the content of a bucket
	for (int x = 0; x < k[n-1]; x++) {
	  cout << b[n-1][x] << " ";
	}
	cout << endl;
      } //end if-else-if block
    } //end if-else-if "see command" block

    //clear stream
    infile.clear();
    infile.ignore(100, '\n');

  } //end for loop to execute commands

  //deallocate memory
  for (int x = 0; x < i; x++) {
    delete b[x];
    b[x] = NULL;
  }
  delete [] b;
  b = NULL;
  delete [] k;
  k = NULL;

  return 0;
}
