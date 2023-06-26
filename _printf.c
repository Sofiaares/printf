#include "main.h"

/**
 * _printf - Printf function
 * @format: format
 * Return: Printed bytes
 */

int _printf(const char *format, ...)
{
	int sum = 0
	va_list list;
	char *p, *start;
	params_t params = PARAMS_INIT;

	if (format == NULL)
		return (-1);

	va_start(list, format);

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (p = (char *)format; *p; p++)
	{
		init_params(&params, list);
		if (*p != '%')
		{
			sum += _putchar(*p);
			continue;
		}
		start = p;
		p++;
		while (get_flag(p, &params)) /* while char at p is flag char */
		{
			p++; /* next char */
		}
		p = get_width(p, &params, list);
		p = get_precision(p, &params, list);
		if (get_modifier(p, &params))
			p++;
		if (!get_specifier(p))
			sum += print_from_to(start, p,
params.l_modifier || params.h_modifier
? p - 1 : 0);
		else
			sum += get_print_func(p, list,
&params);
	}
	_putchar(BUF_FLUSH);	
	va_end(list);
	return (sum);
}
