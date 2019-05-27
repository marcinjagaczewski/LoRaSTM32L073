#include <stdlib.h>
#include <stdio.h>
#include "stm32l0xx_ll_bus.h"
#include "stm32l0xx_ll_spi.h"
#include "HW_SPI.h"
#include "HW_GPIO.h"

LL_SPI_InitTypeDef spi1;
uint8_t data = 0;
uint8_t i = 0;

void initSpi1Sx1276(void)
{
	gpioSX1276ResetSet(Set);
	LL_APB2_GRP1_EnableClock(LL_APB2_GRP1_PERIPH_SPI1);
	gpioNssState(Set);
	spi1.TransferDirection = LL_SPI_FULL_DUPLEX;
	spi1.Mode = LL_SPI_MODE_MASTER;
	spi1.DataWidth = LL_SPI_DATAWIDTH_8BIT;
	spi1.ClockPolarity = LL_SPI_POLARITY_LOW;
	spi1.ClockPhase = LL_SPI_PHASE_1EDGE;
	spi1.NSS = LL_SPI_NSS_SOFT;
	spi1.BaudRate = LL_SPI_BAUDRATEPRESCALER_DIV4;
	spi1.BitOrder = LL_SPI_MSB_FIRST;
	spi1.CRCCalculation = LL_SPI_CRCCALCULATION_DISABLE;

	LL_SPI_Init(SPI1, &spi1);
	LL_SPI_Enable(SPI1);
	
	while(1)
	{
		spiTxRx(0x42, NULL, &data);
		LL_mDelay(1000);
		data = 0;
	}
	
}


void spiTxRx(uint8_t reg, uint8_t txData, uint8_t *rxData)
{
	gpioNssState(Reset);
	while(!LL_SPI_IsActiveFlag_TXE(SPI1));
	LL_SPI_TransmitData8(SPI1,reg);
	while(!LL_SPI_IsActiveFlag_RXNE(SPI1));
	*rxData = LL_SPI_ReceiveData8(SPI1);
	while(!LL_SPI_IsActiveFlag_TXE(SPI1));
	LL_SPI_TransmitData8(SPI1,txData);
	while(!LL_SPI_IsActiveFlag_RXNE(SPI1));
	*rxData = LL_SPI_ReceiveData8(SPI1);
	gpioNssState(Set);
}
