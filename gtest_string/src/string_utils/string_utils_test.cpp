#ifdef TESTS
#include <gtest/gtest.h>
#include <string_utils/string_utils.h>
#include <string>

TEST(isStartedWith, isStartedWith)
{
	std::string s="abcdefg";
	ASSERT_TRUE( isStartedWith(s.data(), s.data() + s.size(), "abcd"));
	ASSERT_TRUE(!isStartedWith(s.data(), s.data() + s.size(), "abce"));
    ASSERT_TRUE(!isStartedWith(s.data(), s.data() + s.size(), "abcdefg12345"));
}

TEST(isStartedWith, isStartedWith_bad)
{
	std::string s="abcdefg";
	ASSERT_TRUE( isStartedWith_bad(s.data(), s.data()+s.size(), "abcd"));
	ASSERT_TRUE(!isStartedWith_bad(s.data(), s.data()+s.size(), "abce"));
    ASSERT_TRUE(!isStartedWith(s.data(), s.data() + s.size(), "abcdefg12345"));
}
#endif
