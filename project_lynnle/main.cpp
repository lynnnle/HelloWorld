#include "Movie.h"
#include <iostream>
#include <string>
using namespace std;

int main () {
  Movie test("Movie 1");
  test.addKeyword("Inigo Montoya");
  test.addKeyword("Comedy");
  test.addKeyword("Robin Wright");
  cout << "Title: " << test.getTitle() << endl;
  Set<string> keywords = test.getAllKeywords();
  cout << "Keywords:\n";
  keywords.printKey();

  Movie copy(test);
  cout << "Copied title: " << copy.getTitle() << endl;
  keywords = copy.getAllKeywords();
  cout << "Keywords:\n";
  keywords.printKey();

  return 0;
}
