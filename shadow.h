#pragma once

#include "user.h"
#include <fstream>
#include <sstream>
#include <string>

class Shadow {
public:
  Shadow();

  const User get_user(const std::string target_user);

private:
  Shadow(const std::string file_name);
  std::map<std::string, User> users;
};
