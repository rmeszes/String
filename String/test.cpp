#include <iostream>

#include "string.h"

#include "memtrace.h"
#include "gtest_lite.h"

int main() {
	String s;
	s.getline(std::cin);
	std::cout << s;
}