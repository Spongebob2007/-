#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //////////////////////////////////
    string number;
    for (std::string s; number.size() < 1000 && cin >> s; number += s);  // считывание в строку строк длинной не более 1000 букв
   ////////////////////////////////////
    int n;
    cin >> n;
    vector<int> v(n);   
    for (auto& it : v) // считывание данных в вектор
        cin >> it;
    for(auto& i:v)     // вывод данных из вектора
        cout<<i;
}
