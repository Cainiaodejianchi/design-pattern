#include<string>
#include<iostream>
class GamePlayer
{
friend class Game; 
public:
	GamePlayer()=default;
private:
	GamePlayer(double i,double j,double k):life(i),attach(j),defense(k){}
public:
	GamePlayer operator=(const GamePlayer &p)
	{
		life=p.life;
		attach=p.attach;
		defense=p.defense;
		return *this;
	}
private:
	void show()
	{
		std::cout<<name<<":"<<"生命力: "<<life<<";攻击力: "<<attach<<";防御力:"<<defense<<std::endl;
	}
private:
	double life=1.0;
	double attach=100;
	double defense=100;
public:
	static const std::string name;
};
const std::string GamePlayer::name="xiaoming";


class Memento
{
friend class Game;
public:
	Memento()=default;
	Memento(const std::string s,GamePlayer p):gameprocess(s),player(p){}
private:
	std::string gameprocess;
	GamePlayer player;	
};

class Game
{
public:
	Game()=default;
	Game(const std::string s):gameprocess(s)
	{
		player=GamePlayer();
	}
	//savegameprocess保存了过多的数据，且对外开放不好；可以使用备忘录模式； 
	/*************************
	Game savegameprocess()
	{
		return *this;
	}
	*******************************/
	void playgame()
	{
		gameprocess="game processing";
		player=GamePlayer(0.5,50,50);
	}
	void gameover()
	{
		gameprocess="game over";
		player=GamePlayer(0,0,0);
	}
	//**************************************
	Memento creatememente()
	{
		return Memento(gameprocess,player);
	}
	void setmemento(Memento m)
	{
		gameprocess=m.gameprocess;
		player=m.player;
	}
	void show()
	{
		std::cout<<gameprocess<<":"<<std::endl;
		player.show();
	}
private:
	std::string gameprocess;
	GamePlayer player;
};



class CareMemento
{
public:
	CareMemento()=default;
	Memento memento;
};


int main()
{
	Game dadoudou("game begining");
	dadoudou.show();
	//Game save1=dadoudou.savegameprocess();
	CareMemento c;
	c.memento=dadoudou.creatememente();
	dadoudou.playgame();
	dadoudou.show();
	dadoudou.gameover();
	dadoudou.show();
	//c.memento=dadoudou.creatememente();
	dadoudou.setmemento(c.memento);
	dadoudou.show();
	return 0;
}
