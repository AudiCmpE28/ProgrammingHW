#ifndef CPU_H
#define CPU_H

class CPU
{
private:
    int move;

public:
    CPU(/* args */);

    void generateMove();
    int getMove();
    void printCPUMove();
};

#endif /* CPU_H */
