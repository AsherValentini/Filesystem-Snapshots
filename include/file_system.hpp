#pragma once

#include <string>
#include <cstdint>
#include <unordered_map>
#include <iostream>
#include <vector>
#include <memory>
#include <optional>
#include <algorithm>

#include "file.hpp"

class FileSystem {

public:
  FileSystem() { std::cout << "[FileSystem] created with ID: \n"; }

  void mkdir(const std::string& path) {
    auto it = fs_.find(path);
    if (it == fs_.end()) {
      fs_[path];
    }
  }
  bool addFile(const std::string& path, const std::string& fileName, const std::string& content) {
    auto it = fs_.find(path);

    if (it == fs_.end()) {
      return false; // to me it makes sense that we should not create a whole new file path if the
                    // person used the wrong file path
    } else {
      it->second.emplace_back(
          fileName, content); // constructs a File objects in place at the back of the file vector
      return true;
    }
  }

  std::optional<std::string> readFile(const std::string& path, const std::string& fileName) const {

    auto itPath = fs_.find(path);
    if (itPath != fs_.end()) {
      auto itFile = std::find_if(itPath->second.begin(), itPath->second.end(),
                                 [&fileName](const File& a) { return a.getName() == fileName; });

      if (itFile != itPath->second.end()) {
        return itFile->getContent();
      } else {
        return std::nullopt;
      }
    } else {
      return std::nullopt;
    }
  }
  void snapShot() {}
  void restore(std::uint8_t ID) {}

private:
  std::unordered_map<std::string, std::vector<File>> fs_;
  std::unordered_map<std::uint64_t, std::unordered_map<std::string, std::vector<File>>> snapShots_;
};
