cmake -E remove_directory build
cmake -E make_directory build
cmake -S . -B build
cmake --build build