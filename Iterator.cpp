#include<string>
#include<vector>
#include<iostream>


class Iterator
{
public:
	Iterator()=default;
public:
	virtual void* begin()=0;
	virtual void* end()const=0;
	virtual void* next()=0;
	virtual void* current()=0;
};

class Aggregate
{
protected:
	Aggregate()=default;
	virtual Iterator* createiterator()=0;
};

class CreateAggregate:public Aggregate
{
public:
	CreateAggregate():vec(std::vector<std::string>()){}
	std::string &operator[](unsigned i)
	{
		if(i<vec.size())
		return vec[i];
	}
	unsigned size()const
	{
		return vec.size();
	}
	Iterator* createiterator() override;
	void push_back(std::string s)
	{
		vec.push_back(s);
	}
private:
	std::vector<std::string> vec;
};

class RealIterator:public Iterator
{
public:
	RealIterator():Iterator(){}
	RealIterator(CreateAggregate &p):Iterator(),aggret(p){}
public:
	void* begin() override
	{
		return &aggret[0];
	}
	void* end()const override
	{
		return nullptr;
	}
	void* next() override
	{
		if(curr==aggret.size())
		return nullptr;
		return &aggret[++curr];
	}
	void* current() override
	{
		return &aggret[curr];
	}
private:
	CreateAggregate aggret;
	unsigned curr=0;
};

Iterator* CreateAggregate::createiterator() 
{
	return new RealIterator(*this);
}



int main()
{
	CreateAggregate a;
	a.push_back("xiaoming");
	a.push_back("zhangsan");
	a.push_back("xiaowang");
	Iterator* i=new RealIterator(a);
	//************迭代器返回类型如何确认，C#中使用object;C++??? 
	std::cout<<*(std::string*)(i->begin())<<std::endl;
	std::cout<<*(std::string*)(i->next());
	delete(i);
	return 0;
}



