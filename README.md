ST M24C16-RP (EEPROM) Notes

Pin Configuration: 
4 -Vss-GND 
5 - SDA --> PB7 on STM32F407 (I2C pins)
6 - SCL --> PB6 on STM32F407 (I2C pins)
7 - WC - Low for write
8 - Vcc - Supply 3.3V

A--> 4 -bit device type identifier 
     1 0 1 0 A10 A9 A8 1/0 (R/W)

Change A10 A9 A8 from 000 to 111 for accessing all the memory addresses.

B--> At a time only 16 pages with 0 to 255 memmory address can be accessed from One Device Address, 
     e.g. 0 to Write and A1 to read.

Use A10 A9 A8 to access all other memory address.

C--> In one command of write and read maximum of only 16bytes of data cna be transfered and received. 
     The additional will be 'Roll-Over' and will stored in the address again starting from the 'first'.

D--> In a Slab of 255 for 8 times. 