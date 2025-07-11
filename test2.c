#include "include/ft_printf.h"
#include <stdio.h>

/*
Test cases that needs to be compiled all at once
*/
int main() {
	int result = 0;

	result = printf("%p", (void *)"Hello!");
	printf("\n");
	printf("result: %d\n", result);

	result = printf("%p", (void *)"");
	printf("\n");
	printf("result: %d\n", result);

	result = printf("%d", "abc");
	printf("\n");
	printf("result: %d\n", result);

	result = printf("%d");
	printf("\n");
	printf("result: %d\n", result);

	// --------------------------------
	printf("\nFrom here, test for ft_printf\n");

	result = ft_printf("%p", (void *)"Hello!");
	ft_printf("\n");
	ft_printf("result: %d\n", result);

	result = ft_printf("%p", (void *)"");
	ft_printf("\n");
	ft_printf("result: %d\n", result);

	result = ft_printf("%d", "abc");
	ft_printf("\n");
	ft_printf("result: %d\n", result);

	result = ft_printf("%d");
	ft_printf("\n");
	ft_printf("result: %d\n", result);
}
