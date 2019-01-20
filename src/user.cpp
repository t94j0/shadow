#include "user.h"

User::User() {}

User::User(std::string line) {
  std::vector<std::string> results;
  boost::split(results, line, [](char c) { return c == ':'; });

  username = results[0];
  password = results[1];

  auto days = std::stoi(results[2]);
  last_reset = bg::date(1970, 1, 1) + bg::date_duration(days);
}
std::string User::get_username() { return username; }
bg::date User::get_last_reset() { return last_reset; }
std::ostream &operator<<(std::ostream &out, const User &u) {
  out << "Username: " << u.username << std::endl;
  out << "Password: " << u.password << std::endl;
  out << "Last Reset: " << u.last_reset << std::endl;
  return out;
}

bool User::is_locked() {
  return password == "!!" || password == "!" || password == "x";
}
