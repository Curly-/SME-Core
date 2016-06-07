#ifndef TIMER_H
#define	TIMER_H

namespace SME {
    class Timer {
    public:
        /*
         * Start timer
         */
        void start();
        /*
         * Freezes timer
         */
        void stop();
        /*
         * Resets the timer to 0
         */
        void reset();
        /*
         * Returns the time since the timer was started in milliseconds
         */
        unsigned long getTime();
    private:
        bool running;
        unsigned long startms;
        unsigned long ms;
    };
}

#endif	/* TIMER_H */

