#include "ses_common.h"
#include "ses_led.h"
#include "ses_button.h"
#include "ses_lcd.h"


int main(void){

    button_init();
    led_redInit();
    led_redInit();
    led_greenInit();
    lcd_init();
    int counter=0;

    for(;;){

        led_redOff();
        led_greenOff();

        if(button_isRotaryPressed())
            led_redOn();
        if(button_isJoystickPressed())
            led_greenOn();

        _delay_ms(1000);
        counter++;
        fprintf(lcdout,"%d\t", counter);
    }
    return 0;
}



