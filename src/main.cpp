#include <iostream>
#include <memory>
#include "file_system.hpp"

std::ostream& operator<<(std::ostream& os, const FileSystem& fs) {

  for (auto& [dir, files] : fs.fs_) {
    os << dir << "\n";
    for (auto& file : files) {
      os << file;
    }
  }
  return os;
}

int main() {
  auto fileSystem = std::make_shared<FileSystem>();

  // lets try out the modules functionality for mkdir, addFile, and readFile
  auto readOption = fileSystem->readFile("project/src", "main.cpp");
  if (readOption.has_value()) {
    std::cout << "[Main] contents of main.cpp at project/src: " << readOption.value() << std::endl;
  } else {
    std::cout << "[Main] either the path or file does not exist try again" << std::endl;
  }

  // create the file
  fileSystem->mkdir("project/src");
  if (!fileSystem->addFile("project/src", "main.cpp", "hello world"))
    std::cout << "[Main] failed to make file " << "main.cpp" << std::endl;

  readOption = fileSystem->readFile("project/src", "main.cpp");
  if (readOption.has_value()) {
    std::cout << "[Main] contents of main.cpp at project/src: " << readOption.value() << std::endl;
  } else {
    std::cout << "[Main] either the path or file does not exist try again" << std::endl;
  }

  // lets print the contents of the file system at this point
  std::cout << std::endl;

  std::cout << *fileSystem << std::endl;

  std::uint64_t snapID = fileSystem->snapShot();

  fileSystem->mkdir("project/include");
  if (!fileSystem->addFile("project/include", "header.hpp", "some module"))
    std::cout << "[Main] failed to make file " << "header.hpp" << std::endl;

  std::cout << *fileSystem << std::endl;

  // lets restore the file system
  if (!fileSystem->restore(snapID))
    std::cout << "[Main] restoration ID not found" << std::endl;

  std::cout << *fileSystem << std::endl;

  return 0;
}

