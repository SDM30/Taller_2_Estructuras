#include "blur_filter.h"
#include "image.h"
#include "negative_filter.h"
#include "pixelate_filter.h"
#include "sepia_filter.h"
#include "task.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <sstream> //Para dividir strings

void processTask(Task &task);
void addTask(std::vector<Task>& tareas, std::string tarea);

int main(int argc, char *argv[]) {
  if (argc < 2) {
    std::cerr << "Uso: " << argv[0] << " <archivo_de_tareas.txt>" << std::endl;
    return 1;
  }

  std::string tasksFileName = argv[1];
  std::ifstream TasksFile(tasksFileName);

  if (!TasksFile.is_open()) {
    std::cerr << "Error al abrir el archivo de tareas: " << tasksFileName
              << std::endl;
    return 1;
  }

  // TODO #1: Crear una estructura de datos para procesar una serie de tareas de
  // manera secuencial.
  std::vector<Task> secuencialTareas;

  int numTasks;
  TasksFile >> numTasks;
  //ignorar primera linea en la lectura
  TasksFile.ignore(1000, '\n');

  for (int i = 0; i < numTasks; ++i) {
    // TODO #2: Leer las tareas del archivo de tareas y agregarlas a la
    // estructura secuencial de tareas
    std::string info;
    std::getline(TasksFile, info);
    std::cout << "Prueba Lectura Tarea" << std::endl;
    addTask(secuencialTareas, info);
  }

  TasksFile.close();

  // TODO #3: Procesar las tareas en orden, mostrando los resultados por
  // pantalla.
  std::vector<Task>::iterator itTask;
  for(itTask = secuencialTareas.begin(); itTask != secuencialTareas.end(); itTask++) {
    
    std::cout << itTask->id << ", "
          << itTask->inputFileName << ", "
          << itTask->outputFileName << ", "
          << itTask->filterName << std::endl;

    processTask(*itTask);
  }

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

void addTask(std::vector<Task>& tareas, std::string tarea){

  const int numDatos = 4;
  std::string datosTarea[4];

  std::stringstream lineaArchivo(tarea);

  for(int i = 0; i < numDatos; i++){

    if( !getline(lineaArchivo,datosTarea[i],' ') ){

        std::cerr << "Estructura de archivo equivocada" << std::endl;
        return;
    }

    std::cout<< datosTarea[i] << std::endl;

  }

  //Ensamblar tarea apartir de tokens
  Task tsk;
  tsk.id = std::stoi(datosTarea[0]);
  tsk.inputFileName = datosTarea[1];
  tsk.outputFileName = datosTarea[2];
  tsk.filterName = datosTarea[3];

  //Colocar tarea al final del vector
  tareas.push_back(tsk);
}

