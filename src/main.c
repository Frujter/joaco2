#include "d7s.h"

volatile num = 0;

int main(){
    d7s_init;
    NVIC_EnableIRQ(PORTA_IRQ2);//habilito interrupciones
    PORTA -> PCR[2] |= (1 << 8); 
    PTA -> PDDR |= (1u << 2);//Defino los pines de las interrupciones como entradas
    PORTA -> PCR[2] = PORT_PCR_MUX(1) | PORTC_PCR_IRQC(0b1101);//Seteo la interrupción para el flanco de subida
    NVIC_SetPriority(PORTA_IRQ2,0); //n valor del 0 al 3 siendo 0 el de más prioridad.

}
while (1){
    
   

}

