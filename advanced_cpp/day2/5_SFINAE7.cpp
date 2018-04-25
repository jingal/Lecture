//5_SFINAE7
// SFINAE - Substitution Failure Is Not An Error

#include <iostream>
#include <type_traits>
using namespace std;



//Point p(1, 1);
//Point(1, 1);		//�ӽð�ü ����

struct Test { 
	//void foo() {} 
};


template<typename U> struct has_foo_function
{
	// �ٽ� : ��� �Լ� foo�� ������ ����
	//			������ ġȯ ���а� �Ǿ�� �Ѵ�.

	// �Ʒ� ǥ���� check(��)�� �ȴ�. check(Ÿ��)�� �ʿ��ϴ�.
	// �Լ� �����̹Ƿ�
	//template<typename T> static char check( sizeof( T().foo()) );
	
	template<typename T> 
	static char check( decltype(T().foo()) *);

	template<typename T> static short check(...);

	enum { value = (sizeof(check<U>(0)) == sizeof(char)) };
};

int main()
{
	cout << has_foo_function<Test>::value << endl;
}
