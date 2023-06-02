#pragma once
class Piece;

class Board
{
protected:
	int D;
	Piece*** P;
	
public:
	Board();
	Board(const Board& Brd);
	Board(int Dim);
	void drawboard();
	void drawbox(int sr, int sc, int R, int C, char sym, int clr, Piece* ps);
	Piece* getpiece(int r, int c);
	char getpiecesym(int r, int c);
	void updateBoard(int r, int c, int dr, int dc);
	void fakeupdate(int r, int c, int dr, int dc);
	Piece* findking(int sr, int sc, int& dr, int& dc, int T);
	void setpiece(int ri, int ci,char c);
	void chesspieces(int sr, int sc, int R, int C, char sym,Piece*ps);
};

