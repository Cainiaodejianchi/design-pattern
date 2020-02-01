#include<string>
#include<vector>
#include<iostream>
class Product
{
friend class FatBuilder;
public:
	Product():ret(std::vector<std::string>()){}
	void show()
	{
		if(!ret.empty()){
			for(auto s:ret)
			std::cout<<s<<std::endl;
		}
		else 
		    std::cout<<"creation fail"<<std::endl;
	}
private:
	void add(const std::string s)
	{
		std::string str=s;
		ret.push_back(str);
	}
private:
	std::vector<std::string> ret;
};

class PeopleBuilder
{
friend class Director;
protected:
	PeopleBuilder()=default;
protected:
	virtual void headbuilt()=0;
	virtual void bodybulit()=0;
	virtual void lefthandbulit()=0;
	virtual void righthandbuilt()=0;
	virtual void leftfootbulit()=0;
	virtual void rightfootbuilt()=0;
	virtual Product getresult()const=0;
protected:
	Product people;
};

class FatBuilder:public PeopleBuilder
{
public:
	FatBuilder():PeopleBuilder(){}
private:
	void headbuilt() override
	{
		people.add("fat head");
	}
	void bodybulit() override
	{
		people.add("fat body");
	}
	void lefthandbulit() override
	{
		people.add("fat lefthand");
	}
	void righthandbuilt() override 
	{
		people.add("fat righthand");
	}
	void leftfootbulit() override
	{
		people.add("fat leftfoot");
	}
	void rightfootbuilt() override
	{
		people.add("fat rightfoot");
	}	
public:
	Product getresult()const override
	{
		return people;
	}
};

class Director
{
public:
	Director()=default;
	void construct(PeopleBuilder* pb)
	{
		pb->headbuilt();
		pb->bodybulit();
		pb->lefthandbulit();
		pb->lefthandbulit();
		pb->leftfootbulit();
		pb->leftfootbulit();
	}
};

int main()
{
	Director director;
	FatBuilder fatpeople;
	director.construct(&fatpeople);
	Product product=fatpeople.getresult();
	product.show();
	return 0;
}
