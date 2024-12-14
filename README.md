# standalones

Place where I dump all my miscellaneous one-off C++ stuff.

## Command Line-Based Environment Setup

Setup instructions assume you are at this project's top level.

Environment is a project-specific Docker image specified in `docker/`.

To build the Docker image for the first time (will take a little while):
```bash
./docker/buildContainer.sh
```

To enter this container from the command line:
```bash
./docker/enterContainer.sh
```

Entering the container should put you into this project's `build` directory.

From within the container, in the `build` directory, use CMake:
```bash
cmake ..
```

Then compile the code:
```bash
make
```

The executables are placed in `build/bin/`.


## VSCode Environment Setup
Alternatively, you can use the Docker extension of VSCode. In this case:
```bash
./docker/buildContainer.sh
```

Then reopen the window in a container (lower-left button). `.devcontainer/devcontainer.json` specifies how it is opened.

Then:
```bash
mkdir -p build
cd build
make ..
```
