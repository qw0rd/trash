

project('hain', 'cpp')

cmake = import('cmake')

json_proj = subproject('json')
dep = json_proj.get_variable('nlohmann_json_dep')

executable('hain', ['rev.cc'], 
  cpp_args: ['-O2', '-std=c++20'],
  link_args: ['-lpthread'], 
  dependencies: [dep])

