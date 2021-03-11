#include "DynamicString.h"

DynamicString::DynamicString(const char *str) {
    length = strlen(str);
    string = new char[length + 1];
    assert(string != 0);
    strcpy(string, str);
}

DynamicString::DynamicString(const DynamicString &str) {
    length = str.length;
    string = new char[length + 1];
    assert(string != 0);
    strcpy(string, str.string); 
}

const DynamicString &DynamicString::operator=(const DynamicString &right) {
    if (this != &right) {
        delete [] string;
        length = right.length;
        string = new char[length + 1]; 
        assert(string != 0);
        strcpy(string, right.string);
    }

    return *this;
}

DynamicString operator+(const DynamicString &left, const DynamicString &right) {
    size_t len = left.length + right.length;
    char *str = new char[len + 1];
    assert(str != 0);
    strcpy(str, left.string);
    strcat(str, right.string);
    DynamicString res(str);
    delete [] str;
    return res; 
}

DynamicString &DynamicString::operator=(DynamicString&& str) {
    string = str.string; 
    length = str.length; 

    str.string = nullptr;

    return *this;
}

DynamicString::DynamicString(DynamicString &&str) {
    string = str.string; 
    length = str.length; 

    str.string = nullptr;
}

std::ostream &operator<<(std::ostream &out, const DynamicString &str) {
    out << str.string;
    return out;
}

const char *DynamicString::getChars() {
    return string;
}

DynamicString::~DynamicString() {
    delete [] string;
}
