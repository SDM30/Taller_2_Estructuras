#ifndef IMAGE_H
#define IMAGE_H

#include <string>
#include <vector>

class Image {
private:
  std::vector<std::vector<std::vector<int>>>
      pixels; // Vector tridimensional para RGB
  int width;
  int height;

public:
  Image(const std::string &filename);
  ~Image();
  std::vector<std::vector<std::vector<int>>> getPixels();
  int getWidth();
  int getHeight();
  void setPixels(std::vector<std::vector<std::vector<int>>> newPixels);
  void save(const std::string &filename) const;
  int getRed(int x, int y);
  int getGreen(int x, int y);
  int getBlue(int x, int y);
};

#endif // IMAGE_H
