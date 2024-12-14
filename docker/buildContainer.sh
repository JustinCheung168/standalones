#!/usr/bin/env bash

# A name for the image.
IMAGE="standalones-image"

# A name for the default user of the image.
DEFAULT_USER="default-user"

# Use this script's location as an absolute reference point.
cd `dirname $0`

echo "Building image: ${IMAGE}"

# Build the image.
docker build -t ${IMAGE} \
    --force-rm \
    --no-cache \
    --platform linux/amd64 \
    --build-arg DEFAULT_USER=${DEFAULT_USER} \
    .