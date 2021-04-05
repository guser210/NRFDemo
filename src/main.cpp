#include "pico/stdlib.h"
#include "hardware/spi.h"
#include "NRF24.h"

#include <stdio.h>

int main(){

    NRF24 nrf(spi1, 9, 8);
    nrf.config();
    nrf.modeTX();

    char buffer[32];
    while(1){
        sprintf(buffer,"60");
        buffer[30] = 'R';
        buffer[31] = 'O'; // not a zero.
        nrf.sendMessage(buffer);
        sleep_ms(3000);

        sprintf(buffer,"-60");
        buffer[30] = 'R';
        buffer[31] = 'O'; // not a zero.
        nrf.sendMessage(buffer);
        sleep_ms(3000);

    }

    return 0;
}

