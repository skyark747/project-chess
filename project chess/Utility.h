#pragma once
#include <iostream>
#include <Windows.h>
using namespace std;

enum Color { White, Black };
class Board;
void getRowColbyLeftClick(int& rpos, int& cpos);
void gotoRowCol(int rpos, int cpos);
void SetClr(int clr);
void SetClr(int clr, int bclr);
bool isvertical(int sci, int dci);
bool ishorizontal(int sri, int dri);
bool isdiagonal(int sri, int sci, int dri, int dci);
bool isverticalpathclear(int sri, int dri, int sci, int dci, Board* B);
bool ishorizontalpathclear(int sri, int dri, int sci, int dci, Board* B);
bool isdiagonalpathclear(int sri, int dri, int sci, int dci, Board* B);
bool isultadiagonalpathclear(int sri, int dri, int sci, int dci, Board* B);
bool isverticalup(int sri, int dri, int sci, int dci, Board* B);
bool isverticaldown(int sri, int dri, int sci, int dci, Board* B);
void hollowbox(int R, int C, int sr, int sc, char sym);
void drawcross(int cr, int cc, char sym);
void pawn(int R, int C, int sr, int sc, char sym);
void rook(int R, int C, int sr, int sc, char sym);
void rookpiece(int R, int C, int sr, int sc, char sym);
void knight(int R, int C, int sr, int sc, char sym);
void queen(int R, int C, int sr, int sc, char sym);
void king(int R, int C, int sr, int sc, char sym);
void bishop(int R, int C, int sr, int sc, char sym);