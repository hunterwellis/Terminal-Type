#include <iostream>
#include <termios.h>
#include <unistd.h>

class KeyIO{
public:
    void setRawMode();
    void restoreTerminal();

    char getKeystroke();

    std::string type();

private:
    struct termios terminalSettings;

};
