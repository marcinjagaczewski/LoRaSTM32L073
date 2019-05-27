#ifndef HW_GPIO_HANDLER__
#define HW_GPIO_HANDLER__

#define RADIO_NRESET_PORT                         GPIOA
#define RADIO_NRESET_PIN                          LL_GPIO_PIN_0

#define RADIO_MOSI_PORT                           GPIOA
#define RADIO_MOSI_PIN                            LL_GPIO_PIN_7

#define RADIO_MISO_PORT                           GPIOA
#define RADIO_MISO_PIN                            LL_GPIO_PIN_6

#define RADIO_SCK_PORT                            GPIOA
#define RADIO_SCK_PIN                             LL_GPIO_PIN_5

#define RADIO_NSS_PORT                            GPIOB
#define RADIO_NSS_PIN                             LL_GPIO_PIN_6

#define RADIO_DIO_0_PORT                          GPIOA
#define RADIO_DIO_0_PIN                           LL_GPIO_PIN_10

#define RADIO_DIO_1_PORT                          GPIOB
#define RADIO_DIO_1_PIN                           LL_GPIO_PIN_3

#define RADIO_DIO_2_PORT                          GPIOB
#define RADIO_DIO_2_PIN                           LL_GPIO_PIN_5

#define RADIO_DIO_3_PORT                          GPIOB
#define RADIO_DIO_3_PIN                           LL_GPIO_PIN_4

#define RADIO_DIO_4A_PORT                         GPIOA
#define RADIO_DIO_4A_PIN                          LL_GPIO_PIN_9

#define RADIO_DIO_4B_PORT                         GPIOB
#define RADIO_DIO_4B_PIN                          LL_GPIO_PIN_0

#define RADIO_DIO_5_PORT                          GPIOC
#define RADIO_DIO_5_PIN                           LL_GPIO_PIN_7

#define RADIO_RXTX_PORT                           GPIOC
#define RADIO_RXTX_PIN                            LL_GPIO_PIN_1


typedef enum gpioState_e
{
	Reset = 0,
	Set,
}gpioState_t;


// void initLedGpio(void);
void initGpioSx1276(void);
void gpioNssState(gpioState_t state);
void gpioSX1276ResetSet(gpioState_t state);

#endif
