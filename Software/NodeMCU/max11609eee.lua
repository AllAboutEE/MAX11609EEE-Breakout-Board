-- Break out board product page: https://www.tindie.com/products/AllAboutEE/esp8266-analog-inputs-expander/
-- Description: Library for the MAX11609 10-bit analog to digital converter with 8 analog input channels
local moduleName = ... 
local M = {}
_G[moduleName] = M 

-- Default value for i2c communication as per NodeMCU API
local id = 0

-- Constant device address.
local MAX11609EEE_ADDRESS = 0x33

M.REF_EXTERNAL = 0x02
M.REF_INTERNAL = 0x05
M.REF_VDD = 0x00

function M.begin(pinSDA, pinSCL,vRef)
  i2c.setup(id,pinSDA,pinSCL,i2c.SLOW)
end

function M.setup(data)
  i2c.start(id)
  i2c.address(id,MAX11609EEE_ADDRESS,i2c.TRANSMITTER)
  i2c.write(id,bit.bor(data,0x80))
  i2c.stop(id)
end

function M.configuration(data)
  i2c.start(id)
  i2c.address(id,MAX11609EEE_ADDRESS,i2c.TRANSMITTER)
  i2c.write(id,bit.band(data,bit.bnot(0x80)))
  i2c.stop(id)
end

function M.read(channel)
 local result = 0x0000
 local configurationByte = bit.bor(bit.band((bit.lshift(channel,1)),0x0E),0x61) -- equivalent to ( (channel<<1) & 0b00001110) | 0b01100001
 
 M.configuration(configurationByte)
 
 i2c.start(id)

 if(i2c.address(id,MAX11609EEE_ADDRESS,i2c.RECEIVER) ~= false) then
   local data = i2c.read(id,2)
   i2c.stop(id)
   local msb, lsb = string.byte(data,1,2)
   msb = bit.lshift(bit.band(msb,0x03),8)
   lsb = bit.band(lsb,0xff)
   result = bit.bor(msb,lsb)
   
   return result
 else
 
   i2c.stop(id)
   return -1
 end

end

return M
