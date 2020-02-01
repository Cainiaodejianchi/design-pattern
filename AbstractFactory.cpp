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

class IFactory
{
protected:
	IFactory()=default;
public:
	virtual IUser* createIuser()const=0;
	virtual Depatrment* createDepatr()const=0;
};

class SqlserverFactory:public IFactory
{
public:
	SqlserverFactory():IFactory(){}
	IUser* createIuser()const override
	{
		return new SqlserverUser();
	}
	Depatrment* createDepatr()const override
	{
		return new SqlserverDepatrment();
	}
};

class AssessFactory:public IFactory
{
public:
	AssessFactory():IFactory(){}
	IUser* createIuser()const override
	{
		return new AssessUser();
	}
	Depatrment* createDepatr()const override
	{
		return new AssessDepatrment();
	}
};

int main()
{
	IFactory* factory=new SqlserverFactory(); //如果要更换数据库，只需要更换此处； 
	User a("xiaoming",1);
	User b("xiaowang",2);
	User c("zhangshang",3);
	
	IUser* database=factory->createIuser();
	IUser* data=database;
	database->insert(a);
	data->insert(b);
	database->insert(c);
	
	database->getuser(2);
	
	delete(database);
	database=nullptr;
	data=nullptr;
	delete(factory);
	
	return 0;
}

