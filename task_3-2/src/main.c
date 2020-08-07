#include <ses_common.h>
#include <ses_led.h>
#include <ses_timer.h>

/* Counter to decrease toggling frequency for timer2 */
int softwareCount = 0; 

void softwareTimer(void){

    softwareCount++;
    /* check if 1000 ms is reached */
    if(softwareCount == 1000){ 
        softwareCount = 0;
        led_yellowToggle();
    }
}

int main(void) {

    led_yellowInit();

    pTimerCallback ledToggle = &softwareTimer;

    timer2_setCallback(ledToggle);
    timer2_start();
    
    sei();
    while(1){
        
    }

    return 0;
}


