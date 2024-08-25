/*!
 * \file
 * \brief Цветной вывод.
 */

// FIXME: const char* ANSI_RED = 

#ifndef COLORS_H
#define COLORS_H

#define PRINTF_RED(string, ...)     printf("\x1b[31m" string "\x1b[0m", ##__VA_ARGS__)    /*!< Печать текста красным цветом. */
#define PRINTF_GREEN(string, ...)   printf("\x1b[32m" string "\x1b[0m", ##__VA_ARGS__)    /*!< Печать текста зеленым цветом. */
#define PRINTF_YELLOW(string, ...)  printf("\x1b[33m" string "\x1b[0m", ##__VA_ARGS__)    /*!< Печать текста желтым цветом. */
#define PRINTF_BLUE(string, ...)    printf("\x1b[34m" string "\x1b[0m", ##__VA_ARGS__)    /*!< Печать текста синим цветом. */
#define PRINTF_MAGENTA(string, ...) printf("\x1b[35m" string "\x1b[0m", ##__VA_ARGS__)    /*!< Печать текста цветом маджента. */
#define PRINTF_CYAN(string, ...)    printf("\x1b[36m" string "\x1b[0m", ##__VA_ARGS__)    /*!< Печать текста цветом циан. */

#endif