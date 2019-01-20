project('shadow', 'cpp',
  version : '1.0.0',
  license : 'MIT',
  default_options : ['cpp_std=c++17'])

boost_dep = dependency('boost', modules: ['system'])

inc = include_directories('include')

subdir('include')
subdir('src')
subdir('test')

pkg_mod = import('pkgconfig')
pkg_mod.generate(libraries : shadow,
                 version : '1.0',
                 name : 'libshadow',
                 filebase : 'shadow',
                 description : 'Library for /etc/shadow information')
