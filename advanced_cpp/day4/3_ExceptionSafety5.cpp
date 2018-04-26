// 3_ExceptionSafety5 - 197 page

#include <iostream>
#include <mutex> 
using namespace std;

mutex m;

// ����ȭ ��ü ���� ���ܰ� �߻��ϸ� dead lock �߻��� �� ����
// ������, �Ҹ��ڸ� ���ؼ� �ڿ��� �������.

// 1. ���������� mutex�� ���������� lg ������ ����
// 2. ���� �߻��� ���������� �����ϰ� �ı��ȴ�.

// RAII : Resource Acquision Is Initialize
// "�ڿ��� ȹ���ϴ� ���� �ڿ�������ü�� �ʱ�ȭ �ɶ��̴�."
// �ȵ���̵�/libutils/include/utils/Singleton.h

/*
template<typename T> struct lock_guard
{
	T& sync;
	lock_guard(T& s) : sync(s) {
		sync.lock();
	}

	~lock_guard(){
		sync.unlock();
	}
};
*/

void foo()
{
	lock_guard<mutex> lg(m);	// lg�� �����ڿ��� m.lock
	//m.lock();
	// ---
	// ���ܹ߻�				--> stack Ǯ��� ���ؼ� �Ҹ��ڰ� ȣ���
	//m.unlock();
								// �ı��ɶ� �Ҹ��ڿ��� m.unlock
}

int main()
{

}