#include <ses_common.h>
#include <ses_button.h>
#include <ses_led.h>
#include <ses_timer.h>


int main(void) {

    led_redInit();
    led_greenInit();

    pButtonCallback joystickCallback = &led_redToggle;
    pButtonCallback rotaryCallback = &led_greenToggle;

    button_setJoystickButtonCallback(joystickCallback);
    button_setRotaryButtonCallback(rotaryCallback);

    button_init(true); // true = debounced, false = direct interrupt
    sei();

    for(;;);

    return 0;
}

