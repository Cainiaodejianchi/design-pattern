#include<string>
#include<iostream>


class People
{
public:
	People()=default;
	People(std::string s):name(s){}
public:
	virtual void ImageDisplay() const
	{
		std::cout<<name<<" display :"<<std::endl;
	}
private:
	std::string name;
};

//*************
class Decoration:public People
{
friend class DecorationA;
private:
	virtual void ImageDisplay() const
	{
		people->ImageDisplay();
	}
protected:
	void decoration(People* name){
		people=name;
	}
protected:
	People* people;
};

class WearTshirt : public Decoration
{
friend class DecorationA;
private:
	void ImageDisplay() const override
	{
		people->ImageDisplay();
		std::cout<<"TS display"<<std::endl;
	}
};

class WearShoes : public Decoration
{
friend class DecorationA;
private:
	void ImageDisplay() const override
	{
		people->ImageDisplay();
		std::cout<<"Shoes display"<<std::endl;
	}
};

class DecorationA:public People
{
public:
	DecorationA(std::string s):people(s){}
	DecorationA(People name):people(name){}
private:
	void ImageDisplay() const override
	{
		people.ImageDisplay();
	    People A("using design1");
	    Decoration* Shoes=new WearShoes;
	    Decoration* TS=new WearTshirt;
	    Shoes->decoration(&A);
	    TS->decoration(Shoes);
	    TS->ImageDisplay();
	}
	People people;
};
int main()
{
	People *plan1=new DecorationA("xiaoming");
	plan1->ImageDisplay();
	return 0;
}
