class File {
public:
  File(std::string name, std::string content) : content_(content), name_(name) {
    std::cout << "[File] created" << std::endl;
  }
  std::string getName() const { return name_; }
  std::string getContent() const { return content_; }

private:
  std::string content_;
  std::string name_;
};