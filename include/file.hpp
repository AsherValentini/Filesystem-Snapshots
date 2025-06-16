#pragma once

class File {
public:
  File(std::string name, std::string content)
      : content_(std::move(content)), name_(std::move(name)) {}
  std::string getName() const { return name_; }
  std::string getContent() const { return content_; }

private:
  std::string content_;
  std::string name_;
};

inline std::ostream& operator<<(std::ostream& os, const File& f) {
  os << "(" << f.getName() << ", " << f.getContent() << ") \n";
  return os;
}