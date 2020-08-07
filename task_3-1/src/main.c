#include <ses_common.h>
#include <ses_button.h>
#include <ses_led.h>

int main(void) {

    sei();
    led_greenInit();
    led_redInit();
    button_init();

    pButtonCallback redToggle = &led_redToggle;
    pButtonCallback greenToggle = &led_greenToggle; 

    button_setJoystickButtonCallback(redToggle);
    button_setRotaryButtonCallback(greenToggle);
    
    for(;;);
}
