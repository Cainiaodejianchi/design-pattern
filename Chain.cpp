#include<iostream>

//��Ҫ�������߽��г��󣬲�����������ʵ���ࣻ�ϼ�����̶���Ӧ�����ó�Ա��������̬ȷ����
//δ�޸ģ��޸ĸ��� 
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
