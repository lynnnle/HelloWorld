#ifndef SET_H
#define SET_H

#include <string>
#include "map.h"

template <class T>
class Set
{
  public:
    Set (); // constructor for a new empty set

    Set (const Set<T> & other); //copy constructor

    ~Set (); // destructor

    int size () const; // returns the number of elements in the set

    void add (const T & item); 
      /* Adds the item to the set.
         If the item is already in the set, it should do nothing.
      */

    void remove (const T & item);
     /* Removes the item from the set.
        If the item was not in the set, it should do nothing. */

    bool contains (const T & item) const;
     /* Returns whether the item is in the set. */

    void merge (const Set<T> & other);
     /* Adds all elements of other to this set. 
        However, will not create duplicates, i.e., it ignores elements
        already in the set. */


    void first();
    // resets traversal to a "first" element,
    // throws "NoSuchElementException" if empty

    void next();
    // traverses elements in list, throws "NoSuchElementException" if at end

    const T & getCurrent();
    // returns the key of the current element (leader's)

    Set<T> setUnion (const Set<T> & other) const;
    // Returns the union of this and other. Does not alter this.

    Set<T> setIntersection (const Set<T> & other) const;
    // Returns the intersection of this and other. Does not alter this.


    void printKey() const;
    // calls print list function of Map. debugging purposes, can ignore.

    void setError(string AddE, string RemE, string GetE);
    string getAddErr() const;
    string getRemErr() const;
    string getGetErr() const;
    // sets and gets the custom error messages

    bool traverseFirst() const;
    bool traverseNext() const;
    //see if, when traversing the list, the item exists. return true if so.

  private:
    Map<T, T> internalStorage;
     /* You should use a Map (your own implementation) to store your set.
        It is part of your assignment to figure out what types you 
        need for the keyType and valueType. */

     /* If you like, you can add further data fields and private
        helper methods. */
};

#include "set.cpp"
#endif
