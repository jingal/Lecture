//1_생성자4, 25 page

#include <iostream>
using namespace std;

struct xstreambuf
{
	xstreambuf() { cout << "버퍼초기화" << endl; }
};

struct xostream
{
	xostream(xstreambuf& buf)
	{
		cout << "buf 사용" << endl;
	}
};

/*
// 버퍼를 가지고 있는 스트림을 만들면 어떨까
struct xfdostream : public xostream
{
	// 아래 코드에서 buf의 초기화 보다 xostream 생성자가
	// 먼저 호출된다. 즉, osteam은 초기화 되지 않은
	// buf를 사용하게 된다.
	// 결론 : 멤버 데이타를 기반 클래스에 생성자를 보내면 안된다.

	xstreambuf buf;
	xfdostream() : xostream(buf) {}
};
*/

// 해결첵 : buf를 가진 클래스를 만들고, 다중 상속을 사용
struct fdostream_base
{ㄴ
protected:
	xstreambuf buf;
};

// 다중상속시 상속 순서를 변경하면 안됨
struct xfdostream : public fdostream_base,
					public xostream
{
	xfdostream() : xostream(buf) {}
};

int main()
{
	xfdostream os;

	//xstreambuf buf;
	//xostream os(buf);
}