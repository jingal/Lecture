//5_SFINAE5
// SFINAE - Substitution Failure Is Not An Error

#include <iostream>
#include <type_traits>
using namespace std;

struct Shape
{
	virtual void Draw() = 0;
};

//�ٽ�. 1. ������ ���ǿ� ���� ġȯ ���а� �Ǵ� �Լ��� �����.
//		2. ���� ���� ������ ����� ��ȯŸ���� �ٸ��� �Ѵ�.

// Step 1. ������ : main���� Shape�� ���� �� ����.
/*
//���ø� ���� : �߻��� �ƴҶ� ���
template<typename T> char check(T t);

//... : �߻��� ��� ���
short check(...);

int main()
{
	Shape s;
	check(s);
}
*/

/*
// Step 2. ������ : main���� Shape�� ���� �� ����.
//���ø� ���� : T�� �߻��� �ƴҶ� ���
// ���� : �߻��϶� �����ؾ� �Ѵ�. main���� ���ڸ� ���� �� �־�� �Ѵ�.
// Shape : �߻��� �� ����, main���� ���� ������ ����.
// Shape* : �߻��� �� ����...
// Shape(*)[1] : �߻��϶� ����. ������ �̹Ƿ� 0���� ����

// ���ڷ� 0�� ���� �� ������, 0���� T�� �߷� �ȵǹǷ�
// ��������� Ÿ���� �����ؾ� �Ѵ�.
template<typename T> char check(T (*p)[1]);

//... : �߻��� ��� ���
short check(...);

int main()
{
	//Shape s;	//error
	//Shape* p;	// ok
	//Shape(*p)[1]; //�迭�� ����Ű�� ������, �߻��϶� error

	// �Ʒ� �ڵ�� ������ check�� ���ø� �����̾�� �Ѵ�.
	cout << sizeof(check<Shape>(0)) << endl;
}
*/


// Step 3. 

template<typename T> char check(T (*p)[1]);
template<typename T> short check(...);

int main()
{
// �Ʒ� �ڵ�� ������ check�� ���ø� �����̾�� �Ѵ�.
// ���� ���� ������ template���� 
cout << sizeof(check<Shape>(0)) << endl;
}
