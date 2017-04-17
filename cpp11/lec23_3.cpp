#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <cstring>

using namespace std;

//////////////////////////////////////////////////////////////////////////////
// 23강 STL과 move생성자
//////////////////////////////////////////////////////////////////////////////


int main()
{
    string s1 = "hello";
    string s2 = s1;

    string s3 = move(s1);

    cout << s1 << endl;

    vector<int> v1 = { 1, 2, 3 };

    vector<int> v2 = v1;            //복사

    vector<int> v3 = move(v1);      //이동

    cout << v1.size() << endl;  
}


