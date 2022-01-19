

project('hain', 'cpp')

cmake = import('cmake')

json_proj = subproject('json')
json = json_proj.get_variable('nlohmann_json_dep')

boost_dep = dependency('boost')

catch2_proj = cmake.subproject('Catch2')
catch2main = catch2_proj.dependency('Catch2WithMain')
catch2 = catch2_proj.dependency('Catch2')

sub_proj = cmake.subproject('cpr')
cpr = sub_proj.dependency('cpr')

executable('hain', ['rev.cc'], 
  cpp_args: ['-O2', '-std=c++20', '-fno-exceptions'],
  dependencies: [json, cpr],
  link_args: ['-lpthread'], 
  #include_directories: [include_directories('subprojects/cpr/include/', 'subprojects/cpr/__CMake_build/cpr_generated_includes/')],
  #include_directories: [include_directories('subprojects/cpr/include/', 'subprojects/cpr/__CMake_build/cpr_generated_includes/')],
  )


t1 = executable('test1', ['tests/first.cc'], 
  dependencies: [catch2main, catch2], 
  #include_directories: [include_directories('subprojects/Catch2/src/')])
  )

test('basic testing', t1)
