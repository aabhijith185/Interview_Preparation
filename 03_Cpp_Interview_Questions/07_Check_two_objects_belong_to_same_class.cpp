#include<iostream>
#include<typeinfo>

class A{};
class B{};


int main(void)
{
	A a1,a2;
	B b1,b2;

	if(typeid(a1) == typeid(a2))
		std::cout<<"A1 and A2 belongs to same class. Typeid : "<<typeid(a1).name()<<std::endl;
	else
		std::cout<<"A1 and A2 belongs to different class"<<std::endl;

	if(typeid(a1) == typeid(b1))
		std::cout<<"A1 and A2 belongs to same class. Typeid : "<<typeid(a1).name()<<std::endl;
	else
		std::cout<<"A1 and b1 belongs to different class"<<std::endl;

	return 0;
}
