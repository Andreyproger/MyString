#pragma once

class MyString
{
	MyString(const char* chstr);
	MyString(const MyString & copy_str);

	~MyString();
	
	size_t size() const;

	operator const char*() const;

	bool operator==(const MyString & str1, const MyString & str2);
	bool operator!=(const MyString & str1, const MyString & str2);

	bool operator<(const MyString & str1, const MyString & str2);
	bool operator>(const MyString & str1, const MyString & str2);

	bool operator<=(const MyString & str1, const MyString & str2);
	bool operator>=(const MyString & str1, const MyString & str2);

	int index(char ch) const;

	MyString & operator +=(const MyString & str);
	MyString operator +(const MyString & firstStr,
					const MyString & secondStr);

	MyString operator -=(const MyString & delStr);

	MyString & insert(size_t pos,
				    const MyString & origstr,
 					size_t countSymbols);

	MyString & push_back(const MyString & str);

	MyString & MyString::push_front(const MyString & str);

MyString & remove(size_t pos, size_t n);

MyString & pop_front();

MyString & pop_back();

/*
//not delete function
MyString operator,(const MyString & str1, const MyString & str2)
{
	return MyString(str1 + "," + str2);
}
*/

MyString operator,(const MyString & str1, const MyString & str2);
MyString appendif(size_t pos, const MyString & origstr, size_t countSymbols);


/*
MyString operator.(const MyString & str1, const MyString & str2)
{
	return MyString(str1 + "." + str2);
}
*/

MyString replace(const MyString & fromFormatStr,
                             const MyString & toFormatStr,
                             const int numberEntries);
};