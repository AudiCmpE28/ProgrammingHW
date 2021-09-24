#include "headers/ChooserFactory.h"
#include "headers/CPU.h"

CPU *ChooserFactory::makeChooser(brainPower bp){
    if(bp == r) return new RandomChooser();    
    else if (bp == s)  return new SmartChooser();    
    else if (bp == g) return new GeniusChooser();
    else return nullptr;
}


/*
    CPU *cpuTurn;
    if(bp == random){
        CPU *cpuTurn = new RandomChooser();
        return*cpuTurn;  
    }     
    else if (bp == smart){
        CPU *cpuTurn = new SmartChooser();
        return*cpuTurn;    
    } 
    else if (bp == genius){
        CPU *cpuTurn = new GeniusChooser();
        return*cpuTurn;  
    } 
*/