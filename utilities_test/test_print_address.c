#include "../include/ft_printf.h"
#include <stdio.h>
#include <assert.h>

int main() {
	int result = printf("%p", (void *)-1);
	printf("\n");
	printf("result: %d\n", result);

	int ft_result = print_address((void *)-1);
	printf("\n");
	printf("ft_result: %d\n", ft_result);
	printf("------------------------\n");

	result = printf("%p", NULL);
	printf("\n");
	printf("result: %d\n", result);

	ft_result = print_address(NULL);
	printf("\n");
	printf("ft_result: %d\n", ft_result);
	printf("------------------------\n");

	result = printf("%p", (void *)15);
	printf("\n");
	printf("result: %d\n", result);

	ft_result = print_address((void *)15);
	printf("\n");
	printf("ft_result: %d\n", ft_result);
	printf("------------------------\n");

	result = printf("%p", (void *)1024);
	printf("\n");
	printf("result: %d\n", result);

	ft_result = print_address((void *)1024);
	printf("\n");
	printf("ft_result: %d\n", ft_result);
	printf("------------------------\n");
}
