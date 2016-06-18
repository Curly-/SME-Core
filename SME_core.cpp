#include "SME_core.h"
#include "SME_timer.h"
#include "SME_events.h"
#include "SME_config.h"
#include <iostream>
#include <vector>

SME::Timer second;
SME::Timer updateTick;

bool running = true;

unsigned long long ticks = 0;
unsigned long long frames = 0;
unsigned long fps;
unsigned long tps;
unsigned long long lastFrames = 0;
unsigned long long lastTicks = 0;

std::vector<SME::Core::FuncPointer> updateFuncs;
std::vector<SME::Core::FuncPointer> renderFuncs;
std::vector<SME::Core::FuncPointer> cleanupFuncs;
#define CALLFUNCPOINTERS(name) for(FuncPointer f : name) f()

void SME::Core::init() {
    SME::Events::init();
}

void SME::Core::start() {
    second.reset(); //reset timers to initialise them (otherwise undefined)
    second.start();
    updateTick.reset();
    updateTick.start();
    float time = 0;

    while (running) {
        time += updateTick.getTime();
        updateTick.reset();
        while (time >= 1000 / 60.f) {
            time -= 1000 / 60.f;

            CALLFUNCPOINTERS(updateFuncs);
            ticks++;
        }

        CALLFUNCPOINTERS(renderFuncs);
        //swap
        frames++;

        if (second.getTime() > 1000 && false) {
            fps = frames - lastFrames;
            lastFrames = frames;
            tps = ticks - lastTicks;
            lastTicks = ticks;
            second.reset();
//            std::cout << "TPS: " << tps << ", FPS: " << fps << std::endl;
        }
    }
    
    CALLFUNCPOINTERS(cleanupFuncs);
}

void SME::Core::stop() {
    running = false;
}

void SME::Core::addLoopUpdateHook(FuncPointer func) {
    updateFuncs.push_back(func);
}

void SME::Core::addLoopRenderHook(FuncPointer func) {
    renderFuncs.push_back(func);
}

void SME::Core::addCleanupHook(FuncPointer func) {
    cleanupFuncs.push_back(func);
}