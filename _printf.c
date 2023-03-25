#include "main.h"
#include <stdio.h>
#include <stdarg.h>
/**
 * _printf - ...
 * @format: ...
 * Return: ...
 */
int _printf(const char *format, ...)
{
        int i = 0;
        char c;
        va_list args;
        int l = 0;
        char *str;

        va_start(args, format);

        while ((c = *format))
        {
                if (c == '%')
                {
			format++;
                        c = *format;
                        switch (c)
                        {
                                case 'c':
                                        putchar(va_arg(args, int));
                                        i++;
                                        break;
                                case 's':
                                        str = va_arg(args, char*);
                                        printf("%s", str);
                                        for (l = 0; str[l] != '\0'; l++)
                                        {

                                        }
                                        i += l;
                                        break;
                                case '%':
                                        putchar('%');
                                        putchar('%');
                                        i += 2;
                                        break;
                                default:
                                        putchar('%');
                                        putchar(c);
                                        i += 2;
                                        break;
                        }
                }
                else
                {
                        putchar(c);
                        i++;
                }
                format++;
        }
        va_end(args);
        return (i);
}
