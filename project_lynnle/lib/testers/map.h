#ifndef MAP_H
#define MAP_H

#include <exception>
#include <string>
using namespace std;

template <class keyType, class valueType>
struct MapItem
{
  keyType key;
  valueType value;
  MapItem<keyType, valueType> *prev, *next;
};


template <class keyType, class valueType>
class Map
{
  public:
  //overloading assignment operator
  Map<keyType,valueType> & operator=(const Map<keyType,valueType> & toAssign);

    Map ();  // constructor for a new empty map

    Map (const Map<keyType, valueType> & other); //copy constructor

    ~Map (); // destructor

    int size () const; // returns the number of key-value pairs

    void add (const keyType & key, const valueType & value); 
      /* Adds a new association between the given key and the given value.
         If the key already has an association, it should do nothing.
      */
    /**  
	 due to the items being unalterable, pass the SECOND template type
         (when declaring the item in any main program) as a pointer.
	 then you can alter the actual contents.
	 otherwise, delete const before valueType; this does the same thing.
	 ie. for passing pointer: Map<string, Set<Movie*>*> keywordLookup;
	 this passes a pointer of type Set<Movie*>, which itself is declaring
	 a templated data type using a pointer of type Movie
	 so that it can be altered.
    **/

    void remove (const keyType & key);
     /* Removes the association for the given key.
        If the key has no association, it should do nothing. */

    valueType & get (const keyType & key) const;
     /* Returns the value associated with the given key. */

    void merge (const Map<keyType, valueType> & other);
     /* Adds all the key-value associations of other to the current map.
        If both maps (this and other) contain an association for the same
        key, then the one of this is used. */


    //** adding functions to traverse

    void first();
    // resets the traversal to a "first" element, and throws an exception
    // of type "NoSuchElementException" if the list is empty

    void next();
    // traverses the list from the leader to the next element,
    // throws exception "NoSuchElementException" if nothing to traverse

    const keyType & getCurrentKey();
    // returns current element's (leader's) key

    const valueType & getCurrentValue();
    // returns current element's (leader's) value

    /** Adding own functions--public because need access **/

    bool keyExists (const keyType & key) const;
    // Checks to see if the key exists already, returns true if it does

    void printKey() const;
    // Print list of keys and values associated with the keys;
    // tester function (can be ignored)

    bool leaderGet() const;
    // see if the leader/head item exists; returns true if it does

    bool leaderNext() const;
    // see if next search/traverse item exists; returns true if it does

    void printError(string errorMessage) const;
    // Prints error messages (with endline), allows for custom error messages

    void setError(string addMsg, string remMsg, string getMsg);
    // Sets the custom error messages

    string getAddErr() const;
    string getRemErr() const;
    string getGetErr() const;
    // functions to get private variables

  private:
     /* The head and tail of the linked list you're using to store
        all the associations. */

     MapItem <keyType, valueType> *head, *tail;

     MapItem <keyType, valueType>* leader;
     //for traversing, first item to traverse from

     /* If you like, you can add further data fields and private
        helper methods. */

     // Error message strings that can be set by user
     string cannotAdd;
     string cannotRemove;
     string cannotGet;
};

class NoSuchElementException //: public Exception
{
 public:
  NoSuchElementException() {
    errorMessage = "No such element exception\n";
  }
  NoSuchElementException(string str) {
    errorMessage = str;
  }

  string what() const {
    return errorMessage;
  }

 private:
  string errorMessage;
};

#include "map.cpp"
#endif
