#include "AllAboutEE_MAX11609.h"
#include <Arduino.h>
#include <Wire.h>

/**
 * Sets up the MAX11609 with a default configuration.
 * 
 * @author Miguel (5/24/2015)
 */
void AllAboutEE::MAX11609::begin(uint8_t vRef)
{
    Wire.begin();

    // 0 - don't care
    // 1 - reset configuration register to default
    // 2 - unipolar
    // 3 - internal clock
    // 4 - SEL0 (vRef)
    // 5 - SEL1 (vRef)
    // 6 - SEL2 (vRef)
    setup(vRef & 0xf0); // 0B[vRef2][vRef1][vRef0] 0000

    // 0 - Single Ended
    // 1 to 4 - Channel Select:  7
    // 5 to 6 - Scan Mode: read channels up to selected channel
    configuration(B00001111);
}

/**
 * Writes the setup byte (see Table 1. pg 13 of the datasheet).
 * 
 * @author Miguel (5/24/2015)
 * 
 * @param data The setup byte to write
 * 
 */
void AllAboutEE::MAX11609::setup(uint8_t data)
{
 
    Wire.beginTransmission(ADDRESS);
    Wire.write(data | 0x80); 
    Wire.endTransmission();
}

/**
 * Writes the configuration byte (see Table 2. pg 14 of the 
 * datasheet).
 * 
 * @author Miguel (5/24/2015)
 * 
 * @param data The configuration byte to write
 *  
 */
void AllAboutEE::MAX11609::configuration(uint8_t data)
{
    Wire.beginTransmission(ADDRESS);
    Wire.write(data & (~0x80)); // make REG bit 7 = 0 (configuration byte)
    Wire.endTransmission();
}

/**
 * Reads one channel.
 * 
 * @author Miguel (5/24/2015)
 * 
 * @param channel The channel to convert or read. Alternatively 
 *                if a channel was set already leave null.
 * 
 * @return uint16_t The conversion result or -1 if there's an 
 *         error.
 */
uint16_t AllAboutEE::MAX11609::read(uint8_t channel)
{

    uint16_t result = 0x0000;

    uint8_t configurationByte = ( (channel<<1) & B00001110) | B01100001;
    configuration(configurationByte);

    Wire.requestFrom(ADDRESS,2,false);

    if(Wire.available()==2) // the conversion consists of two bytes per channel
    {

        result = (Wire.read() & 0x03)<<8; // MSB is returned first. [7-2] are high.
        result |= Wire.read()&0x00ff; // read LSB
        

        return result;
    }
    else
    {
        return -1; // ERROR
    }

}

/**
 * Reads all channels conversion into a buffer/array.
 * 
 * @author Miguel (5/24/2015)
 * 
 * @param buffer an array where the channel read values are put.
 */
void AllAboutEE::MAX11609::scan(uint16_t *buffer)
{
    uint8_t configurationByte = B00001111;
    configuration(configurationByte);

    Wire.requestFrom(ADDRESS,16,false); // 2 bytes per channel. There are 8 channels.

    if(Wire.available()==16)
    {
        for(uint8_t i = 0;i<8;i++) // read all 8 channels [AIN0-AIN7]
        {

            *(buffer+i) = (Wire.read() & 0x03)<<8; // MSB is returned first. [7-2] are high.
            *(buffer+i) |= Wire.read()&0x00ff; // read LSB               
        }
    }
}
