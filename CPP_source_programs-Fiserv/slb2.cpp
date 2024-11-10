#include <iostream>
#include <cstring>



class Name {
  char *name;
private:
  void set_name(const char *name = 0) {
  	if(this->name)				//need to check if name exists
    	delete [] this->name;
    if (name) {
      this->name = new char[strlen(name) + 1];
      strcpy(this->name, name);
    } 
	else {							
      this->name = 0;
    }
  }
public:
  Name(const char *name = 0) {
    this->name = 0;
    set_name(name);
  }
  ~Name() {
  	if(this->name)					//delete only if name exists
    	delete [] this->name;
    this->name = 0;
  }
  
  int len() const {return name ? strlen(name) : 0;}
  friend std::istream& operator>>(std::istream &is, Name &);
  friend std::ostream& operator<<(std::ostream &os, const Name &);
  Name& operator=(const Name& n1);						//need overloaded assignment operator 
};

Name& Name::operator=(const Name& n1)
{
	if(&n1!=this)
	{
		if(this->name)
			delete []this->name;
		set_name(n1.name);
	}
	return *this;
		
}

/* Do not make any changes below this point */

std::istream& operator>>(std::istream &is, Name &n) {
  std::string temp;
  std::getline(std::cin, temp);
  n.set_name(temp.c_str());
  return is;
}

std::ostream& operator<<(std::ostream &os, const Name &n) {
  os << (n.name ? n.name : "<None>") << std::endl;
  return os;
}

int main() {
  Name longest;
  
  while (std::cin) {
    Name temp;
    std::cin >> temp;
	if (longest.len() < temp.len()) {
      longest = temp;
    }
  }
  std::cout << "Longest name = " << longest;
}
