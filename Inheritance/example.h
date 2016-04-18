#include <iostream>
using namespace std;

class Mother 
{
  public:
    Mother ()
    {
		cout << "Mother: no parameters" << endl; 
	}
    Mother (int a, char* name)
    { 
		cout << "Mother: int parameter " << a << endl;
	}
};

class Daughter : public Mother 
{
  public:
    Daughter (int a)
    { 
	  cout << "Daughter: int parameter" << endl;   
	}
};

class Son : public Mother 
{
  public:
    Son (int a) : Mother (a)
    { 
	  cout << "Son: int parameter" << endl; 
	  
	}
};

int main () 
{
	Son Gosho(5);
	Daughter(17);
  
  return 0;
}