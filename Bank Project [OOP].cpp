#include "global.h"
#include "clsLoginScreen.h"

int main()
{
    while(!End)
    {
        if (!clsLoginScreen::ShowLoginScreen())
            break;
    }

    return 0;
}