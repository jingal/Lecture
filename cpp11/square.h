// square.h
// extern "C"	: C++컴파일러에게 C함수라고 알려주는 것

//extern "C" int square(int a);


#ifdef __cplusplus
extern "C" {
#endif
	int square(int a);
#ifdef __cplusplus
}
#endif


