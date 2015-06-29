#include <Wire.h>
#include <AllAboutEE_MAX11609.h>

using namespace AllAboutEE;

MAX11609 converter;

void setup()
{
    converter.begin(MAX11609::REF_VDD);
}

void loop()
{

}
