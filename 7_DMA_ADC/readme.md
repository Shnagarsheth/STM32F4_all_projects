*This STM32 main.c generated from CubeMX.* 

In this project we are starting ADC on a TIMER Interrupt. Used Base TIMER 7 on STM. 

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
Configure the pinouts according to your requirement:   
1.  **For this code configure PA1 as ADC1_IN1.**
2.  Go to *Timers* &#x2192; TIM7 &#x2192; Activated
3.  In the **NVIC settings** *Enable: TIM7 global interrupt.*  
4.  In the **Parameter settings** *Prescaler: 168-1*, *Counter Period: 1000-1.*
5.  Attach a POT to vary the input to ADC1 of STM32 board. 
6.  Activate **ADC1-IN1** 
7.  In **NVIC settings** of ADC1  *Enable: DMA2 Stream0 global interrupt.*  

Vola! you are ready to code 😀 in Keil μ-Vision IDE. Follow the main.c 