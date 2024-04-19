rd /s /q "src/build"
cmake -S src -B src/build -G Ninja
cmake --build src/build
