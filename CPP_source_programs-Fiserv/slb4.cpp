#include <iostream>
template<int N>
class P {
public:
    static void print() {
         P<N-1>::print();
         std::cout << N << std::endl;
    }
};

template<>
class P<1> {
public:
    static void print() {
      std::cout << 1 << std::endl;
    }
};

int main() {
    const int N = 25;
    P<N>::print();
    return 0;
}
