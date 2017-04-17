#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <cstring>

using namespace std;

//////////////////////////////////////////////////////////////////////////////
// 23강 복사(copy)와 이동(move)을 동시에 지원하기
//////////////////////////////////////////////////////////////////////////////


class Cat
{
    char* name;
    int age;

public:
    Cat(const char* n, int a) : age(a)
    {
        name = new char[strlen(n) + 1];
        strcpy(name, n);
    }

    ~Cat() { delete[] name; }


    Cat(const Cat& c)
    {
        age = c.age;

        name = new char[strlen(c.name) + 1];
        strcpy(name, c.name);

        cout << "copy" << endl;
    }

    // 이동 생성자 - 소유권 이전...
    Cat(Cat&& c) : age(c.age), name(c.name) //얕은 복사
    {
        c.name = 0;
        cout << "move" << endl;
    }
};


template<typename T> T&& xmove(T& c)
{
    return static_cast<T&&>(c);
}

int main()
{
    Cat c1("nabi", 5);

    Cat c2 = c1;        //복사 생성자 호출..

    Cat c3 = static_cast<Cat&&>(c1);
    Cat c4 = xmove(c1);
}


