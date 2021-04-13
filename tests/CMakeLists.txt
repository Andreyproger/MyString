cmake_minimum_required(VERSION 3.4.0)

 project(MyString)

 set(CMAKE_AUTOMOC ON)
 set(CMAKE_AUTORCC ON)
 set(CMAKE_AUTOUIC ON)
 
 if(CMAKE_VERSION VERSION_LESS "3.7.0")
     set(CMAKE_INCLUDE_CURRENT_DIR ON)
 endif()
 
 set(AUTOGEN_BUILD_DIR build)
 set(AUTOGEN_TARGETS_FOLDER build)

 #enable_testing()

 find_package(Boost COMPONENTS system filesystem unit_test_framework REQUIRED)
 
 file(GLOB_RECURSE main_sources FOLLOW_SYMLINKS "source/*.c*")
 
 add_executable(telegram
     main_test.cpp
     ${main_sources}
 )

 #target_link_libraries(telegram Qt5::Widgets Qt5::SerialPort Qt5::Network Qt5::PrintSupport ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})
 
# set_property(TARGET telegram APPEND PROPERTY AUTOMOC_MACRO_NAMES "Q_OBJECT")