#pragma once
#include <string>
#include <iostream>
#include <cctype>
#include <locale>
#include <codecvt>

class coder
{
private:
	std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> codec;
	int key1;
    int getValidKey(std::wstring & ws_key);
    std::wstring getValidOpenText(const std::wstring & ws_open_text);
    std::wstring getValidCipherText(const std::wstring & ws_cipher_text);
public:
    coder()=delete; // запрет конструктора без параметров
    coder(std::wstring & ws_key);
    std::wstring encrypt(const std::wstring& open_text); // зашифрование
    std::wstring decrypt(const std::wstring& cipher_text); // расшифрование
};

class cipher_error: public std::invalid_argument {
public:
	explicit cipher_error (const std::string& what_arg):
		std::invalid_argument(what_arg) {}
	explicit cipher_error (const char* what_arg):
		std::invalid_argument(what_arg) {}
};
