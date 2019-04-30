#include <cstdlib>
#include <iostream>
#include <string.h>
#include <cassert>
#include <vector>
#include "MStrings.h"

using namespace std;

struct strStruct
{
    std::string printStr;
    int length;
    
    strStruct()
    {
        printStr = string("Andrey");
        length = printStr.size();
    }
    
    ~strStruct()
    {}
    
    void print()
    {
        cout << "Output string: " << printStr << "." << endl 
             << "Length of string: " << length << "." << endl;
    }
};

template<class T, int S>
class MyClass
{
private:
    T* _array;
    int _size;
 
public:

    MyClass():
          _size(0)
        , _array(0)
        {
            std::cout << "S = " << S << endl;
        }
    
    
    
    ~MyClass()
    {
        if(_size)
            delete [] _array;
        
        _array = 0;
        _size = 0;
    }
    
    
    
    MyClass(const T* array, int size):
          _size(size),
          _array(0)
    {
        _array = new T[_size];
        memcpy(_array, array, size*sizeof(T));
        
        for(int i = 0; i < size; i++, _array++)
            _array->print();
    }
    
    
    
    MyClass(const MyClass<T, S>& copy_obj):
          _size(S)
        , _array(new T[_size])
    {
        _array = copy_obj._array;
        memcpy(_array, copy_obj._array, _size*sizeof(T));
    }
    
      
    MyClass& operator=(const MyClass<T,S>& value)
    {
        
        if(this == &value)
            return *this;
        
        if(_array)
            delete[] _array;
        
        if(0 == S)
        {
            _array = 0;
            _size = 0;
            return *this;
        }
        
        _size = S;
        
        assert(0 <= _size);
        
        _array = value._array;
        
        return *this;
    }
    
    operator const T*() const
    {
        return _array;
    }
    
    T func(T i)
    {
        return i;
    }
};

//specialization 
/*template<> 
MyClass<int>::operator const int*() const
{
    return (const int*)(this->_array);
}

template<>
MyClass<int>&::MyClass<int>::operator=(const MyClass<int>& value)
{
    if(this == &value)
        return *this;
    
    if(_array)
        delete[] _array;
        
    if(0 == value._size)
        {
            _array = 0;
            _size = 0;
            return *this;
        }
        
        _size = value._size;
        
        assert(0 <= _size);
        
        _array = value._array;
        
        return *this;
}

template<>
int MyClass<int>::func(int i)
{
    return i;
}*/

template<int S> class MyClass<char, S>
{
    public:
        
    MyClass()
    : _array(0),
      _size(0)
    {};
    
    
    
    MyClass(const char* array, int size):_array(0), _size(0)
    {
        if (0 == array || 0 == size)
            return;
        
        std::cout << "-------------------------------+++++++++++++++++++++++=" << endl;
        MStrings str(array);
        _array = new char[str.size() + 1];
        
        memcpy(_array, str.data(), str.size());
        _array[str.size()] = 0;
        _size = str.size();
    }
    
    
    
    ~MyClass()
    {
        if (_size)    
            delete [] _array;

        _array = 0;
        _size = 0;
    }
    
private:
    char* _array;
    int _size;
};


template<int N> class MyClass<std::vector<double>, N >
{
    public:
        MyClass(const std::vector<double>& vec, int size)
            : _vec(0), _size(0)
        {
            if(0 == size)
                return;
                
            std::cout << "-------------VECTOR------------------+++++++++++++++++++++++=" << endl;
            
            _vec = vec;
            _size = vec.size();
            
            for(int i = 0; i < vec.size();i++)
            {
                cout << vec[i] << endl;
            }
        
            
        ~MyClass()
        {
            if(_vec)
                delete [] _vec;
                
            _vec = 0;
            _size = 0;
        };
                
        
private:
    std::vector<double> _vec;
    int _size;
};

int main(int argc, char** argv) {
    
    const char* ch = "bsdfsdfdfs00";
    const std::string str = string("abcdefg");
    int i = 5;
    int val[2];
    const int len = sizeof("bsdfsdfdfs00")-1;
    //MyClass<std::string,0> m(&str,6);
    
    const int N = 5;
    
    strStruct temp[N];
    
    MyClass<strStruct, 5> obj(&temp,5);
    
    return 0;
}
