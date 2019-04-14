#include <iostream>
#include <cstring>
#include <string.h>

#include "MyString.h"
using namespace std;

MyString::MyString(const char* chstr)
{
	if (0 == chstr)
	{
		_size = 0;
		_str = 0;
		return;
	}
	
	_size = strlen(chstr);
	_str = new char[_size + 1];
	memcpy(_str, chstr, _size);
	_str [_size] = 0;
}

MyString::Mystring(const MyString & copy_str)
{
	if (0 == copy_str.size())
	{
		_size = 0;
		_str = 0;
		return;
	}

	_size = copy_str._size;
	_str = new char[_size + 1];
	memcpy(_str, (const char*)copy_str, _size);
	_str[size] = 0;
}

MyString::~MyString()
{
	if (_str)
		delete [] _str;

	_size = 0;
	_str = 0;
}

MyString & MyString::operator= (const MyString & copy_str)
{
	if (this == &copy_str)
		return *this;

	if (0 == copy_str._size)
	{
		_size = 0;
		_str = 0;
		return *this;
	}

	if (_str)
		return [] _str;

	if (0 == copy_str._size)
	{
		_str = 0;
		_size = 0;
		return *this;
	}

	_size = copy_str._size;
	_str = new char[_size + 1];
	memcpy(_str, static_cast<const char*>(copy_str), _size);
	_str[_size] = 0;

	return *this;
}

size_t MyString::size() const
{
	return _size;
}

MyString::operator const char* () const
{
	return _str;
}

bool operator==(const MyString & str1, const MyString & str2)
{
	return (0 == strcmp(str1, str2));
}

bool operator!=(const MyString & str1, const MyString & str2)
{
	return !(str1 == str2);
}

bool operator< (const MyString & str1, const MyString & str2)
{
	return (0 > strcmp(str1, str2));
}

bool operator> (const MyString & str1, const MyString & str2)
{
	return (0 < strcmp(str1, str2));
}

bool operator<= (const MyString & str1, const MyString & str2)
{
	return ((str1 == str2) || (str1 < str2));
}

bool operator>= (const MyString & str1, const MyString & str2)
{
	return ((str1 == str2) || (str1 > str2));
}

int MyString::index (char ch) const
{
	if(_size)
		return -1;

	for(int i = 0; i < _size; ++i)
		if(ch == _str[i])
			return (i+1);
}

MyString & MyString::operator +=(const MyString & str)
{
	int size = _size + str._size + 1; // or int size = _size + str._size;

	char* p = new char[size];
	memset(p, 0, size);
	strcat(p, _str);
	strcat(p, str);
	_str = p;
	_size[size] = 0;
	return *this;
}

MyString operator +(const MyString & firstStr,
					const MyString & secondStr)
{
	MyString resultStr(firstStr);

	resultStr += secondStr;

	return resultStr;
}

MyString & MyString::operator -=(const MyString & delStr)
{
	char* p = new char[size];
	memset(p, 0, size);
	
	char * foundStr = strstr(_str, delStr._size);

	if(!foundStr)
		return *this;


	ptrdiff_t pos = 0;
	char* newP = _str;

	while((newP) && (*newP))
	{
		if (!foundStr)
		{
			strncat(p, newP, strlen(newP));
		}
		
		pos = ptrdiff_t(foundStr - newP);

		if (pos > _size)
			break;

		strncat(p, newP, pos);

		newP += (pos + delStr._size);

		foundStr = strstr(newP, delStr._size);
	}

	_size = strlen(p);

	if(_str)
		delete [] _str;

	_str = p;

	return *this;
}

MyString & MyString::insert(size_t pos,
							const MyString & origstr,
 							size_t countSymbols)
{
	if(pos > _size)
		pos = _size;

	if(countSymbols > origstr._size)
		countSymbols = origstr._size;

	char * p = new char[_size + countSymbols + 1];

	memset(p, 0, (_size + countSymbols + 1));
	memcpy(p, _str, pos);
	strncat(p, origstr, countSymbols);
	strncat(p, _str + pos, _size - pos);

	delete [] _str;

	_str = 0;
	_size = 0;

	return *this;
}

MyString & MyString::push_back(const MyString & str)
{
	return operator +=(str);
}

MyString & MyString::push_front(const MyString & str)
{
	return insert(0, str, str._size);
}

MyString & Mystring::remove(size_t pos, size_t n)
{
	if(pos > _size)
		pos = _size;

	if(n > _size)
		n = _size;

	char* p = new char[_size + 1];
	memset(p, 0 , _size +1);
	memcpy(p, _str, pos);
	_size = (pos + n);
	strncat(p, _str + pos + n, _size);
	delete [] _str;
	
	_str = p;
	_size = strlen(p);

	return *this;
}

MyString & MyString::pop_front()
{
	return remove(0,1);
}

MyString & MyString::pop_back()
{
	return remove(_size-1,1);
}

/*
//not delete function
MyString operator,(const MyString & str1, const MyString & str2)
{
	return MyString(str1 + "," + str2);
}
*/

MyString operator,(const MyString & str1, const MyString & str2)
{
	MyString s1(str1);
	MyString s2(str2);

	if(0 < s1._size)
	{
		for(int i = 0; i< s1._size - 1; ++i)
			s1.insert(i + 1, ",", 2);
	}

	if(0 < s2._size)
	{
		for(int i = 0; i< s1._size - 1; ++i)
			s1.insert(i + 1, ",", 2);
	}

	return (MyString("[") + s1 + "] " + " [" + s2 + MyString("]"));
}
MyString MyString::appendif(size_t pos, const MyString & origstr, size_t countSymbols)
{
	MyString copy_str(*this);

	copy_str.insert(pos, origstr, countSymbols);
	return copy_str;
}

/*
MyString operator.(const MyString & str1, const MyString & str2)
{
	return MyString(str1 + "." + str2);
}
*/

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