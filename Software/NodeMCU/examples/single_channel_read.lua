--
-- Break out board product page: https://www.tindie.com/products/AllAboutEE/esp8266-analog-inputs-expander/
-- 
-- @description An example that shows how you can read from all the pins (channel A0 to A7)
-- every 1000 milliseconds (1 second). Assumes you power the board from 3.3V Note: The max voltage is 3.6V so DO NOT use 5V
--

require("max11609eee")

gpio0, gpio2 = 3, 4 -- NodeMCU maps pins GPIO0 and GPIO2 to indices 3 and 4 respectively

pinSDA = gpio0 -- We'll use GPIO0 for I2C's SDA
pinSCL = gpio2 -- We'll use GPIO2 for I2C's SCL

max11609eee.begin(pinSDA,pinSCL,max11609eee.REF_VDD)  -- assign pins connect VDD to 3.3v

-- Continously execute the function code every 1000 milli seconds (1 second)
tmr.alarm(0,1000,1,function()
  local digitalValue = max11609eee.read(3) -- read from pin A3 (analog input 3)
  local voltageValue = digitalValue * 3.3 / 1024
  print("Digital Value: "..digitalValue)
  print("Voltage Value: "..voltageValue)
end)


