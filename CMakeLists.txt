cmake_minimum_required(VERSION 3.4)
project(CalculatorJIT)

set(CMAKE_CXX_STANDARD 14)

find_package(LLVM CONFIG REQUIRED)
message(INFO " Using LLVM version " ${LLVM_VERSION} " in " ${LLVM_DIR})

set(CMAKE_INCLUDE_CURRENT_DIR ON)

include_directories(${LLVM_INCLUDE_DIRS})
add_definitions(${LLVM_DEFINITIONS})

set(AST_SOURCES baseast.cpp arithoperator.cpp litint.cpp)

add_executable(calcjit main.cpp ${AST_SOURCES})
llvm_map_components_to_libraries(llibs all)
target_link_libraries(calcjit ${llibs})
