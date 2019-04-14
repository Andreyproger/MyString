#include <iostream>
#include <cstring>
#include <string.h>

MyString & MyString::replace(const MyString & fromFormatStr,
                             const MyString & toFormatStr,
                             const int numberEntries)
{
  if (0 > numberEntries)
    return *this;
    
  const char * fountStr = strstr(_str, fromFormatStr._str);
  
  if (!foundStr)
    return *this;
    
  if ((toFormatStr.size() > _size) ||
      (formFormatStr.size() < toFormatStr._size))
  {
    cout << "Exit!" << endl;
    return *this;
  }
      
}
