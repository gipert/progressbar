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

#ifndef _PROGRESS_PERC_H_
#define _PROGRESS_PERC_H_

class ProgressPerc {
    
    public:
      // default destructor
      ~ProgressPerc()                             = default;
    
      // delete everything else
      ProgressPerc           (ProgressPerc const&) = delete;
      ProgressPerc& operator=(ProgressPerc const&) = delete;
      ProgressPerc           (ProgressPerc&&)      = delete;
      ProgressPerc& operator=(ProgressPerc&&)      = delete;   
    
      ProgressPerc();                       // must call SetNIter later
      ProgressPerc(int n);                  // ready to call Update

      void Reset();                        // reset instance to be use again
      void SetNIter(int iter);             // set number of loop iterations
      void Update(int i);                  // update the number with respect to the progress of the for
                                           // cycle, 'i' is the loop variable.
  
    private:
      int nCycles;                         // total number of iterations
      int savedPerc;

      bool updateIsCalled;                 // track firs call of Update
      bool setNIterIsCalled;               // be sure of setting nCycles
};

#endif
