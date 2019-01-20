project('shadow', 'cpp',
  version : '1.0.0',
  license : 'MIT',
  default_options : ['cpp_std=c++14'])

boost_dep = dependency('boost')

exe = executable('shadow', 'src/user.cpp', 'src/shadow.cpp', 'src/main.cpp', dependencies : boost_dep)
