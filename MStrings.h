/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MStrings.h
 * Author: andre
 *
 * Created on 15 апреля 2019 г., 16:13
 */

#ifndef MSTRINGS_H
#define MSTRINGS_H

#include <iostream>
#include <cstddef>
#include <limits>

class MStrings {
private:
    char * _str;
    size_t _size;
    
public:
    MStrings(const char* chstr);
    MStrings(const MStrings &str);
    
    
    ~MStrings();
    
    size_t size() const;
    inline const char* data() const {return _str;}
    MStrings& operator=(const MStrings &);
    
    friend bool operator==(const MStrings & str1, const MStrings & str2);
    friend bool operator!=(const MStrings & str1, const MStrings & str2);
    
    friend bool operator<(const MStrings & str1, const MStrings & str2);  
    friend bool operator>(const MStrings & str1, const MStrings & str2);
    
    
    friend bool operator>=(const MStrings & str1, const MStrings & str2);
    friend bool operator<=(const MStrings & str1, const MStrings & str2);
    
    int index (char ch) const;
    
    const char& operator[](const int i) const;
   // char operator[](const int j); 
    
    MStrings & operator += (const MStrings& str);
    friend MStrings operator +(const MStrings & origStr, const MStrings & secondStr);
    
    MStrings & operator -= (const MStrings& str);
    
    friend MStrings operator -(const MStrings & origStr, const MStrings & delStr);
    
    operator const char*() const;
    
    //ToDo operator+=, operator-=, operator+, append, insert
    
    MStrings & insert(size_t pos, const MStrings & origstr, size_t countSymbols);
    
    MStrings appendif(size_t pos, const MStrings & origstr, size_t countSymbols);
    
    MStrings & push_back(const MStrings& str);
    
    MStrings & push_front(const MStrings& str);
    
    MStrings & remove(size_t pos, size_t n);
    
    MStrings & pop_front();
    
    MStrings & pop_back();
    
    friend MStrings operator,(const MStrings& str1,
                              const MStrings& str2);
    
    //встроенные операторы не перегружаются
    //friend MStrings operator,,(const MStrings& str1, const MStrings& str2);
    
    //
    //friend MStrings operator.(const MStrings& str1, const MStrings& str2);

    MStrings & replace(const MStrings & fromFormatStr, 
                       const MStrings & toFormatStr, 
                       const int numberEntries = std::numeric_limits<int>::max());
};

#endif /* MSTRINGS_H */

