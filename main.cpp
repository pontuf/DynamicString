// g++ DynamicString.cpp main.cpp

#include "DynamicString.h"
#include <vector>
#include <algorithm>
#include <string.h>
#include <locale.h>

bool comp(DynamicString a, DynamicString b){
    bool r = true;
    if (strcmp(a.getChars(), b.getChars()) < 0)
        r = false; 
    return r;     
}

// получение строк из аргументов командной строки
// либо набор по-умолчанию
int  main(int argc, char* argv[]) {
    setlocale(LC_ALL, "");
    
    std::vector<DynamicString> array;
    if (argc <= 1){
        array.push_back("abc");     
        array.push_back("acb");  
        array.push_back("cab");  
        array.push_back("cba");  
    }    
    else 
        for (int i = 1; i < argc; i++)
            array.push_back(argv[i]);
    
    sort(array.begin(), array.end(), comp);

    for (auto const &element : array)
        std::cout << element << std::endl;

    return 0;
}
