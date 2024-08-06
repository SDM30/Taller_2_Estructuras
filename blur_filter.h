#ifndef BLUR_FILTER_H
#define BLUR_FILTER_H

#include "image.h"

class BlurFilter {
private:
  std::vector<std::vector<std::vector<int>>> kernel; // Kernel para RGB

public:
  BlurFilter();
  void apply(Image &image);
};

#endif // BLUR_FILTER_H
