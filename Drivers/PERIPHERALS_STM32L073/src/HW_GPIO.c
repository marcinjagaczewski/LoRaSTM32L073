#include "HW_GPIO.h"
#include "stm32l0xx_hal.h"
#include "stm32l0xx_ll_bus.h"
#include "stm32l0xx_ll_system.h"
#include "stm32l0xx_ll_exti.h"
#include "stm32l0xx_ll_gpio.h"

LL_GPIO_InitTypeDef gpio;

// void initLedGpio(void)
// {
//   LL_GPIO_InitTypeDef Gpio;
// 	 __HAL_RCC_GPIOA_CLK_ENABLE();
// 	 Gpio.Pin = LL_GPIO_PIN_5;
// 	 Gpio.Mode = LL_GPIO_MODE_OUTPUT;
// 	 Gpio.Speed = LL_GPIO_SPEED_FREQ_VERY_HIGH;
// 	 Gpio.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
// 	 Gpio.Pull = LL_GPIO_PULL_NO;

// 	 LL_GPIO_Init(GPIOA, &Gpio);
// 	 LL_GPIO_SetOutputPin(GPIOA, LL_GPIO_PIN_5);
// 	 HAL_Delay(1000);
// 	 LL_GPIO_ResetOutputPin(GPIOA, LL_GPIO_PIN_5);
// }

void initGpioSx1276(void)
{
	LL_EXTI_InitTypeDef exti_initstruct;

	LL_APB2_GRP1_EnableClock(LL_APB2_GRP1_PERIPH_SYSCFG);

	LL_IOP_GRP1_EnableClock(LL_IOP_GRP1_PERIPH_GPIOA);
	LL_IOP_GRP1_EnableClock(LL_IOP_GRP1_PERIPH_GPIOB);
	LL_IOP_GRP1_EnableClock(LL_IOP_GRP1_PERIPH_GPIOC);
	//reset
	gpio.Pin = RADIO_NRESET_PIN;
	gpio.Mode = LL_GPIO_MODE_OUTPUT;
	gpio.Speed = LL_GPIO_SPEED_FREQ_VERY_HIGH;
	gpio.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
	gpio.Pull = LL_GPIO_PULL_NO;
	LL_GPIO_Init(RADIO_NRESET_PORT, &gpio);
//	gpio = 0;
	//rxtx
	gpio.Pin = RADIO_RXTX_PIN;
	gpio.Mode = LL_GPIO_MODE_OUTPUT;
	gpio.Speed = LL_GPIO_SPEED_FREQ_VERY_HIGH;
	gpio.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
	gpio.Pull = LL_GPIO_PULL_NO;
	LL_GPIO_Init(RADIO_RXTX_PORT, &gpio);

	//DIO_0
	gpio.Pin = RADIO_DIO_0_PIN;
	gpio.Mode = LL_GPIO_MODE_INPUT;
	gpio.Speed = LL_GPIO_SPEED_FREQ_VERY_HIGH;
	gpio.Pull = LL_GPIO_PULL_DOWN;
	LL_GPIO_Init(RADIO_DIO_0_PORT, &gpio);

	LL_SYSCFG_SetEXTISource(LL_SYSCFG_EXTI_PORTA, LL_SYSCFG_EXTI_LINE10);
	exti_initstruct.Line_0_31   = LL_EXTI_LINE_10;
	exti_initstruct.LineCommand = ENABLE;
	exti_initstruct.Mode        = LL_EXTI_MODE_IT;
	exti_initstruct.Trigger     = LL_EXTI_TRIGGER_FALLING;
	LL_EXTI_Init(&exti_initstruct);
  	
	NVIC_EnableIRQ(EXTI4_15_IRQn);
	NVIC_SetPriority(EXTI4_15_IRQn,0);

	//DIO_1
	gpio.Pin = RADIO_DIO_1_PIN;
	gpio.Mode = LL_GPIO_MODE_INPUT;
	gpio.Speed = LL_GPIO_SPEED_FREQ_VERY_HIGH;
	gpio.Pull = LL_GPIO_PULL_DOWN;
	LL_GPIO_Init(RADIO_DIO_1_PORT, &gpio);
	
	LL_SYSCFG_SetEXTISource(LL_SYSCFG_EXTI_PORTB, LL_SYSCFG_EXTI_LINE3);
	exti_initstruct.Line_0_31   = LL_EXTI_LINE_3;
	exti_initstruct.LineCommand = ENABLE;
	exti_initstruct.Mode        = LL_EXTI_MODE_IT;
	exti_initstruct.Trigger     = LL_EXTI_TRIGGER_FALLING;
	LL_EXTI_Init(&exti_initstruct);
  	
	NVIC_EnableIRQ(EXTI2_3_IRQn);
	NVIC_SetPriority(EXTI2_3_IRQn,0);

	//DIO_2
	gpio.Pin = RADIO_DIO_2_PIN;
	gpio.Mode = LL_GPIO_MODE_INPUT;
	gpio.Speed = LL_GPIO_SPEED_FREQ_VERY_HIGH;
	gpio.Pull = LL_GPIO_PULL_DOWN;
	LL_GPIO_Init(RADIO_DIO_2_PORT, &gpio);
	
	LL_SYSCFG_SetEXTISource(LL_SYSCFG_EXTI_PORTB, LL_SYSCFG_EXTI_LINE5);
	exti_initstruct.Line_0_31   = LL_EXTI_LINE_5;
	exti_initstruct.LineCommand = ENABLE;
	exti_initstruct.Mode        = LL_EXTI_MODE_IT;
	exti_initstruct.Trigger     = LL_EXTI_TRIGGER_FALLING;
	LL_EXTI_Init(&exti_initstruct);

	NVIC_EnableIRQ(EXTI4_15_IRQn);
	NVIC_SetPriority(EXTI4_15_IRQn,0);

	//DIO_3
	gpio.Pin = RADIO_DIO_3_PIN;
	gpio.Mode = LL_GPIO_MODE_INPUT;
	gpio.Speed = LL_GPIO_SPEED_FREQ_VERY_HIGH;
	gpio.Pull = LL_GPIO_PULL_DOWN;
	LL_GPIO_Init(RADIO_DIO_3_PORT, &gpio);
	
	LL_SYSCFG_SetEXTISource(LL_SYSCFG_EXTI_PORTB, LL_SYSCFG_EXTI_LINE4);
	exti_initstruct.Line_0_31   = LL_EXTI_LINE_4;
	exti_initstruct.LineCommand = ENABLE;
	exti_initstruct.Mode        = LL_EXTI_MODE_IT;
	exti_initstruct.Trigger     = LL_EXTI_TRIGGER_FALLING;
	LL_EXTI_Init(&exti_initstruct);

	NVIC_EnableIRQ(EXTI4_15_IRQn);
	NVIC_SetPriority(EXTI4_15_IRQn,0);

	//DIO_4A
	// gpio.Pin = RADIO_DIO_4A_PIN;
	// gpio.Mode = LL_GPIO_MODE_INPUT;
	// gpio.Speed = LL_GPIO_SPEED_FREQ_VERY_HIGH;
	// gpio.Pull = LL_GPIO_PULL_DOWN;
	// LL_GPIO_Init(RADIO_DIO_4A_PORT, &gpio);
	
	// LL_SYSCFG_SetEXTISource(LL_SYSCFG_EXTI_PORTA, LL_SYSCFG_EXTI_LINE9);
	// exti_initstruct.Line_0_31   = LL_EXTI_LINE_9;
	// exti_initstruct.LineCommand = ENABLE;
	// exti_initstruct.Mode        = LL_EXTI_MODE_IT;
	// exti_initstruct.Trigger     = LL_EXTI_TRIGGER_FALLING;
	// LL_EXTI_Init(&exti_initstruct);

	// NVIC_EnableIRQ(EXTI4_15_IRQn);
	// NVIC_SetPriority(EXTI4_15_IRQn,0);

	//DIO_4B
	// gpio.Pin = RADIO_DIO_4B_PIN;
	// gpio.Mode = LL_GPIO_MODE_INPUT;
	// gpio.Speed = LL_GPIO_SPEED_FREQ_VERY_HIGH;
	// gpio.Pull = LL_GPIO_PULL_DOWN;
	// LL_GPIO_Init(RADIO_DIO_4B_PORT, &gpio);
	
	// LL_SYSCFG_SetEXTISource(LL_SYSCFG_EXTI_PORTB, LL_SYSCFG_EXTI_LINE0);
	// exti_initstruct.Line_0_31   = LL_EXTI_LINE_0;
	// exti_initstruct.LineCommand = ENABLE;
	// exti_initstruct.Mode        = LL_EXTI_MODE_IT;
	// exti_initstruct.Trigger     = LL_EXTI_TRIGGER_FALLING;
	// LL_EXTI_Init(&exti_initstruct);

	// NVIC_EnableIRQ(EXTI0_1_IRQn);
	// NVIC_SetPriority(EXTI0_1_IRQn,0);

	//DIO_5
	// gpio.Pin = RADIO_DIO_5_PIN;
	// gpio.Mode = LL_GPIO_MODE_INPUT;
	// gpio.Speed = LL_GPIO_SPEED_FREQ_VERY_HIGH;
	// gpio.Pull = LL_GPIO_PULL_DOWN;
	// LL_GPIO_Init(RADIO_DIO_5_PORT, &gpio);
	
	// LL_SYSCFG_SetEXTISource(LL_SYSCFG_EXTI_PORTC, LL_SYSCFG_EXTI_LINE7);
	// exti_initstruct.Line_0_31   = LL_EXTI_LINE_7;
	// exti_initstruct.LineCommand = ENABLE;
	// exti_initstruct.Mode        = LL_EXTI_MODE_IT;
	// exti_initstruct.Trigger     = LL_EXTI_TRIGGER_FALLING;
	// LL_EXTI_Init(&exti_initstruct);

	// NVIC_EnableIRQ(EXTI4_15_IRQn);
	// NVIC_SetPriority(EXTI4_15_IRQn,0);
	
	//SPI GPIO
	//NSS
	gpio.Pin = RADIO_NSS_PIN;
	gpio.Mode = LL_GPIO_MODE_OUTPUT;
	gpio.Speed = LL_GPIO_SPEED_FREQ_VERY_HIGH;
	gpio.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
	gpio.Pull = LL_GPIO_PULL_NO;
	LL_GPIO_Init(RADIO_NSS_PORT, &gpio);
	//MOSI
	gpio.Pin = RADIO_MOSI_PIN;
	gpio.Mode = LL_GPIO_MODE_ALTERNATE;
	gpio.Speed = LL_GPIO_SPEED_FREQ_VERY_HIGH;
	gpio.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
	gpio.Pull = LL_GPIO_PULL_NO;
	gpio.Alternate = LL_GPIO_AF_0;
	LL_GPIO_Init(RADIO_MOSI_PORT, &gpio);
	//MISO
	gpio.Pin = RADIO_MISO_PIN;
	gpio.Mode = LL_GPIO_MODE_ALTERNATE;
	gpio.Speed = LL_GPIO_SPEED_FREQ_VERY_HIGH;
	gpio.Pull = LL_GPIO_PULL_NO;
	gpio.Alternate = LL_GPIO_AF_0;
	LL_GPIO_Init(RADIO_MISO_PORT, &gpio);	
	//SCK
	gpio.Pin = RADIO_SCK_PIN;
	gpio.Mode = LL_GPIO_MODE_ALTERNATE;
	gpio.Speed = LL_GPIO_SPEED_FREQ_VERY_HIGH;
	gpio.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
	gpio.Pull = LL_GPIO_PULL_NO;
	gpio.Alternate = LL_GPIO_AF_0;
	LL_GPIO_Init(RADIO_SCK_PORT, &gpio);
}

void gpioSX1276ResetSet(gpioState_t state)
{
	if(state == Set)
		{ LL_GPIO_SetOutputPin(RADIO_NRESET_PORT, RADIO_NRESET_PIN); }
	else
		{ LL_GPIO_ResetOutputPin(RADIO_NRESET_PORT, RADIO_NRESET_PIN); }
}

void gpioNssState(gpioState_t state)
{
	if(state == Set)
		{ LL_GPIO_SetOutputPin(RADIO_NSS_PORT, RADIO_NSS_PIN); }
	else
		{ LL_GPIO_ResetOutputPin(RADIO_NSS_PORT, RADIO_NSS_PIN); }
}


/***********************IRQ***********************/
void EXTI0_1_IRQHandler(void)
{
	if(LL_EXTI_IsActiveFlag_0_31(LL_EXTI_LINE_0) != RESET)
 {
 	asm("bkpt #1");
   LL_EXTI_ClearFlag_0_31(LL_EXTI_LINE_0);
 }
}

void EXTI2_3_IRQHandler(void)
{
	if(LL_EXTI_IsActiveFlag_0_31(LL_EXTI_LINE_3) != RESET)
  {
  	asm("bkpt #1");
    LL_EXTI_ClearFlag_0_31(LL_EXTI_LINE_3);
  }
}

void EXTI4_15_IRQHandler(void)
{
	if(LL_EXTI_IsActiveFlag_0_31(LL_EXTI_LINE_4) != RESET)
  {
		asm("bkpt #1");
    LL_EXTI_ClearFlag_0_31(LL_EXTI_LINE_4);
  }

	if(LL_EXTI_IsActiveFlag_0_31(LL_EXTI_LINE_5) != RESET)
  {
		asm("bkpt #1");
    LL_EXTI_ClearFlag_0_31(LL_EXTI_LINE_5);
  }

 if(LL_EXTI_IsActiveFlag_0_31(LL_EXTI_LINE_7) != RESET)
 {
		asm("bkpt #1");
   LL_EXTI_ClearFlag_0_31(LL_EXTI_LINE_7);
 }
//
	// if(LL_EXTI_IsActiveFlag_0_31(LL_EXTI_LINE_9) != RESET)
	//  {
	// 		asm("bkpt #1");
	//    LL_EXTI_ClearFlag_0_31(LL_EXTI_LINE_9);
	//  }

  if(LL_EXTI_IsActiveFlag_0_31(LL_EXTI_LINE_10) != RESET)
  {
		asm("bkpt #1");
    LL_EXTI_ClearFlag_0_31(LL_EXTI_LINE_10);
  }
}
