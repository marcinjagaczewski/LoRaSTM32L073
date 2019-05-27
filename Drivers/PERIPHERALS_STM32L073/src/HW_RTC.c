// #include "stm32l073xx.h"
#include "stm32l0xx.h"
#include "stm32l0xx_hal_rtc.h"
#include "HW_RTC.h"

RTC_HandleTypeDef hrtc;
RTC_TimeTypeDef sTime;

void rtcInit(void)
{
	RCC->CSR |= RCC_CSR_RTCEN;

	hrtc.Instance = RTC;
	hrtc.Init.HourFormat = RTC_HOURFORMAT_24;
	hrtc.Init.AsynchPrediv = 127;
	hrtc.Init.SynchPrediv = 255;
	HAL_RTC_Init(&hrtc);

	sTime.Hours=20;
	sTime.Minutes = 00;
	sTime.Seconds = 0;
	sTime.TimeFormat = RTC_HOURFORMAT12_AM;
	sTime.DayLightSaving = RTC_DAYLIGHTSAVING_NONE;
	sTime.StoreOperation = RTC_STOREOPERATION_RESET;
	HAL_RTC_SetTime(&hrtc, &sTime, RTC_FORMAT_BCD);
	
	NVIC_EnableIRQ(RTC_IRQn);
	NVIC_SetPriority(RTC_IRQn, 0);

}


// void rtcInit(void)
// {


// 	RCC->CSR |= RCC_CSR_RTCEN;

// 	RTC->WPR = 0xCA;
// 	RTC->WPR = 0x53;

// 	RTC->ISR |= RTC_ISR_INIT;
// 	while((RTC->ISR & RTC_ISR_INITF) == 0 )
// 	{
// 		//dodać timeout...
// 	}

// 	RTC->CR &= ~(RTC_CR_FMT | RTC_CR_OSEL | RTC_CR_POL);

// 	RTC->TR |= RTC_TR_PM; //PM Enable
// 													//Hour 20:00:00
// 	RTC->TR |= (2<<RTC_TR_HT_Pos);  //2
// 	RTC->TR |= (0<<RTC_TR_HU_Pos);  //0
// 																//:
// 	RTC->TR |= 0<<RTC_TR_MNT_Pos; //0
// 	RTC->TR |= 0<<RTC_TR_MNU_Pos; //0
// 																//:
// 	RTC->TR |= 0<<RTC_TR_ST_Pos;  //0
// 	RTC->TR |= 0<<RTC_TR_SU_Pos;  //0
// 													//Date 15.04.2019 
// 	RTC->DR |= 1<<RTC_DR_YT_Pos; //1
// 	RTC->DR |= 9<<RTC_DR_YU_Pos; //9

// 	RTC->DR |= 0<<RTC_DR_MT_Pos; //0
// 	RTC->DR |= 4<<RTC_DR_MU_Pos; //4

// 	RTC->DR |= 1<<RTC_DR_DT_Pos; //1
// 	RTC->DR |= 5<<RTC_DR_DU_Pos; //5

// 	RTC->DR |= RTC_DR_WDU_0; //Monday	

// 	//Alarm A
// 	// RTC->CR |= RTC_CR_ALRAE;
// 	// RTC->CR |= RTC_CR_ALRAIE;




// 	RTC->PRER |= 127 << RTC_PRER_PREDIV_A_Pos;
// 	RTC->PRER |= 255 << RTC_PRER_PREDIV_S_Pos;

// 	RTC->CR &= ~RTC_CR_BCK;

// 	RTC->ISR &= ~RTC_ISR_INIT;

// 	RTC->WPR = 0xFE;
// 	RTC->WPR = 0x64;


// 	// NVIC_EnableIRQ(RTC_IRQn);
// 	// NVIC_SetPriority(RTC_IRQn, 0);

// }



void rtcEnableAlarmA(rtcAlarmATime_t time)
{
	RTC->WPR = 0xCA;
	RTC->WPR = 0x53;
	RTC->CR &= ~RTC_CR_ALRAE; 


	RTC->ALRMAR &= ~RTC_ALRMAR_MSK4; //Alarm A set if the date/day match
	RTC->ALRMAR &= ~RTC_ALRMAR_WDSEL;

	RTC->ALRMAR |= (time.day/10)<<RTC_ALRMAR_DT_Pos;
	RTC->ALRMAR |= (time.day%10)<<RTC_ALRMAR_DU_Pos;

	RTC->ALRMAR &= ~RTC_ALRMAR_MSK3; //Alarm A set if the hours match
	RTC->ALRMAR &= ~RTC_ALRMAR_PM;

	RTC->ALRMAR |= (time.hour/10)<<RTC_ALRMAR_HT_Pos;
	RTC->ALRMAR |= (time.hour%10)<<RTC_ALRMAR_HU_Pos;

	RTC->ALRMAR &= ~RTC_ALRMAR_MSK2; //Alarm A set if the minutes match
	RTC->ALRMAR |= (time.minute/10)<<RTC_ALRMAR_MNT_Pos;
	RTC->ALRMAR |= (time.minute%10)<<RTC_ALRMAR_MNU_Pos;

	RTC->ALRMAR &= ~RTC_ALRMAR_MSK1;
	RTC->ALRMAR |= (time.secound/10)<<RTC_ALRMAR_ST_Pos;
	RTC->ALRMAR |= (time.secound%10)<<RTC_ALRMAR_SU_Pos;

	RTC->ALRMASSR &= ~RTC_ALRMASSR_MASKSS;

	RTC->CR = RTC_CR_ALRAIE | RTC_CR_ALRAE;
	RTC->WPR = 0xFE;
	RTC->WPR = 0x64;
}

void rtcDisableAlarmA(void)
{
	RTC->WPR = 0xCA;
	RTC->WPR = 0x53;
	RTC->CR &= ~RTC_CR_ALRAE; 
	RTC->CR &= ~RTC_CR_ALRAIE;
	RTC->WPR = 0xFE;
	RTC->WPR = 0x64;
}
