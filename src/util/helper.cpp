#include <gram/util/helper.h>

std::vector<std::string> gram::util::explode(std::string string, std::string delimiter) {
  std::vector<std::string> pieces;

  unsigned long end = string.find(delimiter);

  while (end != std::string::npos) {
    pieces.push_back(string.substr(0, end));

    string = string.substr(end + delimiter.length());

    end = string.find(delimiter);
  }

  pieces.push_back(string);

  return pieces;
}
