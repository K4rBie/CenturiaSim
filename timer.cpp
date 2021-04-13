#include <thread>
#include "timer.h"

void Timer::stop() {
    this->clear = true;
}
