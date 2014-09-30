#include <iostream>
#include <fstream>
#include <string>
#include "map.h"

using namespace std;

//declare global variables
Map<string,string> mailList; //create list item
string temp; //temporary to keep strings
string command; //see what command it is
string name; //name variable, can have spaces
string email; //email variable

//call map's add function
void addItem(string name, string email) {
  mailList.add(name,email);
}

//call map's remove function
void removeItem(string toRem) {
  mailList.remove(toRem);
}

//call map's get function
void query(string toQuery) {
  if ( mailList.keyExists(toQuery) ) {
    cout << "Email: " << mailList.get(toQuery) << endl;
  }
  else {
    cout << "Name was not in map\n";
  }
}

//call map's merge function
void load(string toLoad) {
  //open file and failsafe
  ifstream otherfile;
  otherfile.open(toLoad);
  if (otherfile.fail()) {
    cout << "File does not exist.\n";
  }

  //create new map/variables to store other file data
  Map<string,string> otherList;
  string otherName, otherEmail;
  //ignore first bracket and loop to add names/emails to other list
  getline(otherfile,temp,'[');
  do {
    getline(otherfile,otherName,']');
    getline(otherfile,temp,'[');
    getline(otherfile,otherEmail,']');

    otherList.add(otherName,otherEmail);

    if (!getline(otherfile,temp,'\n')) {
      break;
    }
  } while (getline(otherfile,temp,'['));

  //merge with current list
  mailList.merge(otherList);
}

int main (int argc, char* argv[]) {
  //setting error messages for the map first
  mailList.setError("Name already in map","Name was not in map","Name was not in map");


/** this portion of code was written AFTER the "NON-FILE-READER PROGRAM"
    below. the while loop was copied and pasted with minor tweaks to the
    instream and removed documentation. it does not show which commands
    were written, only the command itself and results of the command.
    this is mainly for my convenience for testing and can be ignored.
    the program also ignores this portion if there is no command argument.
**/

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
	infile.ignore(12, '[');
	getline(infile,email,']');
	addItem(name, email);
      }
      else if (command == "REMOVE") {
	infile.ignore(12, '[');
	getline(infile,name,']');
	removeItem(name);
      }
      else if (command == "QUERY") {
	infile.ignore(12, '[');
	getline(infile,name,']');
	query(name);
      }
      else if (command == "LOAD") {
	infile.ignore(12, '[');
	getline(infile,name,']');
	load(name);
      }
      else if (command == "print") {
	mailList.printKey();
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
  cout << "What would you like to do? QUIT; or ADD, REMOVE, QUERY, LOAD to email map?\n";
  cin >> command;
  while (command != "QUIT") {
    if (command == "ADD") {
      //get name and email
      cin.ignore(12, '[');
      getline(cin,name,']');
      cin.ignore(12, '[');
      getline(cin,email,']');
      //this also waits for correct input if user fails to input email
      //it was an accident but it works
      //(assuming user inputs [email] with brackets and not jiberish)

      addItem(name, email);
    }
    else if (command == "REMOVE") {
      //get name to remove
      cin.ignore(12, '[');
      getline(cin,name,']');

      removeItem(name);
    }
    else if (command == "QUERY") {
      //get name to search for, and see if it's in the map,
      //and what the associated email is
      cin.ignore(12, '[');
      getline(cin,name,']');

      query(name);
    }
    else if (command == "LOAD") {
      //get name of file to be opened and merged with current list
      cin.ignore(12, '[');
      getline(cin,name,']');

      load(name);
    }
    else if (command == "print") {
      //secret function just for me to test and see if stuff is working
      mailList.printKey();
    }
    else if (command == "copy") {
      //testing for copy constructor
      Map<string,string> copyList(mailList);
      copyList.printKey();
    }
    else if (command == "assign") {
      //testing for assignment operator
      Map<string,string> assignList(mailList);
      string testValue = "email";
      assignList.add("test1",testValue);
      assignList.add("test2",testValue);
      assignList.add("test3",testValue);
      cerr << "assignList:\n";
      assignList.printKey();
      cerr << "copying original mailList over--should delete the tests\n";
      assignList = mailList;
      cerr << "finished assigning. new reassigned list:\n";
      assignList.printKey();
    }
    else if (command == "first") {
      try {
	mailList.first();
      }
      catch (const NoSuchElementException & e) {
	cerr << e.what();
	//cerr << "something went wrong\n";
      }
    }
    else if (command == "next") {
      try {
	mailList.next();
      }
      catch(const NoSuchElementException & e) {
	cerr << e.what();
	cerr << "called 'next' and got exception\n";
      }
    }
    else if (command == "get") {
      try {
	cout << "get key: " << mailList.getCurrentKey() << endl;
	cout << "get value: " << mailList.getCurrentValue() << endl;
      }
      catch(const NoSuchElementException & e) {
	cerr << e.what();
      }
    }
    else if (command == "size") {
      cout << "size of list: " << mailList.size() << endl;
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
