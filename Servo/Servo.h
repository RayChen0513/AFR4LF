#pragma once

// ===== ESP32 =====
#if defined(ARDUINO_ARCH_ESP32)

  #include "esp32/src/ESP32Servo.h"

// ===== 非 ESP32（AVR / R4 / SAMD / etc.）=====
#else

  #include "arduino/src/Servo.h"

#endif
