#include <iostream>
#include "clsLoginScreen.h"
#include "clsMainScreen.h"

int main()

{

    while (true)
    {
        if (!clsLoginScreen::ShowLoginScreen())
        {
            break;
        }
            clsMainScreen::ShowMainMenue();
    }

    return 0;
}