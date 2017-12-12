/**
  ******************************************************************************
  * File Name          : main.h
  * Description        : This file contains the common defines of the application
  ******************************************************************************
  *
  * COPYRIGHT(c) 2017 STMicroelectronics
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif
#include "stdint.h"
#include "stm32f407xx.h"
#include "stm32f4xx_hal.h"


/*pins available on dev board

A 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
B 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
C 0 1 2 3 4 5 6 7 8 9 10 11 12 13  
D 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15

E 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15

*/
//gpio E first byte output second byte input
//gpio D DDS bus
//USART1 rx=A10 tx=A9
//USART3 rx=B11 tx=C10
//I2S sdext=C2 sd=C3 ck=B10 ws=B12
//ADC1 A0
//ADC2 A1
//DAC1 A4
//DAC2 A5

#ifndef FALSE
#define FALSE 0
#define TRUE 1
#endif

#define GPIO_PINS GPIOE

#define LED_PIN GPIO_PIN_0

#define PTT_SWITCH GPIO_PIN_9

#define RXBUFFERSIZE    64
struct command{
char string[RXBUFFERSIZE];
uint8_t size;
};

#define RX 0
#define TX 1

//extern "C" __attribute__((__section__(".user_data"))) const uint8_t userConfig[64];
void _Error_Handler(char *, int);

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
