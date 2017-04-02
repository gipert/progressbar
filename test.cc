/* test program for the ProgressBar class
 * 
 * Author: Luigi Pertoldi
 * Created: 9 dic 2016
 *
 * Compile: c++ -I. -o test test.cc progressbar.cc
 * Usage: ./test
 *
 */

#include <iostream>
#include <thread>
#include <chrono>

#include "ProgressBar.h"

int main() {

    int N = 10000;

    ProgressBar bar(N);

    for ( int i = 0; i < N; i++ ) {

        bar.Update(i);

        // the program...
        std::this_thread::sleep_for( std::chrono::microseconds(300) );
    }
    
    std::cout << std::endl;

    N = 5000;
    bar.SetNIter(N);
    bar.SetStyle('>');
    bar.Reset();
    for ( int i = 0; i < N; i++ ) {

        bar.Update(i);

        // the program...
        std::this_thread::sleep_for( std::chrono::microseconds(300) );
    }
    
    std::cout << std::endl;
    bar.Reset();
    bar.ShowBar(false);
    for ( int i = 0; i < N; i++ ) {

        bar.Update(i);

        // the program...
        std::this_thread::sleep_for( std::chrono::microseconds(300) );
    }

    return 0;
}
