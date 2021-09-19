#ifndef CPU_H_
#define CPU_H_
#pragma once

class CPU
{
private:
    char move;
public:
    CPU(/* args */);
    char playMove(char CPUmove);    
};

CPU::CPU()
{
move =0;
}


#endif /* CPU_H_ */