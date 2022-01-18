

project('hain', 'cpp')

cmake = import('cmake')

json_proj = subproject('json')
dep = json_proj.get_variable('nlohmann_json_dep')

boost_dep = dependency('boost')

catch2_proj = cmake.subproject('Catch2')
catch2main = catch2_proj.get_variable('Catch2WithMain')
catch2 = catch2_proj.get_variable('Catch2')

sub_proj = cmake.subproject('cpr')
cpr = sub_proj.get_variable('cpr')

executable('hain', ['rev.cc'], 
  cpp_args: ['-O2', '-std=c++20', '-fno-exceptions'],
  link_args: ['-lpthread'], 
  dependencies: [dep],
  include_directories: [include_directories('subprojects/cpr/include/', 'subprojects/cpr/__CMake_build/cpr_generated_includes/')],
  link_with: [cpr])


t1 = executable('test1', ['tests/first.cc'], link_with: [catch2main, catch2], include_directories: [include_directories('subprojects/Catch2/src/')])

test('basic testing', t1)
