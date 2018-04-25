//2_new3 - 103 page. generic container idioms

#include <iostream>
using namespace std;


struct Point
{
	int x, y;
	Point(int a, int b) : x(a), y(b)
	{
		cout << "Point()" << endl;
	}

	//Point(const Point& p) { cout << "���������" << endl; }
};

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
				//new(&buff[i]) T;		//����Ʈ ������
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

	void resize(int newsize, T value)
	{
		if (size < newsize)
		{
			// �޸� ���Ҵ��� �ʿ��ϴ�.
			// �Ϲ����� ���
			// ���� 1 : T�� ����Ʈ �����ڰ� �ʿ��ϴ�.
			// ���� 2 : T�� ��ü�϶� �ű� �����ǰ�ü��
			//			�ڿ��� �Ҵ��� �ʿ� ����.
			//			���� ���ۿ��� ������ ���� �ǹǷ�
			//			�ڿ����� �޸𸮸� �Ҵ��ؾ� �Ѵ�.
			//T *temp = new T[newsize];

			T *temp = static_cast<T*>(
							operator new(sizeof(T) * newsize));


			// ���� ���� ����.
			for (int i = 0; i < size; i++)
			{
				//temp[i] = buff[i];	// ���� ����

				//new(&temp[i]) T;				// ����Ʈ ������
				//new(&temp[i]) T(buff[i]);		// ���� ������.
				new(&temp[i]) T(move(buff[i]));		// move ������.
			}

			// ���Ӱ� �߰��� �޸𸮵鿡 ���ؼ��� ������ ȣ��
			for (int i = size; i < newsize; i++)
			{
				new(&temp[i]) T(value);
			}

			//-----------------------------------------------------
			for(int i = 0; i < size; i++) 
			{
				buff[i].~T();			
			}
			operator delete (buff);
		}
	}
};

int main()
{
	Point p(0, 0);
	Vector<Point> v(10, p);	//�ɱ�?

	v.resize(20, p);
}