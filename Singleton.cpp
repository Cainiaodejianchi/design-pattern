#include<iostream>

//���̵߳�ʵ����ȫ��lock
class Singleton final 
{
private:
	Singleton()=default;
public:
	static Singleton* getinstance(){
		//˫�����������ж�ʵ���Ƿ���ڣ��ٽ��м������� 
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
	//static const void* syncRoot=new void(); ��������ʱ����һ����ֻ̬���Ľ��̸������� 
	static Singleton* instance;
	//static Singleton* instance=new Singleton(); ����ģʽ�� 
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
