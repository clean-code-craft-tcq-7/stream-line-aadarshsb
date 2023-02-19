#define CATCH_CONFIG_MAIN
#include "test/catch.hpp"

#include "GenerateParameters.h"
#include "FrameAndSend.h"

// include hpp file of battery charging parameter

TEST_CASE("Test case to verify voltage value reflects from file to the console properly \n")
{
  REQUIRE(GetElement(0,PARAM_VOLTAGE ) == 4.2f);
  REQUIRE(GetElement(6,PARAM_VOLTAGE ) == 3.4f);
  REQUIRE(GetElement(4,PARAM_VOLTAGE ) == 3.8f);
  REQUIRE(GetElement(2,PARAM_VOLTAGE ) == 3.7f);
}

TEST_CASE("Test case to verify current value reflects from file to the console properly \n")
{
  REQUIRE(GetElement(0,PARAM_CURRENT ) == 18.8f);
  REQUIRE(GetElement(6,PARAM_CURRENT ) == 16.700001f);
  REQUIRE(GetElement(4,PARAM_CURRENT ) == 11.7f);
  REQUIRE(GetElement(2,PARAM_CURRENT ) == 15.9f);
}
TEST_CASE("Switch the fn to Generate random number and check if voltage datasets lie in the range \n")
{
  //The set limit for voltage is between 29/10,0f = 2,9fV and max of 43/10,0f = 4,3fV
  ChangeTheGetParamType(GenerateRandParams);
  for(unsigned char Index = 0; Index < 50 ; ++Index)
  {
    REQUIRE((GetElement(Index,PARAM_VOLTAGE) >= 2.9f && GetElement(Index,PARAM_VOLTAGE) <= 4.3f) == 0x01);
  }
}
TEST_CASE("check if current datasets lie in the range \n")
{
  //The set limit for current is between 1/10,0f = 0,1f A and max of 100/10,0f = 10,0f A
  ChangeTheGetParamType(GenerateRandParams);
  for(unsigned char Index = 0; Index < 50 ; ++Index)
  {
    REQUIRE((GetElement(Index,PARAM_CURRENT) >= 0.1f && GetElement(Index,PARAM_VOLTAGE) <= 10.0f) == 0x01);
  }
}

TEST_CASE("Just print the value in the console \n")
{ 
  //Print the results in the console
  TransmitDataToConsole();
}
