#ifndef REGISTER_H
#define REGISTER_H
int getsum(int x,int y);
#define PORTC   *((volatile unsigned char*)0x35)
#define DDRC    *((volatile unsigned char*)0x34)

#endif