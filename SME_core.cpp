#include "SME_core.h"
#include "SME_timer.h"
#include <iostream>

unsigned long long lastFrames = 0;
unsigned long long lastTicks = 0;
SME::Timer second;
SME::Timer updateTick;

void SME::Core::start() {
    second.start();
    updateTick.start();
    float time = 0;
    
    while (running) {
        time += updateTick.getTime();
        updateTick.reset();
        while (time >= 1000 / 60.f) {
            time -= 1000 / 60.f;

            //update
            ticks++;
        }
    }

    //render
    //swap
    frames++;

    if (second.getTime() > 1000) {
        fps = frames - lastFrames;
        lastFrames = frames;
        tps = ticks - lastTicks;
        lastTicks = ticks;
        second.reset();
        std::cout << "TPS: " << tps << ", FPS: " << fps << std::endl;
    }
}
