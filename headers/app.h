#ifndef APP_H
#define APP_H

#include <iostream>
#include "functions.h"
#include "matrix.h"
#include "history.h"

class App
{
    History history;
    bool running = true;

public:
    void run();
    void handleMenu();
    void actionCreateMatrix();
    void actionShowHistory();
    void actionTranspose();
    void actionTakeOutMinus();
    void actionMultiplay();
    void actionSumOrSubstraction();
};

#endif