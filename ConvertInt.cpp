#include <string>
#include "ConvertInt.h"
std::string ConvertInt(int number)//Provisional pa siempre
{
  if (number == 0)
    return "0";
  std::string temp="";
  std::string returnvalue="";
  while (number>0)
    {
      temp+=number%10+48;
      number/=10;
    }
  for (int i=0;i<temp.length();i++)
    returnvalue+=temp[temp.length()-i-1];

  return returnvalue;
}
