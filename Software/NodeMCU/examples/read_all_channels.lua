--
-- Break out board product page: https://www.tindie.com/products/AllAboutEE/esp8266-analog-inputs-expander/
-- 
-- @description An example that shows how you can read from a single pin (channel A3)
-- every 1000 milliseconds (1 second). Assumes you power the board from 3.3V Note: The max voltage is 3.6V so DO NOT use 5V
--

require("max11609eee")

gpio0, gpio2 = 3, 4 -- NodeMCU maps pins GPIO0 and GPIO2 to indices 3 and 4 respectively

pinSDA = gpio0 -- We'll use GPIO0 for I2C's SDA
pinSCL = gpio2 -- We'll use GPIO2 for I2C's SCL

max11609eee.begin(pinSDA,pinSCL)  -- assign pins
max11609eee.setup(max11609eee.REF_VDD) -- use VDD as reference

-- Continously execute the function code every 1000 milli seconds (1 second)
tmr.alarm(0,1000,1,function()
  
  for i=0,7 do
    local digitalValue = max11609eee.read(i) -- read from specified pin
    local voltageValue = digitalValue * 3.3 / 1024 -- convert the digital value to a voltage value
    print("Pin A"..i..": ")
    print("Digital Value: "..digitalValue)
    print("Voltage Value: "..voltageValue)
    print("\r\n")
  end

end)

