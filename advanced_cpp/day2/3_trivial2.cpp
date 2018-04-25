//3_trivial2

#include <iostream>
#include <type_traits>		// Ÿ���� Ư���� �����ϴ�
							// ��Ÿ �Լ���..
using namespace std;

struct Test
{
	Test() {}
	Test(const Test&) {}
};

template<typename T> 
void copy_type(T* dst, T* src, int sz)
{
	if (is_trivially_copyable<T>::value)
	{
		cout << "memcpy ���" << endl;
		memcpy(dst, src, sizeof(T)*sz);
	}
	else
	{
		cout << "trival ���� ����. ��������� ���" << endl;
		while (sz--)
		{
			new(dst) T(*src);		//���� ������ ȣ��
			++dst, ++src;
		}
	}
}

int main()
{
	char s1[10] = "hello";
	char s2[10];

	//strcpy(s2, s1);
	copy_type(s2, s1, 10);

	Test t1[10];
	Test t2[10];

	copy_type(t2, t1, 10);
}

// �ȵ���̵� �ҽ��ڵ� 
// platform / libutils/include/utils/typehelpers.h
// �ȿ���.. copy_type�� ã�ƺ�����.