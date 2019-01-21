#pragma once

#include <date/date.h>
#include <string>

class User {
public:
  User() = default;
  User(std::string line);

  const std::string get_username() const;
  const date::year_month_day get_last_reset() const;
  friend std::ostream &operator<<(std::ostream &out, const User &u);

  const bool is_locked() const;

private:
  std::string username;
  std::string password;
  date::year_month_day last_reset;
};
