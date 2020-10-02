#include <iostream>
#include <vector>
using namespace std;

typedef long long int ll;
int main()
{
    ll n;
    int min = 0;
    cin >> n;
    vector<ll> v(n);
    // v.resize(s);
    for (auto& it : v)
        cin >> it;
    idx = 2; // Удаляем элемент с 3 элементом
    vec.erase(vec.begin() + idx);
  
    const auto [min, max] = minmax_element(begin(v), end(v));  // нахождение максимального и минимального значения вектора
    cout<<"Max value in vector "<< *max <<" Min value in vector "<< *min;
    
    return 0;
}
