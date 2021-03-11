#ifndef DYNAMICSTRING_H
#define DYNAMICSTRING_H

#include <iostream>

class DynamicString {
friend DynamicString operator+(const DynamicString &, const DynamicString &); // внешний оператор сложения

friend std::ostream &operator<<(std::ostream &, const DynamicString &); // оператор вывода

public:
    const DynamicString &operator=(const DynamicString &); // оператор присваивания
    DynamicString(const char * = ""); // конструктор
    DynamicString(const DynamicString &); // конструктор копирования

    DynamicString(DynamicString &&); // move конструктор
    DynamicString &operator=(DynamicString &&); // move присваивание
    
    const char *getChars(); 
    
    ~DynamicString(); 

private:
    char *string; // сама строка 
    size_t length; // длина
};

#endif // DYNAMICSTRING_H
