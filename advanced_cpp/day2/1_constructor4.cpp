//1_������4, 25 page

#include <iostream>
using namespace std;

struct xstreambuf
{
	xstreambuf() { cout << "�����ʱ�ȭ" << endl; }
};

struct xostream
{
	xostream(xstreambuf& buf)
	{
		cout << "buf ���" << endl;
	}
};

/*
// ���۸� ������ �ִ� ��Ʈ���� ����� ���
struct xfdostream : public xostream
{
	// �Ʒ� �ڵ忡�� buf�� �ʱ�ȭ ���� xostream �����ڰ�
	// ���� ȣ��ȴ�. ��, osteam�� �ʱ�ȭ ���� ����
	// buf�� ����ϰ� �ȴ�.
	// ��� : ��� ����Ÿ�� ��� Ŭ������ �����ڸ� ������ �ȵȴ�.

	xstreambuf buf;
	xfdostream() : xostream(buf) {}
};
*/

// �ذ�ý : buf�� ���� Ŭ������ �����, ���� ����� ���
struct fdostream_base
{��
protected:
	xstreambuf buf;
};

// ���߻�ӽ� ��� ������ �����ϸ� �ȵ�
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