// 6_enable_if - 77 page

template<bool, typename T = void> struct enable_if
{
	typedef T type;
};


// 사용자가 enable_if<false, 임의타입>의 경우는 아래
// 템플릿 사용
// partial specialization 부분 특수화 문법
template<typename T> struct enable_if<false, T>
{	
};

// T가 있을 때만 typename 필요
// n1 ~ n4 무슨 타입인지 생각해 보세요.
enable_if<true, int>::type n1;
enable_if<true, double>::type n2;
enable_if<true>::type n3;

enable_if<false, int>::type n4;	// error, type이 없다.

// 결론 
// enable_if<true, 타입>::type => 타입
// enable_if<false, 타입>::type => error, type이 없다.



