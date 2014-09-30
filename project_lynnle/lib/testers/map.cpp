
#include <cstddef>
#include <iostream>
//using namespace std;

//overloading assignment operator
template <class keyType, class valueType>
Map<keyType,valueType> & Map<keyType,valueType>::operator=(const Map<keyType,valueType> & toAssign) {
  MapItem<keyType,valueType>* temp = toAssign.head;
  MapItem<keyType,valueType>* current = head;
  MapItem<keyType,valueType>* newItem;

  if (temp == NULL) {
    head = NULL;
    tail = NULL;
  }

  while (temp != NULL) {
    current->key = temp->key;
    current->value = temp->value;
    current->next = NULL;
    if (temp->next != NULL) {
      newItem = new MapItem<keyType,valueType>;
      current->next = newItem;
      newItem->prev = current;
      newItem->next = NULL;
      current = newItem;
    }
    tail = current;
    temp = temp->next;
  }
  
  //cerr << "assigned operations.\n";
  return *this;
}


template <class keyType, class valueType>
Map<keyType,valueType>::Map () {
  // constructor for a new empty map
  head = NULL;
  tail = NULL;
  cannotAdd = "Warning: Key already exists. Not creating item.";
  cannotRemove = "Could not remove key.";
  cannotGet = "Key not found.";

  leader = head;
}

template <class keyType, class valueType>
Map<keyType,valueType>::Map (const Map<keyType, valueType> & other) {
  //copy constructor
  //MapItem<keyType,valueType>* temp = other.head;

  //initializing head and tail
  head = NULL;
  tail = NULL;
    
  /*
  MapItem<keyType,valueType>* temp2;
  //while head isn't the only item, add items from other list
  while (temp->next != NULL) {
    temp2 = new MapItem<keyType,valueType>;
    temp2->key = temp->key;
    temp2->value = temp->value;
    if (head == NULL && tail == NULL) {
      head = temp2;
      tail = temp2;
      temp2->prev = NULL;
      temp2->next = NULL;
    }
    else {
      temp2->prev = tail;
      temp2->next = NULL;
      tail = temp2;
    }
    temp = temp->next;
  }
  */
  this->merge(other);

  setError(other.getAddErr(),other.getRemErr(),other.getGetErr() );
  //cerr << "creating map copy\n";
}

template <class keyType, class valueType>
Map<keyType,valueType>::~Map () {
  // destructor
  MapItem<keyType,valueType>* temp = head;
  MapItem<keyType,valueType>* temp2 = NULL;
  while (temp != NULL) {
    temp2 = temp->next;
    delete temp;
    temp = temp2;
  }
}

template <class keyType, class valueType>
int Map<keyType,valueType>::size () const {
  // returns the number of key-value pairs
  int count = 0;
  MapItem<keyType,valueType>* temp = head;
  while (temp != NULL) {
    count++;
    temp = temp->next;
  }
  return count;
}

template <class keyType, class valueType>
void Map<keyType,valueType>::add (const keyType & key, const valueType & value) {
      /* Adds a new association between the given key and the given value.
         If the key already has an association, it should do nothing.
      */

  MapItem<keyType,valueType>* temp = new MapItem<keyType,valueType>;
  temp->key = key;
  temp->value = value;

  if ( keyExists(temp->key) ) {
    //if the item already exists, keyExists returns true and doesn't create item
    printError(cannotAdd);
  }
  else {
    //if the item is not an illegal key, create and add it to the list
    if (head == NULL) {
      head = temp;
      tail = temp;
      temp->prev = NULL;
      temp->next = NULL;
    }
    else {
      temp->prev = tail;
      tail->next = temp;
      temp->next = NULL;
      tail = temp;
    }
  }
}

template <class keyType, class valueType>
void Map<keyType,valueType>::remove (const keyType & key) {
     /* Removes the association for the given key.
        If the key has no association, it should do nothing. */
  if ( keyExists(key) ) {
    MapItem<keyType,valueType>* temp = head;
    while (temp->key != key) {
      temp = temp->next;
    }

    if (head == temp && tail == temp) {
      head = NULL;
      tail = NULL;
    }
    else if (head == temp) {
      head = head->next;
      head->prev = NULL;
    }
    else if (tail == temp) {
      tail = tail->prev;
      tail->next = NULL;
    }
    else {
      temp->prev->next = temp->next;
      temp->next->prev = temp->prev;
    }
  }
  else {
    printError(cannotRemove);
  }
}

template <class keyType, class valueType>
valueType & Map<keyType,valueType>::get (const keyType & key) const {
     /* Returns the value associated with the given key. */
  MapItem<keyType,valueType>* temp = head;
  while (temp != NULL) {
    if (temp->key == key) {
      return temp->value;
    }
    temp = temp->next;
  }
  printError(cannotGet);
}

template <class keyType, class valueType>
void Map<keyType,valueType>::merge (const Map<keyType, valueType> & other) {
     /* Adds all the key-value associations of other to the current map.
        If both maps (this and other) contain an association for the same
        key, then the one of this is used. */
  // NOTE: the add function already accounts for duplicate associations
  MapItem<keyType,valueType>* temp = other.head;
  while (temp != NULL) {
    //cout << "Adding item...\n";
    add(temp->key, temp->value);
    temp = temp->next;
  }
}

// traverse functions
template <class keyType, class valueType>
void Map<keyType,valueType>::first () {
  // resets the traversal to a "first" element and throws an exception
  // of type "NoSuchElementException" if the list is empty
  if (head == NULL) {
    throw NoSuchElementException("List was empty!\n");
  }
  leader = head;
  //cerr << "leader key: " << leader->key << endl;
}

template <class keyType, class valueType>
void Map<keyType,valueType>::next () {
  // traverses the list from the leader to the next element,
  // throws exception "NoSuchElementException" if nothing to traverse
  if (head == NULL || leader == NULL) {
    throw NoSuchElementException("List was empty or not being traversed!\n");
  }
  if (leader->next == NULL) {
    throw NoSuchElementException("No more elements in the list!\n");
  }
  leader = leader->next;
  //cerr << "leader key: " << leader->key << endl;
}

template <class keyType, class valueType>
const keyType & Map<keyType,valueType>::getCurrentKey() {
  // returns current element's (leader's) key
  if (leader == NULL) {
    throw NoSuchElementException("Not traversing the list! No key.\n");
  }
  return leader->key;
}

template <class keyType, class valueType>
const valueType & Map<keyType,valueType>::getCurrentValue() {
  // returns current elements' (leader's) value
  if (leader == NULL) {
    throw NoSuchElementException("Not traversing the list! No value.\n");
  }
  return leader->value;
}


// helper functions
template <class keyType, class valueType>
bool Map<keyType,valueType>::keyExists (const keyType & key) const {
  // Checks to see if the key exists already, returns true if it does
  MapItem<keyType,valueType>* temp = head;
  while (temp != NULL) {
    if (temp->key == key) {
      return true;
    }
    temp = temp->next;
  }
  return false;
}

template <class keyType, class valueType>
void Map<keyType,valueType>::printKey() const {
    // Print list of keys and values associated with the keys;
    // tester function (can be ignored)
  int count = 1;
  MapItem<keyType,valueType>* temp = head;
  if (temp == NULL) {
    cout << "List is empty.\n";
  }
  while (temp != NULL) {
    cout << "Item " << count << ": " << temp->key << ", " << temp->value << endl;
    count++;
    temp = temp->next;
  }
}

template <class keyType, class valueType>
bool Map<keyType,valueType>::leaderGet() const {
  // see if next leader/head item exists; returns true if it does
  if (head == NULL) {
    return false;
  }
  return true;
}

template <class keyType, class valueType>
bool Map<keyType,valueType>::leaderNext() const {
  // see if next search/traverse item exists; returns true if it does
  if (leader->next == NULL) {
    return false;
  }
  return true;
}

template <class keyType, class valueType>
void Map<keyType,valueType>::printError(string errorMessage) const {
  cout << errorMessage << endl;
}

template <class keyType, class valueType>
void Map<keyType,valueType>::setError(string addMsg, string remMsg, string getMsg) {
  cannotAdd = addMsg;
  cannotRemove = remMsg;
  cannotGet = getMsg;
}

template <class keyType, class valueType>
string Map<keyType,valueType>::getAddErr() const {
  return cannotAdd;
}

template <class keyType, class valueType>
string Map<keyType,valueType>::getRemErr() const {
  return cannotRemove;
}

template <class keyType, class valueType>
string Map<keyType,valueType>::getGetErr() const {
  return cannotGet;
}
