#include <gtest/gtest.h>
#include <type_traits>

#include "allocator.h"

TEST(AllocatorTestSet, InnerTypesIsConvertible) {
	bool p2constP = std::is_convertible_v<Allocator<int>::pointer, Allocator<int>::const_pointer>;
	bool p2voidP = std::is_convertible_v<Allocator<int>::pointer, Allocator<int>::void_pointer>;
	bool p2constVoidP = std::is_convertible_v<Allocator<int>::pointer, Allocator<int>::const_void_pointer>;
	bool constP2constVoidP = std::is_convertible_v<Allocator<int>::const_pointer, Allocator<int>::const_void_pointer>;
	bool voidP2constVoidP = std::is_convertible_v<Allocator<int>::void_pointer, Allocator<int>::const_void_pointer>;

	ASSERT_TRUE(
		   p2constP
		&& p2voidP
		&& p2constVoidP
		&& constP2constVoidP
		&& voidP2constVoidP
	);
}

TEST(AllocatorTestSet, allocateTest) {
	Allocator<int, 2> allocator;

	int * pint = allocator.allocate(1);

	EXPECT_NE(pint, nullptr);
	EXPECT_THROW(allocator.allocate(1000), std::bad_alloc);

	allocator.deallocate(pint);
}