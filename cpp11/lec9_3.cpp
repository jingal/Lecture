#include <iostream>
#include <type_traits>
#include <vector>

using namespace std;

///////////////////////////////////////////////////////////////////////////
//	final
///////////////////////////////////////////////////////////////////////////

class Window
{
public:
	virtual void init() {}
};

class Dialog : public Window
{
public :
	virtual void init() override final {}
};

class LogInDialog : public Dialog
{
public:
	virtual void init() override {}	//error
};

int main()
{
	LogInDialog dial;
}