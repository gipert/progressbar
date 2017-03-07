/* test program for the ProgressBar class
 * 
 * Author: Luigi Pertoldi
 * Created: 9 dic 2016
 *
 * Compile: c++ -I. -o test test.cc progressbar.cc
 * Usage: ./test
 *
 */

#include <thread>
#include <chrono>
#include "progressbar.h"

int main() {

    int N = 100000;

    ProgressBar bar(N);
    bar.Init();

    for ( int i = 0; i < N; i++ ) {

        bar.Update(i,'>');

        // the program...
        std::this_thread::sleep_for( std::chrono::microseconds(300) );
    }

    return 0;
}
