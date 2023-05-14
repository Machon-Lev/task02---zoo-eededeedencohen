cmake_minimum_required(VERSION 3.15)
project(tasks_week3_eden_cohen CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

# Add executable
add_executable(tasks_week3_eden_cohen)

# Add source and include directories
add_subdirectory(src)
add_subdirectory(include)

# Set compiler options for MSVC
if(MSVC)
    target_compile_options(tasks_week3_eden_cohen PRIVATE /W3 /permissive- /Zc:externConstexpr /Zc:inline)
endif()
