#include <stdio.h>
#include <stdarg.h>
#include "control.h"

int main() {
    controlDevice(LIGHT, ON);
    controlDevice(AIR_CONDITIONER, SET_TEMP, 18);\
    controlDevice(AIR_CONDITIONER, SET_MODE, 1);
    controlDevice(FINGERPRINT_LOCK, UNLOCK);
    controlDevice(MUSIC_PLAYER, ON);
    controlDevice(MUSIC_PLAYER, CHANGE_TRACK, 3617, "bla bla bla");
    return 0;
}