gtest_dep = dependency('gtest', main: 'true', fallback: ['gtest', 'gtest_main_dep'])

test_builder = executable('test_shadow', 'shadow_test.cpp', include_directories: [inc], dependencies: [gtest_dep, boost_dep, date_dep], link_with: shadow)


test('constructor test', test_builder)
