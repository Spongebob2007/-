#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie();
    char s[10];
    cin>>s;
    int scan1;
    int scan2;
    int scan3;
    scanf("%d,%d,%d", &scan1, &scan2, &scan3);
    cout<<scan1<<":"<<scan2<<":"<<scan3;
    //substr - вырез символов или atoi 
    int date1 = (s[0] - '0') * 10 + (s[1] - '0'); // считывание данных с string в C++ при помощи ASCII кодов
    int date2 = (s[3] - '0') * 10 + (s[4] - '0'); // умножаем первое число на 10, чтобы оно стало большим 9, то есть делаем из 9 - 90
    int date3 = (s[6] - '0') * 10 + (s[7] - '0');
    cout<<date1<<":"<<date2<<":"<<date3;
    return 0;
}
