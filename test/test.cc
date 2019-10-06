/* test program for the progressbar class
 * 
 * Author: Luigi Pertoldi
 * Created: 9 dic 2016
 *
 * Compile: c++ -I. -o test test.cc
 * Usage: ./test
 *
 */

#include <iostream>
#include <thread>
#include <chrono>

#include "progressbar.hpp"

int main() {

    int N = 10000;

    progressbar bar(N);

    for ( int i = 0; i < N; i++ ) {

        bar.update();

        // the program...
        std::this_thread::sleep_for( std::chrono::microseconds(300) );
    }

    std::cout << std::endl;

    N = 5000;
    bar.set_niter(N);
    bar.reset();
    bar.set_todo_char(" ");
    bar.set_done_char("█");
    bar.set_opening_bracket_char("{");
    bar.set_closing_bracket_char("}");
    for ( int i = 0; i < N; i++ ) {

        bar.update();

        // the program...
        std::this_thread::sleep_for( std::chrono::microseconds(300) );
    }

    std::cout << std::endl;
    bar.reset();
    bar.show_bar(false);
    for ( int i = 0; i < N; i++ ) {

        bar.update();

        // the program...
        std::this_thread::sleep_for( std::chrono::microseconds(300) );
    }

    return 0;
}
