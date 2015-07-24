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
    converter.begin(0,2,MAX11609::REF_VDD); // For ESP8266 Arduino SDK. Use pins GPIO0 for SDA, use pin GPIO2 for SCL. VDD (3.3V) is reference (i.e. VDD = 3.3V = 1023)
}

void loop()
{
    uint16_t result = converter.read(3); // channel can be [0-7]

    Serial.println(result);

    delay(1000); // read every 1 second
}
