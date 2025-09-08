#ifndef WINDOWS_TERMIOS_H
#define WINDOWS_TERMIOS_H

#ifdef _WIN32
#include <windows.h>
#include <conio.h>
#include <io.h>
#include <stdlib.h>

#define STDIN_FILENO 0
#define STDOUT_FILENO 1

#define F_SETFL 4
#define F_GETFL 3
#define O_NONBLOCK 0x0004

struct termios {
    DWORD c_lflag;
};

#define ECHO 0004
#define ICANON 0002
#define TCSANOW 0

int tcgetattr(int fd, struct termios *t) {
    HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
    DWORD mode;
    if (!GetConsoleMode(hStdin, &mode))
        return -1;
    t->c_lflag = mode;
    return 0;
}

int tcsetattr(int fd, int opt, const struct termios *t) {
    HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
    if (!SetConsoleMode(hStdin, t->c_lflag))
        return -1;
    return 0;
}

int fcntl(int fd, int cmd, int arg) {
    if (fd == STDIN_FILENO) {
        HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
        DWORD mode;
        
        if (!GetConsoleMode(hStdin, &mode))
            return -1;
            
        if (cmd == F_GETFL) {
            return (mode & ENABLE_LINE_INPUT) ? 0 : O_NONBLOCK;
        }
        else if (cmd == F_SETFL) {
            if (arg & O_NONBLOCK) {
                mode &= ~ENABLE_LINE_INPUT;
            } else {
                mode |= ENABLE_LINE_INPUT;
            }
            return SetConsoleMode(hStdin, mode) ? 0 : -1;
        }
    }
    return -1;
}

// Замена random() для Windows
#define random() rand()
#define srandom(x) srand(x)

#else
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#endif

#endif