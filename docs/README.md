# Steering Wheel Board Functional Requirements
- - - -
## Sensors to Poll
This is all the data it should collect, the frequency at which they should be sent, and how they should be collected.

* Temperature and humidity (TEMP_SENSOR): 100ms
	* Use the highest resolution available for both metrics
	* Use the highest I2C clock speed supported by both ends
* Encoder (SW_ACCEL) position: 10ms
	* Send as absolute position, 7-bit
	* Just read the bits in parallel from GPIO
* Button state: 50ms
	* Including the switch (SW-SPDT), the button (K1), navigation pad (SW_NAV) buttons x5, and navigation pad encoder state
	* Navigation encoder state is sent as 8-bit signed displacement between samples
		* Ideally use the encoder mode of the timer peripheral this is hooked up to
- - - -
## Protocol
* Serial is set up at 115200 bps 8N1
* Data is sent in raw bytes, little endian
* Simply sign extend any data that’s not a nice size.
* Start every frame with 0xa5, followed by a data identifier: 0x01, 0x02 or 0x03.
* Append every frame with CRC-32 checksum. Just poll for CRC, don’t bother with DMA. Use the default (reset value) ethernet checksum in the hardware CRC peripheral. Don’t enable any bit swapping
* Don’t bother with endian, make the message a packed struct with the appropriate widths for each value and just write to the struct
* Frame formats: ( {name[size]} )
	* 0x01: Temp data
		* `{0xa5[8], 0x01[8], temp[16], RH[16], CRC[32]}`
	* 0x02: Encoder data
		* `{0xa5[8], 0x02[8], pos[8], CRC[32]}`
	* 0x03: Button data
		* `{0xa5[8], 0x03[8], {SW_SPDT_L[1], SW_SPDT_R[1], K1[1], SW_NAV_U[1], SW_NAV_D[1], SW_NAV_L[1], SW_NAV_R[1], SW_NAV_ENTER[1]}[8], SW_NAV_ENC[8], CRC[32]}`
