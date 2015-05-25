#include "AllAboutEE_MAX11609.h"
#include <Wire.h>

/**
 * Sets up the MAX11609 with a default configuration.
 * 
 * @author Miguel (5/24/2015)
 */
void AllAboutEE::MAX11609::begin()
{
    return 0;
}

/**
 * Writes the setup byte (see Table 1. pg 13 of the datasheet).
 * 
 * @author Miguel (5/24/2015)
 * 
 * @param data The setup byte to write
 * 
 * @return uint8_t status code
 */
uint8_t AllAboutEE::MAX11609::setup(uint8_t data)
{
    return 0;
}

/**
 * Writes the configuration byte (see Table 2. pg 14 of the 
 * datasheet).
 * 
 * @author Miguel (5/24/2015)
 * 
 * @param data The configuration byte to write
 * 
 * @return uint8_t status code
 */
uint8_t AllAboutEE::MAX11609::configuration(uint8_t data)
{

    return 0;
}

/**
 * Sets the converter's Channel Select (CS) bits.
 * 
 * @author Miguel (5/24/2015)
 * 
 * @param channel The channel number (0 to 7)
 * 
 * @return uint8_t status code
 */
uint8_t AllAboutEE::MAX11609::setChannel(uint8_t channel)
{
    this.channel = channel;

    // write CS bits

    return 0;
}

/**
 * Single conversion: Converts and reads the set channel.
 * 
 * @author Miguel (5/24/2015)
 * 
 * @param channel The channel to convert or read. Alternatively 
 *                if a channel was set already leave null.
 * 
 * @return uint8_t status code
 */
uint8_t AllAboutEE::MAX11609::read(uint8_t channel
{
    if(channel == NULL)
    {
        // read using set channel
    }
    else
    {
        // set channel 

        // read
    }

    return 0;
}

/**
 * Scan mode conversions. Reads channels up to set channel.
 * 
 * @author Miguel (5/24/2015)
 * 
 * @param buffer an array where the channel read values are put.
 */
void AllAboutEE::MAX11609::scan(uint8_t *buffer)
{
    for(uint8_t i = 0;i<=channel;i++)
    {
        // read channel to buffer
    }
}
