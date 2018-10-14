#include <wiringPiI2C.h>

void main (){
    int fd = wiringPiI2CSetup(0x04);
    wiringPiI2CWrite(fd, 240);
    wiringPiI2CWrite(fd, 10);
}
