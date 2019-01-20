#pragma once

#include "user.h"
#include <filesystem>
#include <fstream>
#include <map>
#include <sstream>
#include <string>

namespace fs = std::filesystem;
typedef std::map<std::string, User>::const_iterator usermap_citer;

class Shadow {
public:
  Shadow();
  Shadow(std::istream &&content);
  Shadow(const fs::path file_name);
  Shadow(const std::string content);

  const User get_user(const std::string target_user);

  usermap_citer begin() const noexcept;
  usermap_citer end() const noexcept;

private:
  std::map<std::string, User> users;
};
