// 6_callableobject2


#include <iostream>

using namespace std;


// callable object : ()�� ȣ�� ������ ��ü
// �Ϲ� �Լ� 
// �Լ� ��ü(Function Object, Functor)


struct Plus
{
	//����ü �ȿ� �����θ� ������ �ڵ������� inline���� ����
	inline int operator()(int a, int b) const { return a + b; }
};


inline int plus(int a, int b) { return a + b; }

// �Ʒ� ���ø��� �Ϲ��Լ��� ������ ��
// �Ϲ��Լ��� �ڽŸ��� Ÿ���� ����.
// int(*f)(int, int)�� ����� �Լ��� ��� ���� Ÿ���̴�.
// inline�� �ϴ��� � �Լ��� ���� �𸣱� ������ inlineġȯ�� �ȵ�
void foo(int(*f)(int, int))
{
	int n = f(1, 2); 
}

// Plus ��ü�� ���ø� foo�� ������ �����Ϸ��� �Ʒ��ڵ� ����
//
void foo(Plus f)
{
	int n = f(1, 2);
}


template<typename F> void foo(F f)
{
	int n = f(1, 2); //�� ������ ������ ���ô�.
}

int main()
{
	foo(&plus);		// F : int(*)(int, int)
	foo(&minus);	// F : int(*)(int, int)

	Plus p;
	p(1, 2);		//

	Plus()(1, 2);

	Plus p;
	foo(p);		// F : Plus

	Minus m;
	foo(m);		// F : Minus
}
