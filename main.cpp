#include <iostream>
#include <cstdlib>
#include <string.h>

using namespace std;

#define CHR static_cast<const char*>
#define CIN static_cast<const int*>

int main()
{
  MyString mystr("ASDASDKD");
  cout << CHR() << endl;
  
  MyString secondMystr("ASDASD");
  
  //cout << *CIN(secondMystr) << endl;
  
  cout << secondMystr <<endl;
  
  cout << boolalpha << (mystr == secindMystr) << endl;
  cout << boolalpha << (mystr != secindMystr) << endl;
  cout << boolalpha << (mystr > secindMystr) << endl;
  cout << boolalpha << (mystr < secindMystr) << endl;
  
  cout << boolalpha << (mystr <= secindMystr) << endl;
  cout << boolalpha << (mystr >= secindMystr) << endl;
  
  cout << secondMystr.index('K') << endl;
  
  secondMystr += MyString("asd!");
  
  cout << secondMystr << endl;
  
  MyString s("123");
  
  MyString s1("A1A23A");
  
  cout << "::strspn(s, s1): " << ::strspn(s, s1) << endl;
  
  //MyString testStr("abc");
  //cout << (testStr -= MyString("bc")) << endl;
  //cout << (s1 -=) << endl;
  
  MyString newstr("abcd12vg12c");
  
  //cout << "********************************* newstr - aba: " << (newstr -= MyString("12")) << endl;
  //cout << newstr << endl;
  
  MyString str1 = "123";
  MyString str2 = "456";
  
  str1.insert(200, str2, 300);
  
  cout << str1 << endl;
  
  MyString str3 = "123456";
  
  str3.push_back("789");
  cout << str3 << endl;
  
  str3.push_front("ABC");
  cout << str3 << endl;
  
  cout << (str3.remove(0,9)) << endl;
  
  MyString str4 = "-123456789+";
  str4.pop_back();
  
  cout << str4 << endl;
  
  str4.pop_front();
  
  cout << "sss1: " << str3 << " " << str4 << endl;
  
  MyString sss2((str3, str4));
  
  cout << "sss2: " << sss2 << endl;
  
  return 0;
  
  //cout << CHR(newstr) << endl;
  //cout << (mystr_dubl == mystr) << endl;
  
  //return 0;
  
}
