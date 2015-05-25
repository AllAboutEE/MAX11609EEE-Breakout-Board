/**
 * @brief Library for MAX11609EEE+ device. Datasheet: 
 *        http://www.mouser.com/ds/2/256/MAX11606-MAX11611-94219.pdf
 */

#ifndef _ALLABOUTEE_MAX11609_H_
#define _ALLABOUTEE_MAX11609_H_

    namespace AllAboutEE
    {
        class MAX11609
        {
        public:
            uint8_t begin();
            uint8_t setup(uint8_t data);
            uint8_t configuration(uint8_t data);
            uint8_t setChannel(uint8_t channel);
            uint8_t read(uint8_t channel=NULL);
            void scan(uint8_t *buffer);
        protected:

        private:
            const uint8_t ADDRESS = 0x33;
            uint8_t channel = 0x00;
        };
    }

#endif
