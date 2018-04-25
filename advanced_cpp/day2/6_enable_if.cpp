// 6_enable_if - 77 page

template<bool, typename T = void> struct enable_if
{
	typedef T type;
};


// ����ڰ� enable_if<false, ����Ÿ��>�� ���� �Ʒ�
// ���ø� ���
// partial specialization �κ� Ư��ȭ ����
template<typename T> struct enable_if<false, T>
{	
};

// T�� ���� ���� typename �ʿ�
// n1 ~ n4 ���� Ÿ������ ������ ������.
enable_if<true, int>::type n1;
enable_if<true, double>::type n2;
enable_if<true>::type n3;

enable_if<false, int>::type n4;	// error, type�� ����.

// ��� 
// enable_if<true, Ÿ��>::type => Ÿ��
// enable_if<false, Ÿ��>::type => error, type�� ����.



