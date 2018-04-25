//2_new2 - 103 page. generic container idioms

#include <iostream>
using namespace std;


struct Point
{
	int x, y;
	Point(int a, int b) : x(a), y(b) 
	{
		cout << "Point()" << endl;
	}
};

// T�� ���� : ���� �����ڸ� ������ Vector ��� ����
template<typename T> class Vector
{
	T*  buff;
	int size;

public:
	Vector(int sz, T value = T())
	{
		size = sz;
		buff = static_cast<T*>(
					operator new(sizeof(T) * sz));

		int i = 0;
		try {		
			for (; i < sz; i++)
			{
				//new(&buff[i]) T;		//����Ʈ ������, ����
				new(&buff[i]) T(value);		//����Ʈ ������
			}
		}
		catch (...) {
			//���ܰ� �߻��� ��� ������ ȣ�⿡ ������
			// ��ü���� �Ҹ��ڸ� ȣ���ϰ� �޸� ����
			for (int j = i - 1; j <= 0; j--)
			{
				buff[j].~T();
			}

			operator delete(buff);
		}
	}
};

int main()
{
	Point p(0, 0);
	Vector<Point> v(10, p);	//�ɱ�?
}