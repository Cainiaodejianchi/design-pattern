class Subject
{
protected:
	virtual void request()const=0;
};

calss RealSubject:public Subject
{
friend class Proxy;
private:
	void request()const
	{
		"具体的实现"; 
	}
};

class Proxy:public Subject
{
public:
	void request()const
	{
		 realSubject->request();
	}
private:
	RealSubject* realSubject;	
};

int main()
{
	return ;
}
