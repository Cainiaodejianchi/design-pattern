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
		"�����ʵ��"; 
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
