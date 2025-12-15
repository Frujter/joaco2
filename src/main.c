#include "d7s.h"

volatile num = 0;

int main(){
    
    NVIC_EnableIRQ(PORTA_IRQ2);//habilito interrupciones
    PORTA -> PCR[2] |= (1 << 8); 
    PTA -> PDDR |= (1u << 2);//Defino los pines de las interrupciones como entradas
    NVIC_SetPriority(PORTA_IRQ2,0); //n valor del 0 al 3 siendo 0 el de más prioridad.
    PORTA -> PCR[2] = PORT_PCR_MUX(1) | PORTC_PCR_IRQC(0b1101);//Seteo la interrupción para el flanco de subida
    d7s_init();

    while (1){
    bool mas = false;
    if (PORTA->ISFR & (1 << 2)){
        if ((num < 10)&&(!mas)){
            num++
            if(num==9){
                mas = true;
            }
        }else{
            num--;
        }
        if ((num)==0){
            mas = false;
        }     
    }
   

}
}



