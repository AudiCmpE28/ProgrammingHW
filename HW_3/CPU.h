#ifndef CPU_H_
#define CPU_H_

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
move =0;
}


#endif /* CPU_H_ */