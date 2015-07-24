/**
 * @brief Arduino Library for MAX11609EEE+ device. Datasheet: 
 *        http://www.mouser.com/ds/2/256/MAX11606-MAX11611-94219.pdf
 */
#ifndef _ALLABOUTEE_MAX11609_H_
#define _ALLABOUTEE_MAX11609_H_

#include <Arduino.h>

    namespace AllAboutEE
    {
        class MAX11609
        {
        public:
            void begin(uint8_t sda, uint8_t scl, uint8_t vRef = NULL);
            void begin(uint8_t vRef = NULL);
            void setup(uint8_t data);
            void configuration(uint8_t data);
            uint16_t read(uint8_t channel);
            void scan(uint16_t *buffer);

            static const uint8_t ADDRESS = 0x33,
                         REF_EXTERNAL = 0x02, // As defined in Table 6. The external reference can range from 1V to VDD
                         REF_INTERNAL = 0x05, // As defined in Table 6. Reference will be 2.048V
                         REF_VDD = 0x00;
        protected:

        private:


        };
    }

#endif
