#pragma once

#include <boost/algorithm/string.hpp>
#include <boost/date_time/gregorian/gregorian.hpp>
#include <string>

namespace bg = boost::gregorian;

class User {
public:
  User();
  User(std::string line);

  std::string get_username();
  bg::date get_last_reset();
  friend std::ostream &operator<<(std::ostream &out, const User &u);

  bool is_locked();

private:
  std::string username;
  std::string password;
  bg::date last_reset;
};
