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
    Cat() {}                    //일반 생성자
    Cat(const Cat& c) {}        // 복사 생성자 - 참조계수, 깊은 복사
    Cat(Cat&& c) {}             // 이동 생성자 - 소유권 이전..
};

template<typename T> void swap(T& c1, T& c2)
{
    T tmp = move(c1);   // move 생성자 .. move(c1) 리턴은 Cat&&
                        // move 생성자가 있다면 move 호출..
                        // move 생성자가 없다면 copy 생성자 호출
    c1 = move(c2);
    c1 = move(tmp);     //이동 대입연산자도 필요..
}

int main()
{
    Cat c1;
    Cat c2 = c1;                        //복사 생성자 호출..
    Cat c3 = static_cast<Cat&&>(c1);    //이동 생성자..
    Cat c4 = move(c1);                  //이동 생성자..
}


