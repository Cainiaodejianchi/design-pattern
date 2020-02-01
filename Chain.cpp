#include<iostream>

//需要将管理者进行抽象，并派生出三个实体类；上级（后继对象）应该设置成员函数来动态确定；
//未修改，修改更改 
class GeneralManager
{
public:
	GeneralManager()=default;
	void raisemoney(){
		std::cout<<"He is a student, I disagree"<<std::endl;
	}	
};

class Director
{
public:
	Director()=default;
	void raisemoney(){
		std::cout<<"Beyond my duty, request to general manager"<<std::endl;
		g.raisemoney();
	}
private:
	GeneralManager g;	
};

class Manager
{
public:
	Manager()=default;
	void raisemoney(){
		std::cout<<"Beyond my duty, request to director"<<std::endl;
		d.raisemoney();
	}
private:
	Director d;	
};

class Request
{
public:
	Request()=default;
	void raisemoney(){
		std::cout<<"Beyond my duty, request to manager"<<std::endl;
		m.raisemoney();
	}
private:
	Manager m;
};

int main()
{
	Request xiaocai;
	xiaocai.raisemoney();
	return 0;
}
