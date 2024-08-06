#ifndef PIXELATE_FILTER_H
#define PIXELATE_FILTER_H

#include "image.h"

class PixelateFilter {
public:
  void apply(Image &image, int blockSize);
};

#endif // PIXELATE_FILTER_H
