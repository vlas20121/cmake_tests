#include "string_utils.h"
#include <cstring>

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


bool isStartedWith2(const char* start, const char* end, const char* pattern)
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

template<class ITERATOR>
bool isStartedWith(ITERATOR str, ITERATOR str_end, ITERATOR pattern, ITERATOR pattern_end)
{
  for(;str != str_end && pattern != pattern_end;)
    if(*str++ != *pattern++)
      return false;
  return pattern == pattern_end;
}

bool isStartedWith(const char* start, const char* end, const char* pattern)
{
	return isStartedWith(start, end, pattern, pattern+std::strlen(pattern));
}

/*
#include <gtest/gtest.h>
TEST(Dll,Test)
{
	ASSERT_TRUE(0);
}
*/