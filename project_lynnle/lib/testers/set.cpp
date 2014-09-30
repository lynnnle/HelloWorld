template <class T>
Set<T>::Set () {
  // constructor for a new empty set
  //cerr << "creating set\n";
  internalStorage.setError("Name already in set","Name was not in set","Name was not in set");
}

template <class T>
Set<T>::Set (const Set<T> & other) {
  // copy constructor
  //cerr << "creating copy\n";
  internalStorage.merge(other.internalStorage);
  internalStorage.setError(other.internalStorage.getAddErr(), other.internalStorage.getRemErr(), other.internalStorage.getGetErr() );
}

template <class T>
Set<T>::~Set () {
  // destructor
  // do nothing - nothing to deallocate
}

template <class T>
int Set<T>::size () const {
  // returns the number of elements in the set
  return internalStorage.size();
}

template <class T>
void Set<T>::add (const T & item) {
  /* Adds the item to the set.
     If the item is already in the set, it should do nothing.
  */
  internalStorage.add(item, item);
  //ignore the second parameter, it's unimportant except that the function requires two parameters
}

template <class T>
void Set<T>::remove (const T & item) {
  /* Removes the item from the set.
     If the item was not in the set, it should do nothing. */
  internalStorage.remove(item);
}

template <class T>
bool Set<T>::contains (const T & item) const {
  /* Returns whether the item is in the set. */
  return internalStorage.keyExists(item);
}

template <class T>
void Set<T>::merge (const Set<T> & other) {
  /* Adds all elements of other to this set. 
     However, will not create duplicates, i.e., it ignores elements
     already in the set. */
  internalStorage.merge(other.internalStorage);
  //the Map's merge function should handle duplicates
}

template <class T>
void Set<T>::first() {
  // resets traversal to a "first" element,
  // throws "NoSuchElementException" if empty
  internalStorage.first();
}

template <class T>
void Set<T>::next() {
  // traverses elements in list, throws "NoSuchExcetion" if at end
  internalStorage.next();
}

template <class T>
const T & Set<T>::getCurrent() {
  return internalStorage.getCurrentKey();
}

template <class T>
Set<T> Set<T>::setUnion (const Set<T> & other) const {
  // Returns the union of this and other. Does not alter this.
  Set<T> unionSet(*this);
  unionSet.merge(other);
  return unionSet;
}

template <class T>
Set<T> Set<T>::setIntersection (const Set<T> & other) const {
  // Returns the intersection of this and other. Does not alter this.
  Set<T> intersectSet(*this);
  //get all elements in one list
  intersectSet.merge(other);

  //cerr << "intersect list size: " << intersectSet.size() << endl;
  if ( intersectSet.internalStorage.leaderGet() ) {
    intersectSet.first();
    for (int i = 0; i < other.size()+this->size(); i++) {
      //cerr << "i = " << i << endl;
      if ( other.contains(intersectSet.getCurrent()) == true && this->contains(intersectSet.getCurrent()) == true ) {
	//if both sets contain the current element, do nothing
	//cerr << "not removing " << intersectSet.getCurrent() << endl;
      }
      else {
	//the other set contains an element not in this set
	//cerr << "removing " << intersectSet.getCurrent() << endl;
	intersectSet.remove(intersectSet.getCurrent());
      }

      if ( intersectSet.internalStorage.leaderNext() ) {
	intersectSet.next();
      }
    } //end for
  } //end if

  return intersectSet;
}


template <class T>
void Set<T>::printKey () const {
  // calls print list function of Map. debugging purposes, can ignore.
  internalStorage.printKey();
}
