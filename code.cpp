#include <vector>
#include <iostream>

class Widget
{

public:
	
	Widget(int i, bool b)
	{
		std::cout << "ctor 1" << std::endl;
	}

	Widget(int i, double d)
	{
		std::cout << "ctor 2" << std::endl;
	}

	// 문제의 생성자 - 중괄호 초기화 사용에 주의
	// 이 함수가 나중에 추가할 때는 {}로 초기화한 코드는 이쪽으로 호출되거나 에러 발생 주의가 필요.
	Widget(std::initializer_list<long double> il)
	{
		std::cout << "ctor 3(initlist)" << std::endl;
	}

	Widget(const Widget& w)
	{
		x = w.x;
		std::cout << "copy ctor" << std::endl;
	}

	operator float() const
	{
		return static_cast<float>(x);
	}

	int x{};
};

void main()
{
    std::cout << "check!" << std::endl;

	Widget w1(10, true);
	Widget w2{ 10, true }; // 초기화 리스트 버전으로 호출    

	Widget w3(10, 5.0);
	Widget w4{ 10, 5.0 }; // 초기화 리스트 버전으로 호출

	Widget w5(w4);
	Widget w6{ w4 }; // 이것은 책(14버전)과는 달리 복사 생성자가 호출됨. (gcc는 ctor 3 호출)	
}