#include <iostream>

using namespace std;

bool isPalindrome(int n,int p);
int findP(int n);
int main()
{
int n = 123321;
int p;
p = findP(n);
cout<<isPalindrome(n,p);

}
int findP(int n)
{
    int factor = 1;
    while(n >= 10)
    {
       n /= 10;
       factor *= 10;
    }
    return factor;
}
bool isPalindrome(int n,int p)
{

    int f,s,t;
    if(n / 10 > 0)
        {
           int f = n/p;
           int s = n%10;
           if(f == s)
           {
               t = n%p;
               n = t;
               return isPalindrome(n/10,p/100);
           }
           else return false;

        }
    else
    {
        return true;
    }
}