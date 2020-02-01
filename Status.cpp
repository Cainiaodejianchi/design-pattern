#include<iostream>

//**************************************
class WorkStatus;
class Status
{
friend class WorkStatus;
protected:
	Status()=default;
	virtual void getstatus(WorkStatus &)=0;
};

//****************************************
Status* createstatus(const unsigned);

class WorkStatus
{
friend class StatusA;
friend class StatusB;
friend class StatusC;
public:
	WorkStatus(const unsigned i):hour(i)
	{
		status=createstatus(i);
	}
public:
	void sethour(const unsigned i)
	{
		hour=i;
	}
	void finish()
	{
		workfinish=true;
	}
	void request()
	{
		status->getstatus(*this);
	}
public:
	~WorkStatus()
	{
		delete(status);
	}
private:
    Status* status;
    unsigned hour;	
    bool workfinish=false;
};

//8-12 status : working
class StatusA:public Status
{
public:
	StatusA():Status(){}
private:
	void getstatus(WorkStatus &ws) override
	{
		std::cout<<"now I am working, time is "<<ws.hour++<<std::endl;
		ws.status=createstatus(ws.hour);
	}
};

//12-17 status : keep working
class StatusB:public Status
{
public:
	StatusB():Status(){}
private:
	void getstatus(WorkStatus &ws) override
	{
		std::cout<<"now I will keep working, time is "<<ws.hour++<<std::endl;
		ws.status=createstatus(ws.hour);
	}
};

//17-21 status : working or getting off working
class StatusC:public Status
{
public:
	StatusC():Status(){}
private:
	void getstatus(WorkStatus &ws) override
	{
		if(ws.workfinish)
		std::cout<<"now I am getting off working, time is "<<ws.hour++<<std::endl;
		else
		std::cout<<"now I was still keep working, tierd, time is "<<ws.hour++<<std::endl;
		ws.status=createstatus(ws.hour);
	}
};

//*************************************
Status* createstatus(const unsigned i)
{
	if(i<12)
	return new StatusA();
	else if(i<17)
	return new StatusB();
	else
	return new StatusC();
}

//**************************
int main()
{
	WorkStatus xiaoming(8);
	std::cout<<"My name is xiaoming, my daily routime below:"<<std::endl;
	for(int i=0;i<11;++i)
	xiaoming.request();
	xiaoming.finish();
	xiaoming.request();
	return 0;
}


