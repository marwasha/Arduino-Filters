/**
 * Example of Butterworth filter.
 * 
 * @boards  AVR, AVR USB, Teensy 3.x, ESP32
 * 
 * @see <https://tttapa.github.io/Pages/Mathematics/Systems-and-Control-Theory/Analog-Filters/Butterworth-Filters.html>
 * 
 * Written by PieterP, 2019-11-12
 * https://github.com/tttapa/Arduino-Helpers
 */

#include <Filters.h>

#include <AH/Timing/MillisMicrosTimer.hpp>
#include <Filters/Butterworth.hpp>

void setup() {
  Serial.begin(115200);
}

// Sampling frequency
const double f_s = 100; // Hz
// Cut-off frequency (-3 dB)
const double f_c = 40; // Hz
// Normalized cut-off frequency
const double f_n = f_c / f_s;

// Sample timer
Timer<micros> timer = std::round(1e6 / f_s);
// Sixth-order Butterworth filter
auto filter = butter<6>(f_n);

void loop() {
  if (timer)
    Serial.println(filter(analogRead(A0)));
}