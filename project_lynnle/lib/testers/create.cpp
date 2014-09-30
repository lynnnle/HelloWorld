#include <string>
#include <fstream>
#include <iostream>
#include "set.h"
using namespace std;

//declare variables
Set<string> createSet;
string command, name, temp;

//call map's merge function
void load(string toLoad) {
  //open file and failsafe
  ifstream otherfile;
  otherfile.open(toLoad);
  if (otherfile.fail()) {
    cout << "File does not exist.\n";
  }

  //create new map/variables to store other file data
  Set<string> otherList;
  string otherName;
  //ignore first bracket and loop to add names/emails to other list
  getline(otherfile,temp,'[');
  do {
    getline(otherfile,otherName,']');

    otherList.add(otherName);

    if (!getline(otherfile,temp,'\n')) {
      break;
    }
  } while (getline(otherfile,temp,'['));

  //merge with current list
  createSet.merge(otherList);

}

int main (int argc, char* argv[]) {
  //copied from email.cpp

  //open file from command line and file failsafe
  ifstream infile;
  infile.open(argv[1]);
  if (infile.fail()) {
    //no file to open, do nothing
  }
  else {
    //file has opened, run commands from file
    infile >> command;
    while (command != "QUIT") {
      cout << command << endl; //prints command, not actual input after command
      if (command == "ADD") {
	infile.ignore(12, '[');
	getline(infile,name,']');
	createSet.add(name);
      }
      else if (command == "REMOVE") {
	infile.ignore(12, '[');
	getline(infile,name,']');
	createSet.remove(name);
      }
      else if (command == "CONTAINS") {
	infile.ignore(12, '[');
	getline(infile,name,']');
	if ( createSet.contains(name) ) {
	  cout << "This set contains " << name << endl;
	}
	else {
	  cout << "Set does not contain " << name << endl;
	}
      }
      else if (command == "LOAD") {
	infile.ignore(12, '[');
	getline(infile,name,']');
	load(name);
      }
      else if (command == "print") {
	createSet.printKey();
      }
      else {
	cout << "Illegal command!\n";
      }
      
      infile.clear();
      infile.ignore(100,'\n');
      infile >> command;
    }
    
    return 1;
  }

  /** NON-FILE-READER PROGRAM **/

  //prompt user for command and see what to do with it
  //this is all assuming the user enters commands and items correctly, there is no failsafe
  cout << "What would you like to do? QUIT; or ADD, REMOVE, CONTAINS, LOAD to map?\n";
  cin >> command;
  while (command != "QUIT") {
    if (command == "ADD") {
      //get name and email
      cin.ignore(12, '[');
      getline(cin,name,']');

      createSet.add(name);
    }
    else if (command == "REMOVE") {
      //get name to remove
      cin.ignore(12, '[');
      getline(cin,name,']');

      createSet.remove(name);
    }
    else if (command == "CONTAINS") {
      //get name to search for, and see if it's in the map,
      //and what the associated email is
      cin.ignore(12, '[');
      getline(cin,name,']');
      
      if ( createSet.contains(name) ) {
        cout << "This set contains " << name << ".\n";
      }
      else {
	cout << "Set does not contain " << name << endl;
      }
    }
    else if (command == "LOAD") {
      //get name of file to be opened and merged with current list
      cin.ignore(12, '[');
      getline(cin,name,']');

      load(name);
    }
    else if (command == "print") {
      //secret function just for me to test and see if stuff is working
      createSet.printKey();
    }
    else if (command == "copy") {
      //copy constructor test
      Set<string> copySet(createSet);
      copySet.printKey();
    }
    else if (command == "assign") {
      //testing for assignment operator
      Set<string> assignSet(createSet);
      assignSet.add("test1");
      assignSet.add("test2");
      assignSet.add("test3");
      cerr << "assignSet:\n";
      assignSet.printKey();
      cerr << "copying original createSet over--should delete the tests\n";
      assignSet = createSet;
      cerr << "finished assigning. new reassigned list:\n";
      assignSet.printKey();
    }
    else if (command == "first") {
      try {
	createSet.first();
      }
      catch (const NoSuchElementException & e) {
	cerr << e.what();
	//cerr << "something went wrong\n";
      }
    }
    else if (command == "next") {
      try {
	createSet.next();
      }
      catch(const NoSuchElementException & e) {
	cerr << e.what();
	cerr << "called 'next' and got exception\n";
      }
    }
    else if (command == "get") {
      try {
	cout << "get key: " << createSet.getCurrent() << endl;
      }
      catch(const NoSuchElementException & e) {
	cerr << e.what();
      }
    }
    else if (command == "union") {
      Set<string> unionSet; //unionSet(createSet);
      unionSet.add("testing union 1");
      unionSet.add("testing union 2");
      unionSet.printKey();
      cerr << "union createSet and unionSet. neither should change.\n";
      Set<string> unitedSet = createSet.setUnion(unionSet);
      //cerr << "removing key from unionSet to prove difference\n";
      //unionSet.remove("testing union 2");
      cerr << "united set:\n";
      unitedSet.printKey();
      cerr << "create set:\n";
      createSet.printKey();
      cerr << "union set:\n";
      unionSet.printKey();
    }
    else if (command == "intersect") {
      Set<string> intersect;
      intersect.add("a");
      intersect.add("b");
      intersect.add("c");
      intersect.printKey();
      cerr << "intersecting sets createSet and intersect set\n";
      Set<string> intersected = createSet.setIntersection(intersect);
      intersected.printKey();
      cerr << "original createSet:\n";
      createSet.printKey();
      cerr << "original intersect set:\n";
      intersect.printKey();
    }
    else {
      cout << "Illegal command!\n";
    }

    cin.clear();
    cin.ignore(100,'\n');
    cin >> command;
  }

  return 0;
}
