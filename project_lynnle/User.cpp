User (string ID, string name) {
  /* constructor that generates a user with the given name and ID.
     While multiple users may have the same name, the ID should be unique
     (e.g., an e-mail address), so that users can log in with it. */
  userID = ID;
  username = name;
}

User (const User & other){
  // copy constructor
  userID = other.userID;
  username = other.username;
}

~User () {
  // destructor
}

string getID () const {
  // returns the ID associated with this user
  return userID;
}

string getName () const {
  // returns the name associated with this user
  return username;
}
