// array::data
#include <iostream>
#include <cstring>
#include <array>
using namespace std;
using namespace std::tr1;


int main ()
{
  const char* cstr = "Test string";
  array<char,12> charray;

  std::memcpy (charray.data(),cstr,12);

  std::cout << charray.data() << '\n';

  return 0;
}
