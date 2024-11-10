// util/sharedptr1.cpp
//for compiling use option -qlanglvl=rightanglebracket
#define __IBMCPP_TR1__ 1
#include <iostream>
#include <string>
#include <vector>
#include <memory>
using namespace std;
using namespace std::tr1;
int main()
{
// two shared pointers representing two persons by their name
shared_ptr<string> pNico(new string("nico"));
shared_ptr<string> pJutta(new string("jutta"));
// capitalize person names
(*pNico)[0] = 'N';
pJutta->replace(0,1,"J");
// put them multiple times in a container
vector<shared_ptr<string> > whoMadeCoffee;
whoMadeCoffee.push_back(pJutta);
whoMadeCoffee.push_back(pJutta);
whoMadeCoffee.push_back(pNico);
whoMadeCoffee.push_back(pJutta);
whoMadeCoffee.push_back(pNico);
// print all elements
//for (auto ptr : whoMadeCoffee) {
//cout << *ptr << " ";
//}
for(vector<shared_ptr<string> >::const_iterator iter=whoMadeCoffee.begin(); iter!=whoMadeCoffee.end(); iter++)
cout << **iter << " ";
cout << endl;
// overwrite a name again
*pNico = "Nicolai";
// print all elements again
for(vector<shared_ptr<string> >::const_iterator iter=whoMadeCoffee.begin(); iter!=whoMadeCoffee.end(); iter++)
cout << **iter << " ";
cout << endl;
// print some internal data
cout << "use_count: " << whoMadeCoffee[0].use_count() << endl;
}
