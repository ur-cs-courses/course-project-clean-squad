add_executable(main
  Main.cpp
)

target_link_libraries(main
  PRIVATE
    libclean
)

target_compile_features(main PRIVATE cxx_std_20)
