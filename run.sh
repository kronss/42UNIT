make
gcc -Wall -Wextra -Werror -o test main.c libftprintf.a
./test | cat -e
