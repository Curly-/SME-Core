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
    
    void init();
    
    void start();
    void stop();
    
    void addLoopUpdateHook(FuncPointer func);
    void addLoopRenderHook(FuncPointer func);
}}

#endif	/* CORE_H */

