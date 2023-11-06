add_executable(clean_app
  clean_app.cpp
)

target_link_libraries(clean_app
  PRIVATE
    libclean
)

target_compile_features(clean_app PRIVATE cxx_std_20)
