#include<string>
#include<vector>
#include<iostream>

class Cooker
{
friend class Menu;
friend class MenuA;
friend class MenuB;
public:
    Cooker()=default;
private:
	void work1()const{
		std::cout<<"¿¾¼¦ÍÈ"<<std::endl; 
	}
	void work2()const{
		std::cout<<"¿¾ÑòÈâ´®"<<std::endl; 
	}
};

class Menu
{
public:
	Menu(Cooker c):cooker(c){}
	virtual void work()const=0;
protected:
	Cooker cooker;
};

class MenuA:public Menu
{
public:
	MenuA(Cooker c):Menu(c){}
	void work()const override{
		cooker.work1();
	}
};

class MenuB:public Menu
{
public:
	MenuB(Cooker c):Menu(c){}
	void work()const override{
		cooker.work2();
	}
};


class Waiter
{
public:
	Waiter():book(std::vector<Menu*>()){}
public:
	void addorder(Menu* m){
		std::cout<<"¿Í»§ÏÂµ¥£º"; 
		m->work();
		book.push_back(m);
	}
	void notify(){
		if(!book.empty()){
			for(auto v:book){
				v->work();
			}
		}
	}
private:
    std::vector<Menu*> book;	
};



//**************************************
/*
class Customer
{
public:
	Customer()=default;
	void order(const std::string s){
		val=waiter.addorder(s);
	}
	void changeorder(const std::string s){
		waiter.changeorder(s,val);
	}

private:
	unsigned val=0;
    static Waiter waiter;
};
Waiter Customer::waiter;

class Chef
{
	
};
**************************************************************/


int main()
{
	Cooker cooker;
	MenuA a(cooker);
	MenuB b(cooker);
	Waiter girl;
	
	girl.addorder(&a);
	girl.addorder(&b);
	girl.addorder(&b);
	
	girl.notify();
	
	return 0; 
}

