#include "../include/ft_printf.h"
#include <stdio.h>
#include <assert.h>

int main() {
	int result = print_hexadecimal(0, TRUE);
	assert(result == printf("%X", 0));
	printf("\n");

	result = print_hexadecimal(15, TRUE);
	assert(result == printf("%X", 15));
	printf("\n");

	result = print_hexadecimal(160, TRUE);
	assert(result == printf("%X", 160));
	printf("\n");

	result = print_hexadecimal(-1, TRUE);
	assert(result == printf("%X", -1));
	printf("\n");

	result = print_hexadecimal(4294967295, TRUE);
	assert(result == printf("%X", 4294967295));
	printf("\n");

	result = print_hexadecimal(-4294967295, TRUE);
	assert(result == printf("%X", -4294967295));
	printf("\n");
}
