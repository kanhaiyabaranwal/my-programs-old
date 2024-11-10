#include <iostream>
class C {
public:
  ~C() {
    std::cout << "~C";
  }
};

class D : public C {
public:
  ~D() {
    std::cout << "~D";
  }
};

int main() {
  C *c1 = new C(), *c2 = new D();
  delete c1;
  delete c2;
  return 0;
}
