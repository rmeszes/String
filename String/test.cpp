#include <iostream>

#include "string.h"

#include "memtrace.h"
#include "gtest_lite.h"

int main() {
	TEST(ctor, string) {
		String c('c');
		String s("tor");
		EXPECT_STREQ("c", c.c_str());
		EXPECT_STREQ("tor", s.c_str());
		EXPECT_EQ(1, c.size());
		EXPECT_EQ(3, s.size());
	} END

	TEST(copy,string) {
		String s1("test");
		String s2 = s1;
		EXPECT_STREQ(s1.c_str(), s2.c_str());
	} END
}