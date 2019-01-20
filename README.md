# Shadow file parser

## Summary

Parses the /etc/shadow file to give password information like:

* Username
* Password hash
* Last time user reset password


## Example usage

```C++
#include <shadow.h>

Shadow users();
auto target = users.get_user("hari");
std::cout << target.get_last_reset() << std::endl;

for (auto &user_ctr : users) {
        auto [username, user] = user_ctr;
        std::cout << user << std::endl;
}
```
