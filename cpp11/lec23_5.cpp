#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <cstring>

using namespace std;

//////////////////////////////////////////////////////////////////////////////
// 23강 move 생성자와 noexcept
//////////////////////////////////////////////////////////////////////////////


class Data
{
    void* resource;

public:
    Data() {}
    Data(const Data* d)         { cout << "copy ctor" << endl; }
    Data(Data&& d)              { cout << "move ctor" << endl; }
    //Data(Data&& d) noexcept       { cout << "move ctor" << endl; }
};


int main()
{
    vector<Data> v(4);
    v.resize(6);        //버퍼의 재할당.. 기존 버퍼에서 새로운 버퍼로 옮길 때.. move 생성자 이용
                        // move 생성자의 경우에는 이동중 예외가 발생할 경우 보장이 안됨

    Data d1;
    Data d2 = move(d1);
    Data d3 = move_if_noexcept(d1);
}


