#ifndef GENERATEPARAMETERS_H
#define GENERATEPARAMETERS_H

typedef struct
{
  float BattVoltage;
  float BattCurrent;
}tyBatteryParams_t;

void GenerateRandParams(void);
void GetSensorParamsFromFile(void);
const tyBatteryParams_t* GetSensorArrayParameters(void);

#endif
