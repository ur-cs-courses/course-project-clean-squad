set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

find_package(Catch2 3 REQUIRED)

add_executable(tests
  testing.cpp
)

target_link_libraries(tests
  PRIVATE
    libclean
    Catch2::Catch2WithMain
    Threads::Threads
)

target_compile_features(tests PRIVATE cxx_std_20)
