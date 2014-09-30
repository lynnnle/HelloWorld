#include "Movie.h"

#include <string>
using namespace std;

Movie::Movie (string title) {
  // constructor for a movie with the given title
  movieTitle = title;
  keywords.setError("Cannot add keyword to database","Keyword was not in database","Cannot retrieve keyword from database");
}

Movie::Movie (const Movie & other) {
  // copy constructor
  //cerr << "entered copy constructor\n";
  movieTitle = other.movieTitle;

  //cerr << "next step is merge keyword list\n";
  keywords.merge(other.keywords);

  //cerr << "set errors\n";
  keywords.setError(other.getAddErr(), other.getRemErr(), other.getGetErr() );

  //cerr << "done with copy constructor\n";
}

Movie::~Movie () {
  // destructor
  //cerr << "calling Movie destructor\n";
}

string Movie::getTitle () const {
  // returns the title of the movie
  return movieTitle;
}

void Movie::addKeyword (string keyword) {
  /* Adds the (free-form) keyword to this movie.
     If the exact same keyword (up to capitalization) was already
     associated with the movie, then the keyword is not added again. */
  keywords.add(keyword);
}

Set<string> Movie::getAllKeywords () const {
  /* Returns a set of all keywords associated with the movie. */
  return keywords;
}

string Movie::getAddErr() const {
  return keywords.getAddErr();
}

string Movie::getRemErr() const {
  return keywords.getRemErr();
}

string Movie::getGetErr() const {
  return keywords.getGetErr();
}
