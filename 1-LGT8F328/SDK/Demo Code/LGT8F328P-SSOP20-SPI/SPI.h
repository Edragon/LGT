#pragma once
#include <inttypes.h>

class SPI
{
  private:
    volatile static bool isLock;

  public:
    static void init();
    static uint8_t transmit(const uint8_t &data);
    static void slowMode();
    static void fastMode();
    static bool lock();
    static void release();
};
