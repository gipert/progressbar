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

      // default constructor, must call SetNIter later
      ProgressBar();
      ProgressBar(int n, char opt = '#', bool showbar = true);

      // reset bar to use it again
      void Reset();
     // set number of loop iterations
      void SetNIter(int iter);
      // chose between '#' or '->' style
      void SetStyle(char opt) { style = opt; }
      // to show only the percentage
      void ShowBar(bool flag) { showBar = flag; }
      // main function
      void Update();

    private:
      // internal counter
      int i;
      // total number of iterations
      int nCycles;
      int savedPerc;

      char style;
      bool showBar;
      // track first call of Update()
      bool updateIsCalled;
      bool setNIterIsCalled;
};

#endif
