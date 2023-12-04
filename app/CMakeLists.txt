set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

add_executable(main
  Main.cpp
)

target_link_libraries(main
  PRIVATE
    libclean
    Threads::Threads
)

target_compile_features(main PRIVATE cxx_std_20)
