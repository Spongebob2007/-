#include <iostream>
using namespace std;

int gcd(int a, int b) {
   int t;
   while (b) {
     t = a % b;
     a = b;
     b = t;
     cout<<a<<" "<<b<<"\n";
   }
   return abs(a);
}


int main() {

    int a, b;
    cin >> a >> b;
    cout<<gcd(a,b);
}
