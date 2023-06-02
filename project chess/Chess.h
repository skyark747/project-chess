#pragma once
#include <stack>
class Board;
class Player;
class Timer;
class Chess
{
private:
	int sr, sc, dr, dc;
	int T;
	Player* Ps[2];
	Board* B;
	Timer* Tm;
	std::stack<Board*>m_undo;
	std::stack<Board*>save;
	std::stack<Board*>m_redo;
public:
	Chess();
	void print();
	void Tmsg(Player* P) const;
	int changeturn();
	void selectsc();
	void selectdc();
	void mousemovesc();
	void mousemoveds();
	bool isvalidsc(int sr, int sc, int dim, Player* P);
	bool isvaliddc(int sr, int sc, int dim, Player* P);
	bool islegalmove(int sr, int sc, int dr, int dc, Player* P);
	void highlight(int dim, int sr, int sc, int dr, int dc, Player* P);
	bool CheckKing(int sri, int sci, int& dri, int& dci);
	bool selfcheck(int sri, int sci, int dri, int dci);
	bool ischeckmate(int sri, int sci, int dri, int dci);
	void promotepawn(int sri, int sci, int dri, int dci);
	void piecehasmoved(int sri,int sci);
	void castle(int sri, int sci, int dri, int dci);
	void TimerChesswhite(Timer*& T, int& size);
	void TimerChessblack(Timer*& T, int& size);
	void DisplayTimer(Timer* T, int size);
	void play();
	void undomove(int &r,int &c);
	void redomove(int &r,int &c);
	void load();
	void loadgame();
	void clearundo();
	void cleargame();
	void clearredo();
	~Chess()
	{
		clearundo(); clearredo(); cleargame();
	}
};

