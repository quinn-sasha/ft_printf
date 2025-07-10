#include "../include/ft_printf.h"
#include <assert.h>

int main() {
	assert(ft_putstr(NULL) == 6);
	assert(ft_putstr("") == 0);
	assert(ft_putstr("Hello") == 5);
	assert(ft_putstr("We are delighted to announce the signing of Kota Takai from J1 League side Kawasaki Frontale, subject to international clearance and work permit.The Japan international defender has agreed a deal with the Club that will run until 2030.") == 235);
}
