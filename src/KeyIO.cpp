#include "KeyIO.hpp"
#include <cwchar>
#include <filesystem>

void KeyIO::setRawMode(){

    struct termios newTermios;
    tcgetattr(STDIN_FILENO, &terminalSettings);
    newTermios = terminalSettings;
    newTermios.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newTermios);
}

void KeyIO::restoreTerminal(){

    tcsetattr(STDIN_FILENO, TCSANOW, &terminalSettings);
}

char KeyIO::getKeystroke(){
    return getchar();
}

std::string KeyIO::type(){
    char key = getKeystroke();

    switch (key) {
        case 127: // backspace
            return "\b \b";
            break;
        default:
            std::string str(1, key);
            return str;
            break;
    }
}
