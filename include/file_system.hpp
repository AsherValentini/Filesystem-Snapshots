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
  FileSystem() : ID_(0) { std::cout << "[FileSystem]\n"; }

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
  std::uint64_t snapShot() {
    auto currentFS = fs_; // create a deep copy of the fs to store for later use
    snapShots_[ID_] = currentFS;
    return ID_++;
  }

  bool restore(std::uint64_t ID) {
    auto it = snapShots_.find(ID);
    if (it != snapShots_.end()) {

      fs_ = snapShots_[ID];
      return true;
    } else {
      return false;
    }
  }
  friend std::ostream& operator<<(std::ostream& os, const FileSystem& f);

private:
  std::unordered_map<std::string, std::vector<File>> fs_;
  std::unordered_map<std::uint64_t, std::unordered_map<std::string, std::vector<File>>> snapShots_;
  std::uint64_t ID_;
};
