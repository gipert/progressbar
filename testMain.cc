/* progress bar tester
 * 
 * [###########---------------------------------------] 22%
 * 
 * Progress bar length: 50 units
 * Update percentage every unit
 */

#include <iostream>
#include <chrono>
#include <thread>

#include "progressbar.h"

using namespace std::this_thread;
using namespace std::chrono;

int main() {
    
    int N = 23456;
    
    ProgressBar bar(N);
    bar.Init();

    for ( int i = 0 ; i < N ; i++ ) {

        bar.Update(i);

	    sleep_for(milliseconds(3));
    }
	
    return 0;
}
