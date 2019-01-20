#include "shadow.h"

Shadow::Shadow() : Shadow("/etc/shadow") {}

Shadow::Shadow(const std::string file_name) {
  std::ifstream shadow(file_name);
  std::string line;
  while (std::getline(shadow, line)) {
    User tmp(line);
    users[tmp.getUsername()] = tmp;
    if (!tmp.is_locked())
      std::cout << tmp << std::endl;
  }
}

const User Shadow::get_user(const std::string target_user) {
  return users[target_user];
}
