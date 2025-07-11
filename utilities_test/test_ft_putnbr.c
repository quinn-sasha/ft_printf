#include "../include/ft_printf.h"
#include <stdio.h>
#include <assert.h>

int main() {
	int result = ft_putnbr(-2147483648);
	assert(result == printf("%d", -2147483648));
	printf("\n");

	result = ft_putnbr(0);
	assert(result == printf("%d", 0));
	printf("\n");

	result = ft_putnbr(2147483647);
	assert(result == printf("%d", 2147483647));
	printf("\n");

	result = ft_putnbr(214748364700);
	assert(result == printf("%d", 214748364700));
	printf("\n");

	result = ft_putnbr(1024);
	assert(result == printf("%d", 1024));
	printf("\n");

	result = ft_putnbr(-1024);
	assert(result == printf("%d", -1024));
	printf("\n");
}
