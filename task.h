#ifndef TASK_H
#define TASK_H

#include <string>

struct Task {
  int id;
  std::string inputFileName;
  std::string outputFileName;
  std::string filterName;
};

#endif // TASK_H