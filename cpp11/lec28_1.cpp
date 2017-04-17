#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <cstring>
#include <functional>
#include <algorithm>

using namespace std;

//////////////////////////////////////////////////////////////////////////////
// 28강 람다표현식(Lambda Expression 소개) #1
//////////////////////////////////////////////////////////////////////////////

int main()
{
    int x[10] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 10 };
    //sort(x, x + 10, [](int a, int b){ return a < b; });


    // 람다 표현식을 사용해서 컴파일러가 만드는 함수 객체
    class Closure       // lambda_91e5badsfasdfasdfasf <- 람다 생성시 변경됨
    {
    public:
        inline bool operator()(int a, int b) const  //상수함수, 람다캡쳐에서 다시 등장.
        {
            return a < b;
        }
    };

    // 성능 저하가 없는 sort를 만들 수 있음
    sort(x, x + 10, Closure());
}



/*
bool cmp_less(int a, int b) { return a < b; }

int main()
{
    int x[10] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 10 };

    sort(x, x + 10, cmp_less);      //일반함수

    sort(x, x + 10, less<int>());   // 함수 객체를 사용한 정책의 전달..

    // C++11
    // 람다 표현식(Lambda Expression) : 함수 코드를 인자롤 전달하는 기술..
    sort(x, x + 10, [](int a, int b){ return a < b; });
                // [] Introducer
                // 
}
*/


