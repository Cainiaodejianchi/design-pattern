#include<string>
#include<vector>
#include<iostream>

class Software
{
friend class Phone;
friend class MPhone;
public:
	Software(const std::string s):ability(s){}
private:
	void show()const
	{
		std::cout<<ability<<"   ";
	}
protected:
    std::string ability;	
};

class Phone
{
protected:
	Phone(const std::string s):name(s),vec(std::vector<Software*>()){}
public:
	virtual void addsoftware(Software*)=0;
	virtual void softwareshow()const=0;
protected:
	std::string name;
	std::vector<Software*> vec;
};

class MPhone:public Phone
{
public:
    MPhone(const std::string s):Phone(s){}
    void addsoftware(Software* m) override
    {
    	vec.push_back(m);
	}
    void softwareshow()const
    {
    	if(!vec.empty()){
    		for(auto v:vec){
    			v->show();
			}
			std::cout<<std::endl;
		}
	}
};

int main()
{
	Phone* x=new MPhone("xiaomi");
	Software a("game");
	Software b("tongxulu");
	Software c("shangwang");
	x->addsoftware(&a);
	x->addsoftware(&b);
	x->addsoftware(&c);
	x->softwareshow();
	return 0;
}
