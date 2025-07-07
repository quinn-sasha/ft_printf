#include "ft_printf.h"
#include <stdio.h>

#ifdef TEST_FT_PRINTF

#define TEST(...) \
	result = ft_printf(__VA_ARGS__); \
	printf("result: %d\n", result);

#else // TEST_FT_PRINTF

#define TEST(...) \
	result = printf(__VA_ARGS__); \
	printf("result: %d\n", result);

#endif // TEST_PRINTF

int main() {

}
