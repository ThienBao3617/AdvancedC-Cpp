#ifndef CONTROL_H
#define CONTROL_H

#include <stdio.h>
#include <stdarg.h>

typedef enum
{
    LIGHT, AIR_CONDITIONER, FINGERPRINT_LOCK, MUSIC_PLAYER
} DeviceType;

typedef enum
{
    ON, OFF,
    SET_TEMP, SET_MODE,
    UNLOCK, LOCK, 
    INCREASE_VOL, DECREASE_VOL, 
    CHANGE_TRACK
} CommandType;

void controlDevice(DeviceType device, ...)
{
    va_list args;
    va_start(args, device);

    switch(device)
    {
        case LIGHT:
        {
            CommandType command_1 = va_arg(args, CommandType);
            switch(command_1)
            {
                case ON:
                    printf("Light is turned ON\r\n");
                    break;
                case OFF:
                    printf("Light is turned OFF\r\n");
                    break;
                default:
                    printf("Invalid command for LIGHT device\r\n");
                    break;
            }
            break;
        }

        case AIR_CONDITIONER:
        {
            CommandType command_2 = va_arg(args, CommandType);
            switch(command_2)
            {
                case ON:
                    printf("Air conditioner is turned ON\r\n");
                    break;
                case OFF:
                    printf("Air xconditioner is turned OFF\r\n");
                    break;
                case SET_TEMP:
                {
                    int temp = va_arg(args, int);
                    printf("Air conditioner is set to %d degrees\r\n", temp);
                    break;
                }
                case SET_MODE:
                {
                    int mode = va_arg(args, int);
                    if(mode == 1) printf("Air conditioner is set to COOLING mode\r\n");
                    else if(mode == 2) printf("Air conditioner is set to FAN mode\r\n");
                    else printf("Invalid mode for air conditioner\r\n");
                    break;
                }
                default:
                    printf("Invalid command for AIR CONDITIONER device\r\n");
                    break;
            }
            break;
        }

        case FINGERPRINT_LOCK:
        {
            CommandType command_3 = va_arg(args, CommandType);
            switch(command_3)
            {
                case UNLOCK:
                    printf("Finger print lock is UNLOCKED\r\n");
                    break;
                case LOCK:
                    printf("Finger print is LOCKED\r\n");
                    break;
                default:
                    printf("Invalid command for FINGER PRINT LOCK device\r\n");
                    break;
            }
            break;
        }

        case MUSIC_PLAYER:
        {
            CommandType command_4 = va_arg(args, CommandType);
            switch(command_4)
            {
                case ON:
                    printf("Music player is turned ON\r\n");
                    break;
                case OFF:
                    printf("Music player is turned OFF\r\n");
                    break;
                case INCREASE_VOL:
                    printf("Volume is INCREASED\r\n");
                    break;
                case DECREASE_VOL:
                    printf("Volume is DECREASED\r\n");
                    break;
                case CHANGE_TRACK:
                {
                    int trackNums = va_arg(args, int);
                    char* songName = va_arg(args, char*);
                    printf("Changed to track %d which is your favorite song name %s\r\n", trackNums, songName);
                    break;
                }
                default:
                    printf("Invalid command for MUSIC PLAYER\r\n");
                    break;
            }
            break;
        }

        default:
            printf("Invalid DEVICE\r\n");
            break;
    }
    va_end(args);
}
#endif