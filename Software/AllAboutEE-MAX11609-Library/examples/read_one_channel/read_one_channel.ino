/**
 * MAX11609 Breakout/Development Board: 
 *  
 * Description: Shows how to use the "read" function to read an 
 * individual channel ( channel 3 in this case). 
 */
#include <Wire.h>
#include <AllAboutEE_MAX11609.h>

using namespace AllAboutEE;

MAX11609 converter;

void setup()
{
    Serial.begin(9600);
    converter.begin(MAX11609::REF_VDD); // use VDD as reference
}

void loop()
{
    uint16_t result = converter.read(3); // channel can be [0-7]

    Serial.println(result);

    delay(1000); // read every 1 second
}
