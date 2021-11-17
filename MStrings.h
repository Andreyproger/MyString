#ifndef MString_H
#define MString_H

#include <limits>
#include <cstddef>
#include <iostream>

class MString{
private:
    char * _str;
    size_t _size;
    
public:
    MString(const char* chstr);
    MString(const MString &str);
    
    ~MString();
    
    size_t size() const;
    inline char* data() {return _str;}
    MString& operator=(const MString &);
    
    friend bool operator==(const MString & str1, const MString & str2);
    friend bool operator!=(const MString & str1, const MString & str2);
    
    friend bool operator<(const MString & str1, const MString & str2);  
    friend bool operator>(const MString & str1, const MString & str2);
    
    
    friend bool operator>=(const MString & str1, const MString & str2);
    friend bool operator<=(const MString & str1, const MString & str2);
    
    int index (char ch) const;
    
    const char& operator[](const int i) const;
   // char operator[](const int j); 
    
    MString & operator += (const MString& str);
    friend MString operator +(const MString & origStr, const MString & secondStr);
    
    MString & operator -= (const MString& str);
    
    friend MString operator -(const MString & origStr, const MString & delStr);
    
    operator const char*() const;
    
    //ToDo operator+=, operator-=, operator+, append, insert
    
    MString & insert(size_t pos, const MString & origstr, size_t countSymbols);
    
    MString appendif(size_t pos, const MString & origstr, size_t countSymbols);
    
    MString & push_back(const MString& str);
    
    MString & push_front(const MString& str);
    
    MString & remove(size_t pos, size_t n);
    
    MString & pop_front();
    
    MString & pop_back();
    
    friend MString operator,(const MString& str1,
                              const MString& str2);
    
    //встроенные операторы не перегружаются
    //friend MString operator,,(const MString& str1, const MString& str2);
    
    //
    //friend MString operator.(const MString& str1, const MString& str2);

    MString & replace(const MString & fromFormatStr, 
                       const MString & toFormatStr, 
                       const int numberEntries = std::numeric_limits<int>::max());
    
};

#endif /* MString_H */