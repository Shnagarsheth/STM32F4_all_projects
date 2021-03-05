### **ST M24C16-RP (EEPROM) Notes**
___
**Pin Configuration:**   
1. Pin no. 4 -Vss-GND  
2. Pin no. 5 (on EEPROM) - SDA --> PB7 on STM32F407 (I2C pins)  
3. Pin no. 6 - SCL --> PB6 on STM32F407 (I2C pins)  
4. Pin no. 7 - WC - Low for write  
5. Pin no. 8 - Vcc - Supply 3.3V 
___
> 4 -bit device type identifier 1 0 1 0 A10 A9 A8 1/0 (R/W)

>Change A10 A9 A8 from 000 to 111 for accessing all the memory addresses.

> At a time only 16 pages with 0 to 255 memmory address can be accessed from One Device Address, e.g. 0 to Write and A1 to read.
 
> Use A10 A9 A8 to access all other memory address.

> In one command of write and read maximum of only 16bytes of data cna be transfered and received. The additional will be 'Roll-Over' and will stored in the address again starting from the 'first'.

> In a Slab of 255 for 8 times.
---
**References:**  

1. [DATASHEET](https://www.st.com/resource/en/datasheet/m24c16-f.pdf)  
2. [Detailed Datasheet](https://www.jameco.com/Jameco/Products/ProdDS/697901-DS01.pdf)  
3. Youtube Channel by "Mohammad Yaqoob" for some greater start on STM32.   
4. HAL libraries of STMicroeletronics.  