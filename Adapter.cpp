#include<iostream>

class BacketballPlayer
{
public:
	BacketballPlayer()=default;
	virtual void attach()const=0;
	virtual void defense()const=0;
};

class Madi:public BacketballPlayer
{
public:
	Madi():BacketballPlayer(){}
	void attach()const override
	{
		std::cout<<"Madi attach"<<std::endl;
	}
	void defense()const override
	{
		std::cout<<"Madi defense"<<std::endl;
	}
};

class Yaoming
{
friend class  Adapter;
private: 
    Yaoming()=default; 
	void attach001()const
	{
		std::cout<<"Ò¦Ã÷ ½ø¹¥"<<std::endl;
	}
	void defense001()const
	{
		std::cout<<"Ò¦Ã÷ ·ÀÊØ"<<std::endl;
	}
};

class Adapter:public BacketballPlayer
{
public:
	Adapter():BacketballPlayer(){}
public:
	void attach()const override
	{
		yaoming.attach001();
	}
	void defense()const override
	{
		yaoming.defense001();
	}
private:
	Yaoming yaoming;
};

int main()
{
	BacketballPlayer *madi=new Madi();
	madi->attach();
	BacketballPlayer *yaoming=new Adapter();
	yaoming->defense();
	return 0;
}
