// 1_PolicyClone - 183 page
// wtf/������ nolock.h


#include <iostream>
using namespace std;

// PolicyBase Design(���� ���� ������) - ����� ���ÿ� ���ؼ� ��å ����, �������� ����
// ��� ��å Ŭ�������� ���Ѿ� �ϴ� ������ �ִ�.
// �Լ� �̸��� ������ �ִٴ� �ǹ�.

template<typename T, typename ThreadModel = NoLock> class List
{
	ThreadModel tm;

public:
	void push_front(const T& a)
	{
		tm.lock();
		//....
		tm.unlock();
	}
};

// ����ȭ ��å�� ���� ��å Ŭ����
class MuteLock
{
public:
	inline void lock() { cout << "mutex lock" << endl; }
	inline void unlock() { cout << "mutex unlock" << endl; }

};

class NoLock
{
public:
	inline void lock() { }
	inline void unlock() { }
};


List<int, NoLock> s;				//��������, ��Ƽ�����忡 �������� �ʴ�.


int main()
{
	s.push_front(10);
}