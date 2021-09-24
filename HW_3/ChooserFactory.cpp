#include "headers/ChooserFactory.h"
#include "headers/CPU.h"



static CPU *ChooserFactory::makeChooser(brainPower bp){
    if(bp == random) return new RandomChooser();    
    else if (bp == smart)  return new SmartChooser();    
    else if (bp == genius) return new GeniusChooser();
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