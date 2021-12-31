# Building the program
1. Clone via git clone and cd into the repo
2. Make build folder ```mkdir build && cd build```
3. Configure cmake ```cmake ..```
4. Build ```cmake --build .```

# Building Docs
1. Move into build folder
2. Reconfigure cmake ```cmake .. -DRDS_ENABLE_DOXYGEN=1```
3. Build docs ```cmake --build . --target doxygen-docs```

# Submit a pull request for any changes you have