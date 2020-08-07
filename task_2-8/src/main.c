#include <ses_common.h>
#include <ses_adc.h>
#include "ses_uart.h"

int main(void) {
        
    int16_t tempReading = 0;
    uint16_t lightReading= 0;
    uart_init(57600);;
    adc_init();

    for(;;){

        tempReading = adc_getTemperature();
        lightReading = adc_read(ADC_LIGHT_CH);
        fprintf(uartout, "The readings of temperature and light sensors are %d\t°C and %d\trespectively\n", tempReading, lightReading);
        _delay_ms(2500);
    
    }
    return 0;
}
