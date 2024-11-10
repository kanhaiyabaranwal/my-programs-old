#include <iostream>

class Other {
public:
  ~Other() {
    std::cout << "Other Destroyed";
  }
};

class Base {
};

class Derived : public Base {
private:
  Other o;
};

int main() {
  Base *b = new Derived();
  delete b;
}
