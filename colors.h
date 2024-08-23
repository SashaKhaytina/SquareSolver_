#ifndef COLORS_H
#define COLORS_H

#define RED(string, ...) printf("\x1b[31m" string "\x1b[0m", ##__VA_ARGS__)
#define GREEN(string, ...) printf("\x1b[32m" string "\x1b[0m", ##__VA_ARGS__) 
#define YELLOW(string, ...) printf("\x1b[33m" string "\x1b[0m", ##__VA_ARGS__)
#define BLUE(string, ...) printf("\x1b[34m" string "\x1b[0m", ##__VA_ARGS__)
#define MAGENTA(string, ...) printf("\x1b[35m" string "\x1b[0m", ##__VA_ARGS__)
#define CYAN(string, ...) printf("\x1b[36m" string "\x1b[0m", ##__VA_ARGS__)

#endif