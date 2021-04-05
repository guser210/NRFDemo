
#ifndef __NRF24_H_
#define __NRF24_H_
#include "hardware/spi.h"
#include "hardware/gpio.h"

class NRF24
{
private: // Vars.
    spi_inst_t *port;
    uint16_t csn;
    uint16_t ce;

public: // Vars.
    //TODO: Add public vars.
private: // Funcs.
    void csnLow(){ gpio_put(csn, 0);}
    void csnHigh(){ gpio_put(csn, 1);}
    void ceLow(){ gpio_put(ce, 0);}
    void ceHigh(){ gpio_put(ce, 1);}
public: /// Funcs.
    uint8_t readReg(uint8_t reg);

    void writeReg( uint8_t reg, uint8_t data);
    void writeReg( uint8_t reg, uint8_t *data, uint8_t size);

    void config();

    void modeTX();
    void modeRX();

    void sendMessage(char *msg);
    void receiveMessage(char *msg);

    uint8_t newMessage();

    void setChannel(uint8_t ch);
    void setRXName(char *name);
    void setTXName(char *name);

public:
    NRF24(spi_inst_t *port, uint16_t csn, uint16_t ce);
    ~NRF24();
};




#endif
