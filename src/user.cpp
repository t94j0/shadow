#include "user.h"
#include <boost/algorithm/string.hpp>

User::User(std::string line) {
  using namespace date;
  using namespace std::chrono;
  std::vector<std::string> results;
  boost::split(results, line, [](char c) { return c == ':'; });

  username = results.at(0);
  password = results.at(1);

  auto days_since = std::stoi(results.at(2));

  last_reset = sys_days(1970_y / January / 1) + days{days_since};
}
const std::string User::get_username() { return username; }
const date::year_month_day User::get_last_reset() { return last_reset; }
std::ostream &operator<<(std::ostream &out, const User &u) {
  out << "Username: " << u.username << "\n";
  out << "Password: " << u.password << "\n";
  out << "Last Reset: " << u.last_reset << "\n";
  return out;
}

bool User::is_locked() {
  return password == "!!" || password == "!" || password == "x";
}
