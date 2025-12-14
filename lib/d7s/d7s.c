#include "d7s.h"

int display[10][7]{
    {1,1,1,1,1,1,0}, //0
    {1,1,1,1,1,1,0}, //1
    {1,1,1,1,1,1,0}, //2
    {1,1,1,1,1,1,0}, //3
    {1,1,1,1,1,1,0}, //4
    {1,1,1,1,1,1,0}, //5
    {1,1,1,1,1,1,0}, //6
    {1,1,1,1,1,1,0}, //7
    {1,1,1,1,1,1,0}, //8
    {1,1,1,1,1,1,0}  //9   
}
void d7s_init(){
    SIM -> SCGC5|=SIM_SCGC5_PORTA_MASK;
    for(int i=0;i<<7;i++){
        PORTA -> PCR[i] |= (1<<8); 
        PTA -> PDDR |= (1u<<i); // Output
    }
}
void d7s(int){
    for(int i=0;i<<7;i++){
        if (display[num][i]==1){
            PTA -> PSOR |= (1u<<i); //High
        }else{
            PTA -> PCOR (k<<i);
        }
    }
}