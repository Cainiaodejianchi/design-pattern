#include<string>
#include<iostream>
#include<vector>
#include<memory>

class CreateCompany
{
public:
	CreateCompany(const std::string s):name(s){}
	virtual void addpart(CreateCompany*)=0;
	virtual void removepart(CreateCompany*)=0;
	virtual void show(const unsigned)const=0;
protected:
    std::string name;	
};

//************************************************
class Department:public CreateCompany
{
public:
	Department(const std::string s):CreateCompany(s){}
private:
	void addpart(CreateCompany* p) override
	{
		return;
	}
	void removepart(CreateCompany* p) override
	{
		return;
	}
public:
	void show(const unsigned depth)const
	{
		std::string s(depth,'-');
		std::cout<<s+name<<std::endl;
	}
};

class Company:public CreateCompany
{
public:
	Company(const std::string s):CreateCompany(s),part(std::make_shared<std::vector<CreateCompany*>>()){}
	void addpart(CreateCompany* p) override
	{
		part->push_back(p);
	}
	void removepart(CreateCompany* p) override
	{
		for(auto it=part->begin();it!=part->begin();++it){
		    if(*it==p)
		    part->erase(it);			
		}
	}
	void show(const unsigned depth)const
	{
		std::string s(depth,'-');
		std::cout<<s+name<<std::endl;
		for(auto p:*part){
			p->show(depth+2);
		}
	}
	~Company(){}
private:
    std::shared_ptr<std::vector<CreateCompany*>> part;	
};


/*******************************************************
class CompanyPartA:public Company
{
public:
	CompanyPartA():Company()
	{
		conpanypart=="上海分公司";
	}
    void show()const override
	{
		std::cout<<"上海分公司架构："<<std::endl;
		std::cout<<"    "<<humanresourcesdepartment<<"+"<<financedepartment<<"+"<<operationdepartment
	             <<"+"<<office<<std::endl;
	}
protected:
    std::string office="设有多个办事处"	;
};

class NanjingOffice:public CompanyPartA
{
public:
    NanjingOffice():CompanyPartA()
	{
		office="南京办事处";
	}	
	void show()const override
	{
		std::cout<<"南京办事处架构："<<std::endl;
		std::cout<<"    "<<humanresourcesdepartment<<"+"<<financedepartment<<"+"<<operationdepartment<<std::endl;
	}
};

class HangzhouOffice:public CompanyPartA
{
public:
    HangzhouOffice():CompanyPartA()
	{
		office="杭州办事处";
	}
	void show()const override
	{
		std::cout<<"杭州办事处架构："<<std::endl;
		std::cout<<"    "<<humanresourcesdepartment<<"+"<<financedepartment<<"+"<<operationdepartment<<std::endl;
	}	
};
*****************************************************************/
int main()
{
	//Company* a= new NanjingOffice();
	//a->show();
	//delete(a);
	//a=nullptr;
	CreateCompany* root=new Company("Sunny");
	root->addpart(new Department("R & D"));
	Company *branches=new Company("Sunny Car");
	branches->addpart(new Department("R & D"));
	branches->addpart(new Department("H & M"));
	root->addpart(branches);
	root->show(1);
	return 0;
} 
