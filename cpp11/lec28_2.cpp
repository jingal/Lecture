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
// 28강 3. 람다표현식과 타입
//////////////////////////////////////////////////////////////////////////////



// 모든 람다 표현식은 다른 타입이다.
// auto 변수에 담은 람다 표현식은 다른 람다를 대입할 수 없다.
int main()
{
    // 같은 람다함수를 만들어도 각기 다른 타입의 람다 closure 생성
    auto f1 = [](int a, int b){ return a + b; };            // class xxx{}, xxx();
    auto f2 = [](int a, int b){ return a + b; };            // class yyy{}, yyy();

    cout << typeid(f1).name() << endl;
    cout << typeid(f2).name() << endl;

    //f1 = f2;                                      //error
    //f1 = [](int a, int b) { return a + b; };      //error
}


/*
int main()
{
    // 메인함수 구문에 작성해도 됨
    auto f = [](int a, int b){ return a + b; };      // class Closure{}; Closure();

    //RTTI를 사용한 클래스 이름 조사
    cout << typeid(f).name() << endl;

    int n = f(1, 2);
    cout << n << endl;
}
*/