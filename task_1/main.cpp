#include <iostream>
#include <locale>
#include <cctype>
#include <codecvt>
#include <typeinfo>
#include "modAlphaCipher.cpp"
using namespace std;

void check(const wstring& Text, const wstring& key, const bool destructCipherText=false)
{ 
try {
	 wstring cipherText;
     wstring decryptedText;
     modAlphaCipher cipher(key);
     cipherText = cipher.encrypt(Text);
     if (destructCipherText)
        cipherText.front() = towlower(cipherText.front());
     decryptedText = cipher.decrypt(cipherText);
     wcout<<L"key="<<key<<endl;
     wcout<<Text<<endl;
     wcout<<cipherText<<endl;
     wcout<<decryptedText<<endl;
 } catch (const cipher_error & e) {
        wcerr<<"Error: "<<e.what()<<endl;
  }
}
	
int main(int argc, char **argv)
{ 	locale loc("ru_RU.UTF-8");
    locale::global(loc);
	check(L"СПАСИОТСЕССИИ",L"Спасу");
	check(L"СПАСИОТСЕССИИ",L"");
	check(L"СПАСИ",L"ОТ СЕССИИ472");
	check(L"Н Е С П А С У",L"СПАСИОТСЕССИИ");
	check(L"123456789",L"СПАСУ");
	check(L"СЕССИЯ",L"АБВГ",true);
return 0;
}
