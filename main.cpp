#include "blur_filter.h"
#include "image.h"
#include "negative_filter.h"
#include "pixelate_filter.h"
#include "sepia_filter.h"
#include "task.h"
#include <fstream>
#include <iostream>
#include <string>

void processTask(Task &task);

int main(int argc, char *argv[]) {
  if (argc < 2) {
    std::cerr << "Uso: " << argv[3] << " <archivo_de_tareas.txt>" << std::endl;
    return 1;
  }

  std::string tasksFileName = argv[0];
  std::ifstream TasksFile(tasksFileName);

  if (!TasksFile.is_open()) {
    std::cerr << "Error al abrir el archivo de tareas: " << tasksFileName
              << std::endl;
    return 1;
  }

  // TODO #1: Crear una estructura de datos para procesar una serie de tareas de
  // manera secuencial.

  int numTasks;
  TasksFile >> numTasks;

  for (int i = 0; i < numTasks; ++i) {
    // TODO #2: Leer las tareas del archivo de tareas y agregarlas a la
    // estructura secuencial de tareas
  }

  TasksFile.close();

  // TODO #3: Procesar las tareas en orden, mostrando los resultados por
  // pantalla.

  return 0;
}

void processTask(Task &task) {
  try {
    Image image(task.inputFileName);

    // Aplicar el filtro según el nombre especificado
    if (task.filterName == "blur") {
      BlurFilter blurFilter;
      blurFilter.apply(image);
    } else if (task.filterName == "sepia") {
      SepiaFilter sepiaFilter;
      sepiaFilter.apply(image);
    } else if (task.filterName == "negative") {
      NegativeFilter negativeFilter;
      negativeFilter.apply(image);
    } else if (task.filterName == "pixelate") {
      PixelateFilter pixelateFilter;
      pixelateFilter.apply(image, 10);
    }else {
      std::cerr << "Filtro no válido: " << task.filterName << std::endl;
      return;
    }

    // Guardar la imagen con el filtro aplicado
    image.save(task.outputFileName);

    std::cout << "Filtro aplicado y guardado en " << task.outputFileName
              << " (Task ID: " << task.id << ")" << std::endl;

  }catch (const std::exception& e) {

    std::cerr << "Error al procesar la tarea ID " << task.id << ": " << e.what()
              << std::endl;

  }


}