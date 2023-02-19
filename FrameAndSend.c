#include "FrameAndSend.h"

/*static fn prototypes*/
static float GetVoltageParam(const unsigned int,const tyBatteryParams_t*);
static float GetCurrentParam(const unsigned int,const tyBatteryParams_t*);
/*scope limited global variable (static var)*/
static void (*GetParameters)(void) = GetSensorParamsFromFile;

/*consts*/
static const unsigned int TOTAL_REQ_TYPES = 2U;
static float (*ParamToFnMap[TOTAL_REQ_TYPES])(unsigned int,const tyBatteryParams_t*) =
{
  GetVoltageParam,
  GetCurrentParam
};

void ChangeTheGetParamType(void (*GetTypeFunction)())
{
  GetParameters = GetTypeFunction;
}
void TransmitDataToConsole(void)
{
  (*GetParameters)();
  const tyBatteryParams_t* SensorParams = GetSensorArrayParameters();
  for(unsigned int DataSet = 0; DataSet < 50; ++DataSet)
  {
    /*The data will be output in console as following example
    
      3.7 -This represents voltage of the battery
      -3.2 - This represnts current (- means discharge, + means charge)
      
      3.9
      +0.1
      
      4.1
      +0.1
      
      This way, it will be easy for the receiver to read the data by simply reading lines
      and next line carriage for the next dataset
    */
    printf("%f\n%f\n\n",SensorParams[DataSet].BattVoltage,SensorParams[DataSet].BattCurrent); 
  }
}

float GetElement(unsigned int ArrayElement,enumRequestParam Parameter)
{
  (*GetParameters)();
  const tyBatteryParams_t* SensorParams = GetSensorArrayParameters();
  if(ArrayElement >= 50)
  {
    return 0xffffffff; //NaN expression 
  }
  else 
  {
    return (*ParamToFnMap[Parameter])(ArrayElement,SensorParams);
  }
}

static float GetVoltageParam(unsigned int ArrayElement,const tyBatteryParams_t* SensorParam)
{
  return SensorParam[ArrayElement].BattVoltage;
}

static float GetCurrentParam(unsigned int ArrayElement,const tyBatteryParams_t* SensorParam)
{
  return SensorParam[ArrayElement].BattCurrent;
}
