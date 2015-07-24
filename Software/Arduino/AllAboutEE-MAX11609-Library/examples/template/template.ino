#include <Wire.h>
#include <AllAboutEE_MAX11609.h>

using namespace AllAboutEE;

MAX11609 converter;

void setup()
{
    converter.begin(0,2,MAX11609::REF_VDD); // For ESP8266 Arduino SDK. Use pins GPIO0 for SDA, use pin GPIO2 for SCL. VDD (3.3V) is reference (i.e. VDD = 3.3V = 1023)
}

void loop()
{

}
