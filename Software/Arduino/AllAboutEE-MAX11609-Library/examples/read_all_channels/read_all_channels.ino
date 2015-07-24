/**
 * MAX11609 Breakout/Development Board: 
 *  
 * Description: Shows how to use the scan function to read all 
 * the channels. 
 */
#include <Wire.h>
#include <AllAboutEE_MAX11609.h>

using namespace AllAboutEE;

MAX11609 converter;

void setup()
{
    Serial.begin(9600);
    converter.begin(0,2,MAX11609::REF_VDD); // For ESP8266 Arduino SDK. Use pins 0 for SDA, use pin 2 for SCL. VDD is reference (i.e. VDD = 1023)
    // converter.begin(MAX11609::REF_VDD); // Use this line instead of previous if you want to use Arduino the arduino instead of ESP8266. VDD is reference (i.e. VDD = 1023)
}

void loop()
{
    uint16_t result[8] = {0}; // There are 8 channels total

    converter.scan(result); // The conversion results are stored in the "result" array.

    // display results
    for(int i=0;i<8;i++)
    {
        Serial.print("Channel ");
        Serial.print(i);
        Serial.print(": ");
        Serial.println(result[i]);
        
    }
    Serial.println();

    delay(1000); // read every 1 second
}
