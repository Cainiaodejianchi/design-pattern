#include<string>
#include<vector>
#include<memory>
#include<iostream>

//******************************************************************** 
class User
{
friend class SqlserverUser;
friend class AssessUser;
public:
	User()=default;
	User(const std::string s,const unsigned i):name(s),id(i){}
	unsigned getid()const
	{
		return id;
	}
	std::string getname()const
	{
		return name;
	}
private:
	std::string name;
	unsigned id;
};

class IUser
{
protected:
	IUser():p(std::make_shared<std::vector<User>>()){}
public:
	virtual void insert(const User&)=0;
	virtual void getuser(const unsigned)const=0;
protected:
	std::shared_ptr<std::vector<User>> p;
};

class SqlserverUser:public IUser
{
public:
    SqlserverUser():IUser(){}
    void insert(const User& u)override
    {
    	p->push_back(u);
	}
	void getuser(const unsigned i)const override
	{
		for(auto use:*p){
			if(use.getid()==i)
			std::cout<<use.getname()<<" : "<<use.getid()<<std::endl;
		}
	}
};

class AssessUser:public IUser
{
public:
    AssessUser():IUser(){}
    void insert(const User& u)override
    {
    	p->push_back(u);
	}
	void getuser(const unsigned i)const override
	{
		for(auto use:*p){
			if(use.getid()==i)
			std::cout<<use.getname()<<" : "<<use.getid()<<std::endl;
		}
	}
};

//******************************************************************** 
class Depatrment
{
	
};

class SqlserverDepatrment:public Depatrment
{
	
};

class AssessDepatrment:public Depatrment
{
	
};

//******************************************************************** 
using System.Reflection;

class IFactory
{
public:
	IFactory()=default;
public:
	static IUser* createIuser()
	{
		std::string calssname=Assemblyname+"."+db+"User";  //目前反射机制缺失； 
		return Assembly.Load(Assemblyname).CreateInstance(calssname);
	}
	//***************************************
	/*
	static IUser* createIuser()
	{
		switch(data){
			case SQLserver:
				return new SqlserverUser();
				break;
			case Assess:
				return new AssessUser();
				break;
		}
	}
	static Depatrment* createDepatr()
	{
		switch(data){
			case SQLserver:
				return new SqlserverDepatrment();
				break;
			case Assess:
				return new AssessDepatrment();
				break;
		}		
	}
	*/
private:
	const static std::string Assemblyname="抽象工厂模式";
	const static std::string db="Sqlserver";
};

int main()
{
	User a("xiaoming",1);
	User b("xiaowang",2);
	User c("zhangshang",3);
	
	IUser* database=IFactory::createIuser();
	IUser* data=database;
	database->insert(a);
	data->insert(b);
	database->insert(c);
	
	database->getuser(3);
	
	delete(database);
	database=nullptr;
	data=nullptr;
	
	return 0;
}

