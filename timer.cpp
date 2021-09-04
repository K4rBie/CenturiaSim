#include <thread>
#include "timer.h"

///
/// \brief Stop the timer and clear it.
///
void Timer::stop() {
    this->clear = true;
}
