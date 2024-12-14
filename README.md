# standalones

Place where I dump all my miscellaneous one-off C++ stuff.

## Environment Setup

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
