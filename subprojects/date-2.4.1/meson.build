project('hinnant-date', ['cpp'],
        default_options: ['cpp_std=c++17'],
        license: 'MIT')

pkg = import('pkgconfig')

thread_dep = dependency('threads')

header_files = files(
  'include/date/chrono_io.h',
  'include/date/date.h',
  'include/date/ios.h',
  'include/date/islamic.h',
  'include/date/iso_week.h',
  'include/date/julian.h',
  'include/date/tz.h',
  'include/date/tz_private.h'
)
defines = []
public_defines = []
deps = [thread_dep]
if get_option('use_system_tzdb')
  defines += ['-DUSE_AUTOLOAD=0', '-DHAS_REMOTE_API=0']
  public_defines += ['-DUSE_OS_TZDB=1']
else
  defines += ['-DUSE_AUTOLOAD=1', '-DHAS_REMOTE_API=1']
  public_defines += ['-DUSE_OS_TZDB=0']
  deps += dependency('libcurl')
endif

if get_option('use_tzdb_in_dot')
  defines += ['-DINSTALL=.']
endif

i = include_directories('include')
tz_lib = library('tz', 'src/tz.cpp',
     include_directories: i,
     cpp_args: defines + public_defines,
     dependencies: deps)

tz_dep = declare_dependency(
  compile_args: public_defines,
  include_directories: i,
  link_with: tz_lib
)
date_dep = declare_dependency(
  include_directories: i
)
