project('shadow', 'cpp',
  version : '1.0.0',
  license : 'MIT',
  default_options : ['cpp_std=c++17'])

cpp = meson.get_compiler('cpp')

#filesystem checks
filesystem_does_not_need_experimental_code = '''#include <filesystem>
namespace fs = std::filesystem;
int main() {
    fs::recursive_directory_iterator directory(".");
}
'''
filesystem_is_not_experimental = cpp.links(filesystem_does_not_need_experimental_code)
filesystem_needs_experimental_code = '''#include <experimental/filesystem>
namespace fs = std::experimental::filesystem;
int main() {
    fs::recursive_directory_iterator directory(".");
}
'''
libstdcppfs_dep = cpp.find_library('stdc++fs', required: false)
cppexperimental_dep = cpp.find_library('c++experimental', required: false)
experimental_filesystem_requires_stdcppfs = cpp.links(filesystem_needs_experimental_code, dependencies: libstdcppfs_dep)
experimental_filesystem_requires_cppexperimental = cpp.links(filesystem_needs_experimental_code, dependencies: cppexperimental_dep)

if filesystem_is_not_experimental
  filesystem_dep = declare_dependency()
elif experimental_filesystem_requires_stdcppfs
  filesystem_dep = libstdcppfs_dep
elif experimental_filesystem_requires_cppexperimental
  filesystem_dep = cppexperimental_dep
else
  error('a filesystem implementation is required')
endif

boost_dep = dependency('boost', modules: ['system'])
date_dep = dependency('hinnant-date', fallback: ['hinnant-date', 'date_dep'])


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
