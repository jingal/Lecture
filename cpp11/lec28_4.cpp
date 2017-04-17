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
// 28강 6. 람다 표현식과 리턴 타입
//////////////////////////////////////////////////////////////////////////////

int main()
{
    auto f1 = [](int a, int b) {return a + b; };        // 람다표현식이 리턴타입이 생략된 형태..

    auto f2 = [](int a, int b) -> int {return a + b; }; //람다 표현식에서 명시적으로 리턴 타입 지정
                                                        // trailing return


    auto f3 = [](int a, int b) { if (a == 0) return a;
                                else return b;};       //여러 개의 리턴문이 있어도 같은 타입이면 생략 가능
    

    auto f4 = [](int a, int b) -> double { if (a == 0) return a;        //여러개의 리턴문이 타입이 다르면, 명시적으로 리턴 타입지정
                               else return 3.1; };

}