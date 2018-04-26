// 4_move2 - 133 page

#include <iostream>
using namespace std;

struct Test
{
	int* p = 0;

	Test() {
		p = new int[100];
	}

	Test(const Test& t)
	{		
		cout << "복사 생성자" << endl;
		p = new int[100];
		memcpy(p, t.p, sizeof(int) * 100);
	}

	Test(Test&& t) noexcept
	{		
		cout << "move 생성자" << endl;
		p = t.p;
		t.p = 0;
	}	

	~Test() { delete[] p; }
};

int main()
{
	Test* p1 = new Test[2];

	//버퍼를 4개로 키우려고 합니다.
	// 1. new가 아닌 operator new로 메모리만 할당
	// 
	Test* p2 = static_cast<Test*>(
				operator new(sizeof(Test) * 4));

	//2. 2개는 기존 버퍼내용 복사
	for (int i = 0; i < 2; i++)
	{
		//new(&p2[i]) Test(p1[i]);		//복사 생성자.
		//new(&p2[i]) Test(move(p1[i]));		//Move 생성자.

		// move_if_noexcept : 예외가 없을 때만 move
		//						예외가 있을 수 있다면 copy
		new(&p2[i]) Test(move_if_noexcept(p1[i]));
	}
}