# ProgressBar
A very simple progress bar (with percentage) for c++ loops, available in two different styles (with or without the bar).

![screenshot](https://raw.githubusercontent.com/luigipertoldi/progressbar/master/bar.png?raw=true "'#' style")

## Notes
To use the bar in parallelized loops you can for example declare a shared counter `k` outside the loop and then call `ProgressBar::Update` in a critical section. With [OpenMP](http://www.openmp.org) this can be achieved with the following structure:
```cpp
int k = 0;
#pragma omp parallel for
for ( ... ) {
    #pragma omp critical
        bar.Update(k++);
}
```
