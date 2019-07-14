## Temperature/Humidity sensor configuration
- Slave address: 0x40

USER REGISTER 1
- Read register
    - Verify VDD ok
- Default reset value is ok (0x39)
    - Disable heater
    - 12-bit RH; 14-bit Temperature

Initialize Sensor: 
- Get Sensor ID (0xFC 0xC9)
- Verify (SNB_3 == 0x06) -> Si7006 chip
- Get firmware revision
- Send RESET command
- Delay 15 ms (wait for setup)
- Read RH/T User Register 1 and verify settings (0x39)
    - If not equal, write value (0x39)

Task structure: 
- Send read RH command, no hold master (0xF5)
- Delay 12 ms (for measurement)
- Send slave address to read RH measurement
- Send read Temp after RH measurement (0xE0)
    - Store temp data
- Assemble data string (json)
- UART synchronous send (1ms timout)
- Delay until (100ms)

## Acceleration encoder settings
No intialization needed!

Task structure: 
- Read GPIO data 
- Map GPIO data
- UART synchronous send (1ms timeout)


## Nav pad encoder settings
