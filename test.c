#include "include/ft_printf.h"
#include <stdio.h>

#ifdef TEST_FT_PRINTF

#define TEST(...) \
	result = ft_printf(__VA_ARGS__); \
	ft_printf("result: %d\n", result);

#else

#define TEST(...) \
	result = printf(__VA_ARGS__); \
	printf("result: %d\n", result);

#endif

int main() {
	int result = 0;

	// Basic tests
	TEST("abc");
	TEST("");
	TEST(NULL);
	TEST("%d", 10);
	TEST("%d", 0);

	// Character tests
	TEST("%c", 'a');
	TEST("%c", 126);

	// String tests
	TEST("%s", "\t");
	TEST("%s", "Hello!\n");
	TEST("%s", "");

	// Pointer tests
	TEST("%p", (void *)1024);
	TEST("%p", (void *)1025);
	TEST("%p", (void *)'a');
	TEST("%p", (void *)0);

	// Integer tests with %d and %i
	TEST("d: %d, i: %i", 0, 0);
	TEST("d: %d, i: %i", 10, 10);
	TEST("d: %d, i: %i", 2147483647, 2147483647);
	TEST("d: %d, i: %i", (int)-2147483648, (int)-2147483648);
	TEST("d: %d, i: %i", 0xa, 0xa);
	TEST("d: %d, i: %i", 033, 033);
	TEST("di: %di", 33);

	// Unsigned integer tests
	TEST("%u", -1);
	TEST("%u", (int)-2147483648);

	// Hexadecimal tests
	TEST("%x", 0);
	TEST("%x", 50);
	TEST("%x", -10);
	TEST("%x", 0xab);
	TEST("%x", 033);

	// Percent sign test
	TEST("%%");

	// Error cases
	// TEST();  Cannot compile
	// TEST('a');  Segmentation fault
	TEST("%");
	TEST("%d", 10, 10);
	TEST("%%%");
	TEST("%c", "a");
	TEST("%k%k");
}
