#include<iostream>
#include<string>
using namespace std;


int main()
{
string ss ="L\"\\?\\UNC\\10.1.3.23\\TOKEN$\\0x432567\\C\\FileDrive\\Testcase.doc";

std::cout << ss<< "\n";
std::string::size_type n = ss.find("TOKEN$");

if (n == std::string::npos) {
std::cout << "not found\n";
} else {

std::string::size_type first = ss.find("\\",n);
std::string::size_type last = ss.find("\\",first+1);

ss.replace(first,(last-first),"");
std::cout << "found: " << ss << '\n';
}

return 0;
}
