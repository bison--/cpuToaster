env = DefaultEnvironment()
env['CXX'] = '/usr/bin/g++'
env['CXXFLAGS'] = '-std=c++0x -Wall -Wextra -fno-strict-aliasing -fstack-protector -D_FORTIFY_SOURCE=2 -O9'

Program('cpuToaster', [Glob('*.cpp')], LIBS=[])
