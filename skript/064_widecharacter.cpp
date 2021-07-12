#include <clocale>
#include <codecvt>
#include <cwchar>
#include <iostream>

using namespace std;

int main(void) {
  setlocale(LC_ALL, "de_DE.utf8");  // Umgebung richten
  std::wcout.imbue(std::locale("de_DE.utf8"));
  string s1{"abc"};  // nicht mehr ausgeben, kein cout mehr
  std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> cvt;
  wstring s1w = cvt.from_bytes(s1);  // nur noch wstring ausgeben
  wstring w1{L"abc"};
  const wchar_t* w2 = L"abcä";
  wstring w3{L"abcä"};
  wcout << "s1: size =" << s1.size() << ", |";
  wcout << setw(6) << s1w << "|" << endl;
  wcout << " length =" << s1.length();
  wcout << ", capacity=" << s1.capacity() << endl;
  wcout << "w1: length =" << w1.length() << ", |";
  wcout << setw(6) << w1 << "|" << endl;  // wcout statt cout
  wcout << "w2: length =" << wcslen(w2) << ", |";
  wcout << setw(6) << w2 << "|" << endl;  // wcout statt cout
  wcout << "w3: length =" << wcslen(w3.c_str()) << ", |";
  wcout << setw(6) << w3 << "|" << endl;  // wcout statt cout
}
