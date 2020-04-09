#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long int ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll a,b,c;
    cin>>a>>b>>c;
    cout << max(a, max(b,c));
}
