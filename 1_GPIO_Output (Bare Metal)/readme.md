*This STM32 main.c generated from CubeMX.* 

Do the follwing setting in CubeMX to get started:

1. *New Project* &#x2192; *Start My Project from MCU* &#x2192; *Access to MCU selector*.
2. Select the board **STM32F407VG** to initialze the project.
3. Configure the pinouts according to your requirement.
4. For this code configure PD12 to PD15 (OnBoard LEDs) as GPIO_Outputs.
5. Go to *System Core* &#x2192; *RCC* &#x2192; *High Speed Clock (HSE)* &#x2192; *Crsytal/Ceramic Resonator*
6. Switch to *Clock Configuration* tab.
    * Set *Input frequency* to 8 Mhz
    * Select *HSE* and *PLLCLK* and write 168Mhz in *HCLK*
 7. Switch to *Project Manager* tab 
    * Select **MDK-ARM** from *Code Generator* &#x2192; *ToolChain IDE.*
    * Choose your folder and click on **Generate Code**
 
Vola you are ready to code 😀 in Keil μ-Vision IDE. Follow the main.c 
