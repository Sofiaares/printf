#include "main.h"
/****** CONVERT A FUNCTION ******/
/**
 * convert - convert a function, clone of itoa
 * @num: number
 * @base: base
 * @flags: argument flags
 * @params: parameter struct
 * return: string
 */
char *convert(long int num, int base, int flags, params_t *params)
{
	static char *array;
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long n = num;
	(void)params;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		n = -num;
		sign = '-';
	}
	array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" :"0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do {
		*--ptr = array[n % base];
		n /= base;
	} while (n != 0);

	if (sign)
		*--ptr = sign;
	return (ptr);
}
/****** PRINT UNSIGNED NUMBER ******/
/**
 * print_unsigned - print unsigned integer numbers
 * @ap: argument pointer
 * @params: parameter struct
 * return: bytes printed
 */
int print_unsigned(va_list ap, params_t *params)
{
        unsigned long 1;

        if (params->l_modifier)
                l = (unsigned long)va_arg(ap, unsigned long);
        else if (params->h_modifier)
                l = (unsigned short int)va_arg(ap, unsigned int);
        else
                l = (unsigned int)va_arg(ap, unsigned int);
        params->unsign = 1;
        return (print_number(convert(1, 10, CONVERT_UNSIGNED, params), params));
}
/****** PRINT ADRESS ******/
/** 
 * print_adress - print adress
 * @ap: argument pointer
 * @params: parameter struct
 * return: bytes printed
 */
int print_adress(va_list ap, params_t *params)
{
        unsigned long int n = va_arg(ap, unsigned long int);
        char *str;

	if (!n)
	return (_puts("(nil)"));
	
	str = convert(1, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, params);
	*--str = 'x';
	*--str = '0';
	return (print_number(str, params));
}
