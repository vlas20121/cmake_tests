#include "string_utils.h"
#include <cstring>

bool isStartedWith(const char* start, const char* end, const char* pattern)
{
  if(std::strlen(pattern) > (end - start))
      return false;
  const char* data = start;
  while(*pattern != '\0' && data != end)
  {
    if(*data++ != *pattern++)
      return false;
  }
  return true;
}

bool isStartedWith_bad(const char* start, const char* end, const char* pattern)
{
  const char* data = start;
  while(pattern != '\0' || data != end)
  {
    if(data++ != pattern++)
      return false;
  };
  return true;
}

