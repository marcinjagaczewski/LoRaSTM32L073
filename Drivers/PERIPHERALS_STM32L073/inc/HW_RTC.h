#ifndef HW_RTC_HANDLER__
#define HW_RTC_HANDLER__


typedef struct rtcAlarmATime_s
{
	uint8_t day;
	uint8_t hour;
	uint8_t minute;
	uint8_t secound;

}rtcAlarmATime_t;

void rtcInit(void);

#endif