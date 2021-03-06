#include <iostream>
#include <cstring>
#include "header/file.h"
#include "header/common.h"

using namespace std;


int StringMe::num_strings = 0;

StringMe::StringMe(const char *s) : myyear(0),values(0)
{
    show("StringMe::StringMe(const char *s)\n");
    len = std::strlen(s);
    str = new char[len + 1];
    std::strcpy(str, s);
    num_strings ++;
}

StringMe::StringMe(const StringMe & st):values(0)
{
    show("StringMe::StringMe(const StringMe &)\n");
    num_strings++;
    len = st.len;
    str = new char[len + 1];
    std::strcpy(str, st.str);
}

StringMe::StringMe():values(0)
{
    show("StringMe::StringMe()\n");
    len = 5;
    str = new char[len + 1];
    std::strcpy(str, "empty");
    num_strings++;
}

StringMe::~StringMe()
{
    show("~StringMe::StringMe()\n");
    print();
    delete [] str;
    num_strings--;
}

std::ostream & operator<<(std::ostream & os,
                          const StringMe & st)
{
    os << st.str;
    return os;
}

void StringMe::print(void)
{
    cout << "str: " << str << endl;
    cout << "num_strings: " << num_strings << endl;
}

StringMe & StringMe::operator=(const StringMe & st)
{
    show("StringMe & StringMe::operator=(const StringMe & st)\n");
    
    if (this == &st) {
        return *this;
    }

    delete [] str;
    len = st.len;
    str = new char [len + 1];
    std::strcpy(str, st.str);

    return *this;
}

StringMe & StringMe::operator=(const char * s)
{
    show("StringMe & StringMe::operator=(const char * s)\n");         
    delete [] str;
    len = std::strlen(s);
    str = new char[len+1];
    std::strcpy(str, s);
    return *this;
}

 char & StringMe::operator[](int i)
 {
    show("char & StringMe::operator[](int i)\n");     
    return str[i];
 }

const char & StringMe::operator[](int i) const
 {
    show("const char & StringMe::operator[](int i) const\n");     
    return str[i];
 }

reStringMe::reStringMe (const char * str, int r) : StringMe(str)
{
    show("reStringMe::reStringMe (int r, const char * str) : StringMe(str)\n");         
    rating = r;
}

reStringMe::reStringMe (int r, const StringMe & s) : rating(r), StringMe(s)
{
    show("reStringMe::reStringMe (int r, const StringMe & s) : rating(r), StringMe(s)\n");         
}

reStringMe::~reStringMe()
{
    show("reStringMe::~reStringMe()\n");      
}