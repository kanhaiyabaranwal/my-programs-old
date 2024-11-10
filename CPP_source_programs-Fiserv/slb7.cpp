#include <iostream>
#include <cstring>

class Line {
public:
  char *line;
  Line(const char *s = 0) {
    if (s) {
      line = new char[strlen(s)+1];
      strcpy(line, s);
    } else {
      line = 0;
    }
  }
  ~Line() {
    delete[] line;
    line = 0;
  }
  Line &operator=(const Line &other) {
    delete[] line;
    line = new char[other.len()+1];
    strcpy(line, other.line);
    return *this;
  }
  int operator<=(const Line &other) {
    int cmp = strcmp(line, other.line);
    return cmp <= 0;
  }
  int len() const {return strlen(line);}
};

int main() {
  Line array[] = {Line("navin"), Line("kabra"),
                  Line("amit"), Line("paranjape")};
  Line tmp;
  for(int i=0; i<4; i++) {
    for(int j=i; j<4; j++) {
      if(array[i] <= array[j]) {
        tmp = array[i];
        array[i] = array[j];
        array[j] = tmp;
      }
    }
  }
  for(int i=0; i<4; i++) {
    std::cout << array[i].line << std::endl;
  }
}
