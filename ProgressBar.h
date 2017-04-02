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

#ifndef _PROGRESS_BAR_H_
#define _PROGRESS_BAR_H_

class ProgressBar {
    
    public:
      // default destructor
      ~ProgressBar()                             = default;
    
      // delete everything else
      ProgressBar           (ProgressBar const&) = delete;
      ProgressBar& operator=(ProgressBar const&) = delete;
      ProgressBar           (ProgressBar&&)      = delete;
      ProgressBar& operator=(ProgressBar&&)      = delete;   
    
      ProgressBar();                       // must call SetNIter later
      ProgressBar(int n, char opt = '#', bool showbar = true);                  // ready to call Update

      void Reset();                        // reset bar to be use again
      void SetNIter(int iter);             // set number of loop iterations
      void SetStyle(char opt) { style = opt; }
      void ShowBar(bool flag) { showBar = flag; }
      void Update(int i);  // update the bar with respect to the progress of the for
                                           // cycle, 'i' is the loop variable.
  
    private:
      int nCycles;                         // total number of iterations
      int savedPerc;

      char style;
      bool showBar;
      bool updateIsCalled;                 // track firs call of Update
      bool setNIterIsCalled;               // be sure of setting nCycles
};

#endif
