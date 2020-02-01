#include<unordered_map>
#include<string>
#include<iostream>

class Flyweight
{
public:
	Flyweight()=default;
	virtual void show(const unsigned val)const=0;
protected:
	std::string name="��Ʒչʾ��վ";
};

class CFlyweight:public Flyweight
{
public:
	CFlyweight():Flyweight(){
	}
	void show(const unsigned val)const{
		std::cout<<name<<" : "<<val<<std::endl;
	}
};

class UCFlyweight:public Flyweight
{
public:
	UCFlyweight():Flyweight(){
		name="��Ʒչʾ��վ(���ɹ�����)";
	}
	void show(const unsigned val)const{
		std::cout<<name<<" : "<<val<<std::endl;
	}
};

class FlyweightFactory
{
public:
	FlyweightFactory():lookup(std::unordered_map<std::string,Flyweight*>()){}
	Flyweight* getflyweight(std::string s){
		if(lookup.find(s)==lookup.end()) 
		lookup[s]=new CFlyweight();        //�δ������ͷţ����� �������������������ϣ��ͻ��˵�ֻ��һ������ָ�� 
		return lookup[s];
	}
	int size()const{
		int count=0;
		for(auto it=lookup.begin();it!=lookup.end();++it){
			++count;
		}	
		return count;	
	} 
	~FlyweightFactory(){
		for(auto it=lookup.begin();it!=lookup.end();++it){
			delete(it->second);
			it->second=nullptr;
		}
	}
private:
	std::unordered_map<std::string,Flyweight*> lookup;
};

int main()
{
	unsigned val=20;
	FlyweightFactory f;
	Flyweight* fx=f.getflyweight("X");
	fx->show(--val);
	Flyweight* fy=f.getflyweight("Y");
	fy->show(--val);
	Flyweight* fz=f.getflyweight("Z");
	fz->show(--val);
	UCFlyweight z;
	z.show(--val);
	
	
	//****************
	//std::cout<<fx<<std::endl;
	Flyweight* fxsame=f.getflyweight("X");//����һ����ַ�� val�൱��ID�� 
	fxsame->show(--val);
	//std::cout<<fxsame<<std::endl;
	std::cout<<f.size();
	return 0;
}
