# CMake generated Testfile for 
# Source directory: /home/apostolis/Desktop/CppTrader
# Build directory: /home/apostolis/Desktop/CppTrader
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(cpptrader-tests "cpptrader-tests" "--durations" "yes" "--order" "lex")
set_tests_properties(cpptrader-tests PROPERTIES  _BACKTRACE_TRIPLES "/home/apostolis/Desktop/CppTrader/CMakeLists.txt;93;add_test;/home/apostolis/Desktop/CppTrader/CMakeLists.txt;0;")
subdirs("modules")
