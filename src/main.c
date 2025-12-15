#include "d7s.h"

volatile int num = 0;
volatile int mas = 0;

int main(){
    
    NVIC_EnableIRQ(PORTA_IRQ2);//habilito interrupciones
    PORTA -> PCR[2] |= (1 << 8); 
    PTA -> PDDR |= (1u << 2);//Defino los pines de las interrupciones como entradas
    NVIC_SetPriority(PORTA_IRQ2,0); //n valor del 0 al 3 siendo 0 el de más prioridad.
    PORTA -> PCR[2] = PORT_PCR_MUX(1) | PORTC_PCR_IRQC(0b1101);//Seteo la interrupción para el flanco de subida
    d7s_init();

    while (1){
     d7s(num);
    }
    return 0;
}
void PORTA_IRQHandler(){
    if (PORTA->ISFR & (1 << 2)){// verificar si la interrupción fue en PTX N
        PORTA->ISFR |= (1 << 2);  // Limpiar bandera de interrupción

        if ((num < 10)&&(mas==0)){
            num++
            if(num==9){
                mas = 1;
            }
        }else{
            num--;
        }
        if ((num)==0){
            mas = 0;
        }     
    } 

}