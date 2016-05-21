/* 
 * File:   Core.h
 * Author: Sam
 *
 * Created on 21 May 2016, 19:22
 */

#ifndef CORE_H
#define	CORE_H

namespace SME { namespace Core {
    void start();
    
    bool running = true;
    long long ticks = 0;
    long long frames = 0;
    
    long fps;
    long tps;
}}

#endif	/* CORE_H */

