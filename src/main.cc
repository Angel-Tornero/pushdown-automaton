#include "../include/PushdownAutomaton.h"
#include <iostream>
#include <fstream>

void commandsMessage() {
  std::cout << "\nComandos:\n";
  std::cout << "\t- trace(): escribe la traza de la última cadena que fue introducida.\n";
  std::cout << "\t- exit():  cierra el programa.\n\n";
}

int main(int argc, char* argv[]) {
  std::string file_name = argv[1];
  commandsMessage();
  PushdownAutomaton automaton(file_name);
  std::ofstream output_file("./output/trace.md");
  std::string input_file_name;
  if (output_file.fail()) std::cout << "no se pudo abrir el fichero de salida\n";
  if (argc > 2) input_file_name = argv[2];
  std::ifstream input_file(input_file_name);
  std::string input;
  std::cout << '\n';
  if (!input_file.fail()) {
    while (!input_file.eof()) {
      std::getline(input_file, input);
      std::cout << '-' << input << ": ";
      std::cout << (automaton.exec(input, false, output_file)? "Si pertenece al lenguaje" : "No pertenece al lenguaje") << '\n';
    }
    std::cout << '\n';
    return 1;
  }
  std::cout << "A continuación, puede introducir cadenas por teclado para que el autómata las reconozca o algún comando de los especificados arriba:\n\n";
  while (true) {
    std::string command;
    std::cout << "> ";
    std::cin >> command;
    if (command == "exit()") break;
    if (command == "trace()") {
      std::cout << "La traza se ha escrito en el fichero ./output/trace.md\n";
      automaton.exec(input, true, output_file);
      return 0;
    }
    input = command;
    std::cout << (automaton.exec(input, false, output_file)? "Si pertenece al lenguaje" : "No pertenece al lenguaje") << '\n';
  }
  return 0;
}
