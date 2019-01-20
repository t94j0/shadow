#pragma once

#include "user.h"
#include <boost/filesystem.hpp>
#include <fstream>
#include <sstream>
#include <string>

namespace fs = boost::filesystem;

class Shadow {
public:
  Shadow();

  const User get_user(const std::string target_user);

  std::map<std::string, User>::const_iterator begin() const noexcept;
  std::map<std::string, User>::const_iterator end() const noexcept;

private:
  Shadow(const fs::path file_name);
  std::map<std::string, User> users;
};
