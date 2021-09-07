#ifndef TIMER_H
#define TIMER_H

#include <thread>

///
/// \brief Universal timer class. Makes the simulation tick.
///
class Timer {
    bool clear = false;

public:
    ///
    /// \brief set Timeout after which the chosen function will run
    /// \param function     Function to run
    /// \param delay        delay to function start
    ///
    template<typename Function>
    void setTimeout(Function function, int delay) {
        this->clear = false;
        std::thread t([=]() {
            if(this->clear) return;
            std::this_thread::sleep_for(std::chrono::milliseconds(delay));
            if(this->clear) return;
            function();
        });
        t.detach();
    }

    ///
    /// \brief set Interval at which the chosen function will run.
    /// \param function        Function to run
    /// \param interval        interval between function runs
    ///
    template<typename Function>
    void setInterval(Function function, int interval) {
        this->clear = false;
        std::thread t([=]() {
            while(true) {
                if(this->clear) return;
                std::this_thread::sleep_for(std::chrono::milliseconds(interval));
                if(this->clear) return;
                function();
            }
        });
        t.detach();
    }

    void stop();
};

#endif // TIMER_H
