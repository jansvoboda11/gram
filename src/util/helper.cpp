#include <gram/util/helper.h>

using namespace std;

vector<string> gram::explode(string input, string delimiter) {
  vector<string> pieces;

  unsigned long end = input.find(delimiter);

  while (end != string::npos) {
    pieces.push_back(input.substr(0, end));

    input = input.substr(end + delimiter.length());

    end = input.find(delimiter);
  }

  pieces.push_back(input);

  return pieces;
}
