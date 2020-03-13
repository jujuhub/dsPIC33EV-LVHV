/*
  * HIH6030 Header File
  *
  * written by: Julie He
*/

#ifndef HIH6030_H
#define HIH6030_H
#endif

#define NORMAL 0
#define STALE_DATA 1
#define COMMAND_MODE 2
#define DIAGNOSTIC 3

#define RHT_OK 1
#define RHT_NOTOK 0

int HIH6030_GetRHT(float *hum, float *temp);

int HIH6030_GetSensorStatus(void);
