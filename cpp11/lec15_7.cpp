#include <iostream>
#include <type_traits>
#include <typeinfo>
//#include <vector>
//#include <boost\\type_index.hpp>

using namespace std;

///////////////////////////////////////////////////////////////////////////
//	scoped enum
///////////////////////////////////////////////////////////////////////////

// C++98/03
//enum Color { red = 1, green = 2 };

// C++11/14 scoped enum
//enum class Color { red = 1, green = 2 };

enum Color {red = 1, blue};
enum class Shape { rect = 1, circle };

int main()
{
//	cout << typeid(underlying_type<Color>::type).name() << endl;

	int n1 = red;
	int n2 = Color::red;

	Color c1 = red;
	Color c2 = Color::red;

	//int n3 = rect;
	//int n4 = Shape::rect;

	Shape s1 = rect;
	Shape s2 = Shape::rect;

}

/*
// C++98/03
//enum Color { red = 1, green = 2 };

// C++11/14 scoped enum
enum class Color { red = 1, green = 2 };

int main()
{
	//int n1 = red;		//error;
	//int n2 = Color::red;		//error

	Color c1 = Color::red;	//ok;

	int n3 = static_cast<int>(Color::red);
}
*/



/*
enum Color { red = 1, green = 2};

int main()
{
	int n1 = Color::red;

	int n2 = red;					//unscoped enum

	int red = 10;

	cout << red << endl;			//10
}
*/
