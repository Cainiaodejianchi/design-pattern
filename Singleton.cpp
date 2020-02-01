#include<iostream>

//多线程单实例安全，lock
class Singleton final 
{
private:
	Singleton()=default;
public:
	static Singleton* getinstance(){
		//双重锁定，先判断实例是否存在，再进行加锁处理； 
		if(instance==nullptr){
		//lock(syncRoot){
			if(instance==nullptr){
		        instance=new Singleton();
	        }		
		//}
		} 
		return instance;
	}
	~Singleton(){
		delete(instance);
		instance=nullptr;
	}
private:
	//static const void* syncRoot=new void(); 程序运行时创建一个静态只读的进程辅助对象； 
	static Singleton* instance;
	//static Singleton* instance=new Singleton(); 饿汉模式； 
};
Singleton* Singleton::instance=nullptr;

int main()
{
	return 0;
}
 
/*****************************************
class Formtoolbox
{
friend class Menu;
friend class ToolButton;
public:
	bool isdispond()
	{
		if(ftb==nullptr)
		return true;
		ftb=nullptr;
		return false;
	}
private:
	void create()
	{
		if(ftb==nullptr||ftb->isdispond()){
		    ftb=new Formtoolbox();
		    std::cout<<"ok";
	    }
	}
private:
	Formtoolbox()=default;
public:
	static Formtoolbox* ftb;
};
Formtoolbox* Formtoolbox::ftb=nullptr;

class Menu
{
public:
	Menu(){
	    Formtoolbox::ftb->create();	
	}
};

class ToolButton
{
public:
	ToolButton(){
	    Formtoolbox::ftb->create();		
	}
};


int main()
{
	Menu m;
	Formtoolbox::ftb->isdispond();
	Menu n;
	ToolButton b;
	return 0;
}

*************************************************************/
