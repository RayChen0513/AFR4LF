#pragma once

// ===== ESP32 =====
#if defined(ARDUINO_ARCH_ESP32)

  #include "esp32/ESP32Servo.h"
  using Servo = ESP32Servo;

// ===== 非 ESP32（AVR / R4 / SAMD / etc.）=====
#else

  #include "arduino/Servo.h"

#endif
