#include<string>
#include<iostream>

class Country;
class Mediator
{
public:
	Mediator()=default;
public:
	virtual void send(Country* c,const std::string message)=0;
}; 

class Country
{
friend class CreateMediator;
public:
	Country(Mediator* m,const std::string s):mediator(m),name(s){}
protected:
	Country()=default;
    virtual void send(const std::string message)=0;
	Mediator* mediator;
	std::string name;
private:
	void notify(const std::string message){
		std::cout<<name<<" accept the message:"<<message<<std::endl;
	}
};

class CountryA:public Country
{
friend class CreateMediator;
public:
	CountryA(Mediator* m,const std::string s):Country(m,s){}
private:
	CountryA():Country(){}
public:
	void send(const std::string message)override{
		mediator->send(this,message);
	}
//private:
//	void notify(const std::string message){
//		std::cout<<name<<" accept the message:"<<message<<std::endl;
//	}
};

class CountryB:public Country
{
friend class CreateMediator;
public:
	CountryB(Mediator* m,const std::string s):Country(m,s){}
private:
	CountryB():Country(){}
public:
	void send(const std::string message)override{
		mediator->send(this,message);
	}
//private:
//	void notify(const std::string message){
//		std::cout<<name<<" accept the message:"<<message<<std::endl;
//	}
};

class CreateMediator:public Mediator
{
friend class Country;
friend class CountryA;
friend class CountryB;
public:
	CreateMediator(const std::string s):name(s){}
private:
    void send(Country* c,const std::string message){
    	if(c==countrymember1){
    		countrymember2->notify(message);
		}
		else{
			countrymember1->notify(message);
		}
	}
public:
	CountryA* countrymember1;
	CountryB* countrymember2;
private:
	std::string name;
};

int main()
{
	CreateMediator mediator("UN");
	CountryA country1(&mediator,"USA");
	CountryB country2(&mediator,"Irap");
	mediator.countrymember1=&country1;
	mediator.countrymember2=&country2;
	
	country1.send("no fighting?");
	country2.send("ok,stop fighting!!!");
	return 0;
}
