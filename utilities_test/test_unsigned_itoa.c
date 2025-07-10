#include "../include/ft_printf.h"
#include <string.h>
#include <assert.h>

int main() {
	unsigned long long num;
	int	result;

	num = (unsigned long long)-1;
	result = strcmp(unsigned_itoa(num, 16), "ffffffffffffffff");
	assert(result == 0);

	num = (unsigned long long)0;
	result = strcmp(unsigned_itoa(num, 16), "0");
	assert(result == 0);

	num = (unsigned long long)15;
	result = strcmp(unsigned_itoa(num, 16), "f");
	assert(result == 0);

	num = (unsigned long long)1024;
	result = strcmp(unsigned_itoa(num, 16), "400");
	assert(result == 0);

	num = (unsigned long long)-10;
	result = strcmp(unsigned_itoa(num, 16), "fffffffffffffff6");
	assert(result == 0);
}
