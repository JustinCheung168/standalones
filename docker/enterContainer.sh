#!/usr/bin/env bash

# A name for the image.
IMAGE="standalones-image"

# A name for the default user of the image.
DEFAULT_USER="default-user"

# Use this script's location as an absolute reference point.
cd `dirname $0`

# Assume this script is one directory under the top-level project that includes this repository.
PROJECT_ROOT=$(pwd -P)/..

# Directory to restrict access to.
VOLMAPDIR=${PROJECT_ROOT}

# Directory to enter the container at.
WORKDIR=${PROJECT_ROOT}/build

echo "Entering container of image: ${IMAGE}"

# Enter the container.
docker run --rm -it \
    -p 8888:8888 \
    -v ${VOLMAPDIR}:${VOLMAPDIR} \
    -w ${WORKDIR} \
    --user ${DEFAULT_USER} \
    ${IMAGE} \
    /bin/bash