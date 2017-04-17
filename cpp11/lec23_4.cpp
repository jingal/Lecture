#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <cstring>

using namespace std;

//////////////////////////////////////////////////////////////////////////////
// 23강 move 지원 클래스 만들기

//////////////////////////////////////////////////////////////////////////////

class Cat
{
    string name;
    int age;

public:
    Cat(string s, int a) : name(s), age(a) {}

    //복사 생성자
    Cat(const Cat& c) : name(c.name), age(c.age) 
    {
        cout << "copy ctor" << endl;
    }

    /*
    //이동 생성자
    Cat(Cat&& c) : name(move(c.name)), age(c.age)
    {
        cout << "move ctor" << endl;
    }
    */


    //대입 연산자
    Cat& operator=(const Cat& c)
    {
        name = c.name;
        age = c.age;

        cout << "copy = " << endl;
        return *this;
    }
};


int main()
{
    Cat c1("nabi", 2);
    Cat c2("yaong", 3);

    swap(c1, c2);
}


