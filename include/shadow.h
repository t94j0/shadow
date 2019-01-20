#pragma once

#include "user.h"
#include <boost/filesystem.hpp>
#include <boost/iostreams/stream.hpp>
#include <fstream>
#include <sstream>
#include <string>

namespace fs = boost::filesystem;
namespace io = boost::iostreams;

class Shadow {
public:
  Shadow();
  Shadow(const std::string content);

  const User get_user(const std::string target_user);

  std::map<std::string, User>::const_iterator begin() const noexcept;
  std::map<std::string, User>::const_iterator end() const noexcept;

private:
  Shadow(const fs::path file_name);
  std::map<std::string, User> users;
};
