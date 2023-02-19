#ifndef FRAMEANDSEND_H
#define FRAMEANDSEND_H

#include "GenerateParameters.h"
#include <stdio.h>

enum enumRequestParam
{
  PARAM_VOLTAGE,
  PARAM_CURRENT,
};

void TransmitDataToConsole(void);

void ChangeTheGetParamType(void (*GetTypeFunction)());
float GetElement(const unsigned int ArrayElement,enumRequestParam Parameter);

#endif
