/* 
 * File:   Core.h
 * Author: Sam
 *
 * Created on 21 May 2016, 19:22
 */

#ifndef CORE_H
#define	CORE_H

namespace SME { namespace Core {
    typedef void (*FuncPointer)();
    
    /*
     * Initialises all Core components
     */
    void init();
    
    /*
     * Starts the game loop
     */
    void start();
    
    /*
     * Stops the game loop
     */
    void stop();
    
    void addLoopUpdateHook(FuncPointer func);
    void addLoopRenderHook(FuncPointer func);
    void addCleanupHook(FuncPointer func);
}}

#endif	/* CORE_H */

