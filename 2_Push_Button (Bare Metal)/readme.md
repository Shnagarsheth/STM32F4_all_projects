*This STM32 main.c generated from CubeMX.* 

Do the follwing setting in CubeMX to get started:

**Common Steps to followed in every project:** 

1. *New Project* &#x2192; *Start My Project from MCU* &#x2192; *Access to MCU selector*.
2. Select the board **STM32F407VG** to initialze the project.
3. Go to *System Core* &#x2192; *RCC* &#x2192; *High Speed Clock (HSE)* &#x2192; *Crsytal/Ceramic Resonator*
4. Switch to *Clock Configuration* tab.
    * Set *Input frequency* to 8 Mhz
    * Select *HSE* and *PLLCLK* and write 168Mhz in *HCLK*
5. Switch to *Project Manager* tab 
    * Select **MDK-ARM** from *Code Generator* &#x2192; *ToolChain IDE.*
    * Choose your folder and click on **Generate Code**

**Specific steps:**  
1. Configure the pinouts according to your requirement.
2. **For this code configure PA0 as GPIO_Input (OnBoard PushButton).**

Vola you are ready to code 😀 in Keil μ-Vision IDE. Follow the main.c 