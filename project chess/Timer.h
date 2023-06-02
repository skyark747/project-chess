#pragma once
struct Position
{
    int ri, ci;
};
class Timer
{
private:
    int minute, sec;
    Position screen_position;

public:
    Timer();
    void setTimer(int m, int s, int, int); // sr and sc are screen coordinates    
    void increment(); 
    void printstandard();
};

