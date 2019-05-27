#ifndef HW_SPI_HANDLER__
#define HW_SPI_HANDLER__

void initSpi1Sx1276(void);
void spiTxRx(uint8_t reg, uint8_t txData, uint8_t *rxData);

#endif