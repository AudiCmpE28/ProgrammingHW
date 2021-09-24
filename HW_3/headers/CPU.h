#ifndef CPU_H
#define CPU_H

class CPU //an abstract class, its just a class with a pure virtual function in it.
{
private:
    int move;

public:
    CPU(/* args */);
    virtual void generateMove()=0;//pure virtual function
    virtual int getMove()=0;
    virtual void printCPUMove()=0;
};

#endif /* CPU_H */
