#include "shadow.h"

Shadow::Shadow() : Shadow(fs::path("/etc/shadow")) {}

Shadow::Shadow(std::istream &&content) {
  std::string line;
  while (std::getline(content, line)) {
    User tmp(line);
    users[tmp.get_username()] = tmp;
  }
}

Shadow::Shadow(const fs::path file_name) : Shadow(std::ifstream(file_name)) {}

Shadow::Shadow(const std::string content)
    : Shadow(std::istringstream(content)) {}

const User Shadow::get_user(const std::string target_user) const {
  return users.at(target_user);
}

usermap_citer Shadow::begin() const noexcept { return users.cbegin(); }

usermap_citer Shadow::end() const noexcept { return users.cend(); }
