#include "SPI.h"
#include <avr/io.h>
#include "vendor/lgt/io.h"

#define SPI_DDRSPI DDRB
#define SPI_PORTSPI PORTB
#define SPI_SS PB1
#define SPI_MOSI PB3
#define SPI_MISO PB4
#define SPI_SCK PB5

volatile bool SPI::isLock = false;

void SPI::init()
{
    PMX0 |= _BV(WCE);
    PMX0 |= _BV(SSB1);
    SPCR |= _BV(MSTR);
    SPI_DDRSPI &= ~_BV(SPI_MISO);
    SPI_DDRSPI |= _BV(SPI_MOSI) | _BV(SPI_SCK) | _BV(SPI_SS);
    SPCR |= _BV(SPE);
}

uint8_t SPI::transmit(const uint8_t &data)
{
    SPDR = data;
    loop_until_bit_is_clear(SPFR, RDEMPT);
    return SPDR;
}

void SPI::slowMode()
{
    SPCR |= _BV(SPR1);
    SPCR |= _BV(SPR0);
}

void SPI::fastMode()
{
    SPCR &= ~_BV(SPR1);
    SPCR |= _BV(SPR0);
}

bool SPI::lock()
{
    if (!SPI::isLock)
    {
        SPI::isLock = true;
        return true;
    }
    return false;
}

void SPI::release()
{
    SPI::isLock = false;
}
