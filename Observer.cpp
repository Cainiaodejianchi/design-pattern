#include<iostream>
#include<string>
#include<vector>

class Observer
{
friend class Subject;
friend class SubjectA;
protected:
	Observer()=default;
	Observer(const std::string s):workstatus(s){}
protected:
	virtual void update()=0;
	std::string workstatus="working";
};

class RealObserver:public Observer
{
public:
	RealObserver():Observer(){}
	RealObserver(const std::string s):Observer(s){}
private:
	void update() override
	{
		if(workstatus!="working"){
			workstatus="working instead of"+workstatus;
		}
		std::cout<<workstatus<<std::endl;
	}
};

class Subject
{
protected:
	Subject():p(std::vector<Observer*>()){}
public:
	void addobserver(Observer* observer)
	{
		p.push_back(observer);
	}
	void subobserver(Observer* observer)
	{
		//p.erase(observer);
	}
protected:
	virtual void notify()=0;
protected:
	std::vector<Observer*> p;
};

class SubjectA:public Subject
{
public:
	SubjectA():Subject(){}
	void set(const bool status)
	{
		notifystatus=status;
	}
	void notify() override
	{
		if(notifystatus)
		for(auto o:p){
			o->update();
		}
	}
private:
	bool notifystatus=false;
};

int main()
{
	SubjectA secretary;
	RealObserver tongshi1("watching");
	RealObserver tongshi2("playing");
	RealObserver tongshi3;
	
	secretary.addobserver(&tongshi1);
	secretary.addobserver(&tongshi2);
	secretary.addobserver(&tongshi3);
	
	secretary.set(true);
	secretary.notify();
	return 0;
}



