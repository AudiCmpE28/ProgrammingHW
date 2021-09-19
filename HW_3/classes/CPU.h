#ifndef CPU_H
#define CPU_H

class CPU
{
private:
    int move;

public:
    CPU(/* args */);
    int playMove();
};

CPU::CPU()
{
    move = 0;
}

#endif /* CPU_H_ */