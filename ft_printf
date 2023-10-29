#include <unistd.h>
#include <stdarg.h>

void print_char(char *str, int *count)
{
     if (!str)
         str = "(null)";
     while (*str)
         *count = write(1, str++, 1);
}

void print_hexa(long long int number, int base, int *count)
{
      char *hexa = "0123456789abcdef";

      if (number < 0)
      {
          number *= -1;
          *count += write(1, "-", 1);
      }
      if (number >= base)
          print_hexa((number / base), base, count);
      *count += write(1, &hexa[number %, base], 1);
}

int ft_printf(const char *str, ...)
{
     int count = 0;

     va_list args;
     va_star(args, str);
     while(*str)
     {
        if ((*str == '%') && ((*(str + 1) == 's' || (*(str + 1) == 'd') || (*(str + 1) == 'x')))
        {
           str++;
           if (*str + 1 == 's')
               print_char(va_arg(args, char *), &count);
           else if (*str + 1 == 'd')
              print_hexa((long long int)va_arg(args, int), 10, &count);
           else if (*str + 1 == 'x')
              print_hexa((long long int)va_arg(args, unsigned int), 16, &count);
        }
        else
            count += write(1, str, 1);
        str++;
     }
     return(va_end(args), count);
}
