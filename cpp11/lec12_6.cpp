#include <iostream>
#include <type_traits>
#include <vector>

using namespace std;

///////////////////////////////////////////////////////////////////////////
//	direct vs copy initialization
///////////////////////////////////////////////////////////////////////////

class Matrix
{
	int buff[5][5];
public:
	int& operator[](pair<int, int> idx)
	{
		return buff[idx.first][idx.second];
	}
};



int main()
{
	// pair<int, int> p = {1,1};

	Matrix m;
	m[pair<int, int>(1, 1)] = 0;
	m[{1, 1}] = 0;
}
