#include <gtest/gtest.h>
#include <shadow.h>

const std::string passwd =
    "root:PASSWORD_ROOT:17658::::::\n" +
    std::string("hari:PASSWORD_HARI:17916:0:99999:7:::\n");

TEST(ShadowTest, Constructor) {
  Shadow users(passwd);
  auto target = users.get_user("hari");
  std::cout << target << std::endl;
  ASSERT_EQ(target.get_username(), "hari");
}

TEST(ShadowTest, Iterator) {
  Shadow users(passwd);
  bool has_root, has_hari;
  for (auto &user_ctr : users) {
    auto [_, user] = user_ctr;
    if (user.get_username() == "root") {
      has_root = true;
    } else if (user.get_username() == "hari") {
      has_hari = true;
    }
  }
  ASSERT_EQ(has_root, true);
  ASSERT_EQ(has_hari, true);
}
