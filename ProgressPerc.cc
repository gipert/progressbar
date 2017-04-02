/* Running percentage for c++ loops with internal running variable
 *
 * Author: Luigi Pertoldi
 * Created: 2 apr 2017
 *
 * Notes: The class must be used when there's no other possible source of output
 *        inside the for loop
 *
 *
 */

#include "ProgressPerc.h"

#include <iostream>

ProgressPerc::ProgressPerc() : 
    savedPerc(0),
    updateIsCalled(false), 
    setNIterIsCalled(true) {}

ProgressPerc::ProgressPerc(int n) : 
    nCycles(n), 
    savedPerc(0), 
    updateIsCalled(false),
    setNIterIsCalled(true) {}

void ProgressPerc::Reset() {
    updateIsCalled = false;
    savedPerc = 0;
    return;
}

void ProgressPerc::SetNIter(int iter) { 
    nCycles = iter;
    setNIterIsCalled = true;
    return;
}

void ProgressPerc::Update( int i ) {
    
    if (!setNIterIsCalled) { std::cerr << "ProgressPerc: number of cycles not set!\n"; return; }
    
    if (!updateIsCalled) {
	    std::cout << "0%" << std::flush;
    }
    updateIsCalled = true;

	int perc = 0;

	// compute percentage
	perc = i*100. / (nCycles-1);

	// update percentage each unit
	if (perc == savedPerc + 1) {
		// erase the correct  number of characters
		if (perc  < 10)               std::cout << "\b\b"   << perc << "%";
		if (perc == 10)               std::cout << "\b\b"   << perc << "%";
		if (perc  > 10 && perc < 100) std::cout << "\b\b\b" << perc << "%";
		if (perc == 100)              std::cout << "\b\b\b" << perc << "%";
	}

	savedPerc = perc;
	std::cout << std::flush;

    return;
}

