#include <iostream>
#include <cstring>

class Line {
public:
  char *line;
  Line() {
    line = 0;
  }
  Line(const char *s) {
    line = new char[strlen(s)+1];
    strcpy(line, s);
  }
  ~Line() {
    delete[] line;
    line = 0;
  }
  Line &operator=(const Line &other) {
   delete[] line;
    Line = new char[other.len()+1];
    strcpy(line, other.line);
    return *this;
  }
  int len(void) const {return strlen(line);}
};

int main() {
  Line n1("n1");
  Line n2 = n1;
}
