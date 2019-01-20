#include "shadow.h"

Shadow::Shadow() : Shadow("/etc/shadow") {}

Shadow::Shadow(const std::string file_name) {
  std::ifstream shadow(file_name);
  std::string line;
  while (std::getline(shadow, line)) {
    User tmp(line);
    users[tmp.get_username()] = tmp;
  }
}

const User Shadow::get_user(const std::string target_user) {
  return users[target_user];
}

std::map<std::string, User>::const_iterator Shadow::begin() const noexcept {
  return users.cbegin();
}

std::map<std::string, User>::const_iterator Shadow::end() const noexcept {
  return users.cend();
}
