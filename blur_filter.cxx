#include "blur_filter.h"

BlurFilter::BlurFilter() {
    kernel = {
        {{1, 1, 1}, {1, 1, 1}, {1, 1, 1}},
        {{1, 1, 1}, {1, 1, 1}, {1, 1, 1}},
        {{1, 1, 1}, {1, 1, 1}, {1, 1, 1}}
    };
}

void BlurFilter::apply(Image& image) {
    std::vector<std::vector<std::vector<int>>> newPixels;
    std::vector<std::vector<std::vector<int>>> pixels = image.getPixels();
    //-----------------------------------------------------------------------
    // TODO #4: Implementar el filtro de desenfoque (BLUR).

    //-----------------------------------------------------------------------
    image.setPixels(newPixels);
}