//2_������2

#include <iostream>
using namespace std;

// protected ������ - 
// �ڽ��� ��ü�� ����� ������, 
// �Ļ�Ŭ������ ��ü�� ���� �� �ְ��Ѵ�.
class Animal
{
protected:
	Animal() {}
};

class Dog : public Animal
{

};

int main()
{
	// ������ ������?
	Animal a;	// error
	Dog d;		// ok
}