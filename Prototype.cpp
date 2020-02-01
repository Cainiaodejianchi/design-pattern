#include<string>
#include<memory>
#include<iostream>

class Prototype
{
protected:
	Prototype()=default;
	//virtual Prototype* clone()const=0;
	virtual std::shared_ptr<Prototype> clone()const=0;
};

class WorkExperience:public Prototype
{
friend class Resume;
public:
	WorkExperience()=default;
public:
	WorkExperience(const std::string wt,const std::string cp):worktime(wt),company(cp){}
private:
	//Prototype* clone()const override
	std::shared_ptr<Prototype> clone()const override
	{
		//WorkExperience *copy=new WorkExperience(worktime,company);
		std::shared_ptr<WorkExperience> copy=std::make_shared<WorkExperience> (worktime,company);
		return copy;
	}
private:
	std::string worktime;
	std::string company;
};

class Resume:public Prototype
{
public:
	Resume()=default;
	Resume(const std::string s,const std::string str):name(s),sex(str){}
	Resume(const std::string s,const std::string str,unsigned i):name(s),sex(str),age(i){}
	void setage(const unsigned val)
	{
		age=val;
	}
	void setWorkExperience(const std::string s,const std::string str)
	{
		//workexperience=std::make_shared<WorkExperience>(s,str);
		workexperience->worktime=s;
		workexperience->company=str; 
	}
private:
	//Resume* Membercopy()const
	std::shared_ptr<Resume> Membercopy()const
	{
		//Resume* copy=new Resume(name,sex);
		std::shared_ptr<Resume> copy=std::make_shared<Resume>(name,sex); 
		copy->age=age;
		copy->workexperience=workexperience;
		return copy;
	}
public:
	//Prototype* clone()const override
	std::shared_ptr<Prototype> clone()const override
	{
		return this->Membercopy();
	}
	void display()
	{
		std::cout<<name<<" "<<sex<<"  "<<age<<std::endl;
		std::cout<<workexperience->worktime<<"  "<<workexperience->company<<std::endl;
	}
private:
	const std::string name;
	const std::string sex;
	unsigned age;
	std::shared_ptr<WorkExperience> workexperience=std::make_shared<WorkExperience>();
};

int main()
{
	std::shared_ptr<Resume> a=std::make_shared<Resume>("zhangsan","boy",18);
	a->setWorkExperience("2008-2010","Sunny");
	//***********基类强制类型转换派生类ok,智能指针NG； 
	std::shared_ptr<Resume> b=(std::shared_ptr<Resume>)a->clone(); //强制类型转换Very good 
	/*std::shared_ptr<Resume> c=(std::shared_ptr<Resume>)b->clone();
	b->setWorkExperience("2010-2017","Sunnyxx");
	c->setWorkExperience("2017-2020","Sunnyyy");
	a->display();
	b->display();
	c->display();*/
	return 0;
}

