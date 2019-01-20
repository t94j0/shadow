#include "shadow.h"

int main() {
  Shadow users;
  for (const auto &user_pair : users) {
    auto [username, user] = user_pair;
    if (!user.is_locked())
      std::cout << user << std::endl;
  }
}
