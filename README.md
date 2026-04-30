
<div align="center">
<a href="https://github.com/hadi14250">
    <img src="github_gifs/printf.gif" alt="printf gif" width="150" height="150">
  </a>
  <h3 align="center">ft_printf</h3>
  Rebuild, from scratch, the C stdio function printf
</div>

<br>

# About

`ft_printf` is a from-scratch reimplementation of the C standard library's `printf`. The goal of the project is to mirror the behavior of the original function for the most common conversions, while staying within the limits of the C standard (no external libraries, just `write` and `<stdarg.h>`). Variadic arguments are walked with `va_list`, the format string is parsed character by character, and each conversion is dispatched to a small dedicated handler.

<br>

# Specifiers Supported

- `%c` — prints a single character
- `%s` — prints a null-terminated string
- `%p` — prints a pointer address in hexadecimal, prefixed with `0x`
- `%d` / `%i` — prints a signed decimal integer
- `%u` — prints an unsigned decimal integer
- `%x` — prints an unsigned integer in lowercase hexadecimal
- `%X` — prints an unsigned integer in uppercase hexadecimal
- `%%` — prints a literal `%`

<br>

# Build

```sh
make
```

This produces `libftprintf.a`, a static archive you can link against your own programs.

Other targets:

- `make clean` — remove object files
- `make fclean` — remove object files and the archive
- `make re` — full rebuild

<br>

# Usage

Include the header and link against the archive:

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("hello, %s! you are user #%d\n", "world", 42);
    return (0);
}
```

Compile:

```sh
gcc main.c -L. -lftprintf -o demo
```

`ft_printf` returns the number of characters printed, matching the behavior of the standard `printf`.

<br>

# Files

- `ft_printf.c` — entry point, walks the format string
- `ft_parse.c` — dispatches each specifier to its handler
- `ft_putchar.c`, `ft_putstr.c` — character and string output
- `ft_putnbr.c`, `ft_putnbr_u.c` — signed and unsigned integers
- `ft_put_hex.c` — hexadecimal output (lowercase and uppercase)
- `ft_put_address.c` — pointer addresses
- `ft_printf.h` — public header
- `Makefile` — build rules

<br>
