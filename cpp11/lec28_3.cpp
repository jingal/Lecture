#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <cstring>
#include <functional>
#include <algorithm>
#include <typeinfo>

using namespace std;

//////////////////////////////////////////////////////////////////////////////
// 28강 4. 람다와 인라인 치환
// 28강 5. 람다와 함수 인자
//////////////////////////////////////////////////////////////////////////////

/*
// 4장
// cl 람다와 인라인 치환 /FAs /Ob1 => 어셈 확인
int main()
{
    auto f1 = [](int a, int b){ return a + b; };

    int(*f2)(int, int) = [](int a, int b){ return a + b; }; //클로져 Object는 함수 포인터로 암시적 형변환 가능

    function<int(int, int)> f3 = [](int a, int b){ return a + b; };     //ok..

    //if (n==1) f2 = &foo;

    int n1 = f1(1, 2);      // 인라인 치환.. 
    int n2 = f2(1, 2);      // 호출은 되지만 인라인 치환 안됨.
    int n3 = f3(1, 2);      // 인라인 치환 안됨
}
*/


// 5장
/*
void foo(int(*f)(int, int))     //ok..
{
    f(1, 2);                    // 인라인 치환이 어렵다.
}


void foo(function<int(int, int)> f)     //ok..
{
    f(1, 2);                    // 인라인 치환이 어렵다.
}

void foo(auto f)     //error, auto는 함수 인자로 쓰일 수 없음
{
    f(1, 2);                    // 인라인 치환이 어렵다.
}


template<typename T> void foo(T f)     //ok
{
    f(1, 2);                            // 인라인 치환 가능.
}

// 1. 함수 포인터로 받기
// 2. function<> 으로 받기
// 3. template으로 받기..

int main()
{
    foo([](int a, int b) {return a + b; });         // foo( xxxx());
    foo([](int a, int b) {return a + b; });         // foo( yyyy());
}
*/


template<typename T> void foo(const T& f)     //ok
{
    f(1, 2);                            // 인라인 치환 가능.
}

int main()
{
    foo([](int a, int b) {return a + b; });         // foo( xxxx());
    foo([](int a, int b) {return a + b; });         // foo( yyyy());
}