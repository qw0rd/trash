

project('hain', 'cpp')

cmake = import('cmake')

json_proj = subproject('json')
dep = json_proj.get_variable('nlohmann_json_dep')

sub_proj = cmake.subproject('cpr')

cpr = sub_proj.get_variable('cpr')

executable('hain', ['rev.cc'], 
  cpp_args: ['-O2', '-std=c++20'],
  link_args: ['-lpthread'], 
  dependencies: [dep],
  include_directories: [include_directories('subprojects/cpr/include/', 'subprojects/cpr/__CMake_build/cpr_generated_includes/')],
  link_with: [cpr])

