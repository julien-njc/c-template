#include "utilities/memory.h"
#include <catch2/catch.hpp>
#include <limits>

TEST_CASE("utilities")
{
	SECTION("safe_malloc success")
	{
		const size_t oneKB = 1024;
		void*        allocated = safe_malloc(oneKB);
		CHECK(allocated != NULL);
		safe_free(&allocated);
		CHECK(allocated == NULL);
	}

	SECTION("safe_calloc success")
	{
		const size_t oneKB = oneKB;
		void*        allocated = safe_calloc(10, oneKB);
		CHECK(allocated != NULL);
		safe_free(&allocated);
		CHECK(allocated == NULL);
	}

	SECTION("safe_realloc success")
	{
		const size_t oneKB = 1024;
		const size_t maxSize = std::numeric_limits<size_t>().max();
		void*        allocated = safe_malloc(oneKB);
		CHECK(allocated != NULL);
		allocated = safe_realloc(allocated, 2 * oneKB);
		CHECK(allocated != NULL);
		void* notAllocated = safe_realloc(allocated, maxSize);
		CHECK(notAllocated == NULL);
		safe_free(&allocated);
		CHECK(allocated == NULL);
	}

	SECTION("safe_aligned_alloc")
	{
		const size_t allocationSize = 1024 * 1024; // allocate 1 MB
		const size_t fourBytesAlignment = 65536;   // 16 byte alignment
		const size_t fourBytesMask = 0xFFFF;       // addresses aligned mask
		// classic allocation
		void* smallAllocation = safe_malloc(1);
		void* allocated = safe_malloc(allocationSize);
		CHECK(allocated != NULL);
		size_t address = (size_t)allocated;
		CHECK((size_t)allocated == address);
		CHECK((address & fourBytesMask) != 0);
		// aligned allocation
		void* allocatedAligned = safe_aligned_alloc(fourBytesAlignment, allocationSize);
		CHECK(allocatedAligned != NULL);
		size_t addressAligned = (size_t)allocatedAligned;
		CHECK((addressAligned & fourBytesMask) == 0);
	}

	SECTION("save_malloc failure")
	{
		const size_t maxSize = std::numeric_limits<size_t>().max();
		void*        allocated = safe_malloc(maxSize);
		CHECK(allocated == NULL);
		safe_free(&allocated);
		CHECK(allocated == NULL);
	}
}
