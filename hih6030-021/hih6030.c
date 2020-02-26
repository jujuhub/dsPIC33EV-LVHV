/*
  *
  * This script contains firmware for the Honeywell HumidIcon
  * relative humidity and temperature sensor HIH6030-021-001.
  *
  * It is based on the firmware from ControlEverythingCommunity
  * which can be found at
  * <github.com/ControlEverythingCommunity/HIH6020>
  *
  * modified by: Julie He
  *
*/

#include <stdio.h>
#include <stdlib.h>
//#include <unistd.h>
//#include <linux/i2c-dev.h>
//#include <sys/ioctl.h>
//#include <fcntl.h>

int HIH6030_GetRHT(float *hum, float *temp)
{
  // Create I2C bus
  int file;
  char *bus = "/dev/i2c-1";
/*  if ((file = open(bus, O_RDWR)) < 0)
  {
    printf("Failed to open the bus. \n");
    exit(1);
  }
  // Get I2C device. HIH6030 I2C address is 0x27
//  ioctl(file, I2C_SLAVE, 0x27);
  sleep(1);

  // Read 4 bytes of data(0x00)
  // humidity msb, humidity lsb, temp msb, temp lsb
  char reg[1] = {0x00};
  write(file, reg, 1);
  char data[4] = {0}
  if (read(file, data, 4) != 4)
  {
    printf("Error: Input/Output error! \n");
  }
  else 
  {
    // Convert data to 14-bits
    humidity = ((data[0] & 0x3F)*256 + data[1]) / 16382. * 100.;
    int temp = ((data[2]*256 + (data[3] & 0xFC)) / 4);
    cTemp = (temp / 16384.)*165. - 40.;
    float fTemp = cTemp*1.8 + 32;

    // Output data to screen
    printf("Relative humidity: %.2f RH \n", humidity);
    printf("Temperature in Celsius: %.2f C \n", cTemp);
    printf("Temperature in Fahrenheit: %.2f F \n", fTemp);
  } */
}

int HIH6030_GetRHTStatus()
{
  // Get relative humidity and temperature
/*  float rhmd, ctmp;
  HIH6030_GetRHT(&rhmd, &ctmp);

  // Compare with critical relative humidity and temp
  if (rhmd >= 0.5)
  {
    printf(" WARNING !! Relative humidity is above 50% ! \nTurning off LVHV board... \n");
    return 0;
  } else { return 1; }

  if (ctmp >= 50.)
  {
    printf(" WARNING !! Temperature is above 50 deg C ! \n Turning off LVHV board... \n");
    return 0;
  } else { return 1; }
*/
  return 1; // dbg
}
