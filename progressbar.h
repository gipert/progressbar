/* Progress Bar for c++ loops with internal running variable
 *
 * Author: Luigi Pertoldi
 * Created: 3 dic 2016
 *
 * Notes: The bar must be used when there's no other possible source of output
 *        inside the for loop
 *
 *
 */

#ifndef PROGRESS_BAR
#define PROGRESS_BAR

class ProgressBar {

    public:
    ProgressBar( int n ) { nCycles = n; savedPerc = 0; }
    ~ProgressBar();

    void Init();                             // initialize the bar. It must be put before the for loop
                                             // and after every text sent to the standard output
    void Update( int i , char opt = '#' );   // update the bar with respect to the progress of the for
                                             // cycle, 'i' is the loop variable.

    private:
    int nCycles;                             // total number of iterations
    int savedPerc;
};

#endif
