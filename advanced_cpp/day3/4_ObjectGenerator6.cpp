// 4_ObejctGennerator5 - 177 page

#include <iostream>
#include <functional>
using namespace std;

void log() { cout << "log" << endl; }
int goo() { cout << "goo" << endl; return 0; }

template<typename T>
class ScopedExit
{
	T handler;

public:
	ScopedExit(T f) : handler(f) {}
	~ScopedExit() { handler(); }
};


// 웹킷 소스 : wtf/Scoped.h
template<typename T>
ScopedExit<T> makeScopedExit(const T& a)
{
	return ScopedExit<T>(a);
}

int main()
{
	auto e1 = makeScopedExit(&log);
	auto e2 = makeScopedExit([]() {cout << "bye" << endl; });
}