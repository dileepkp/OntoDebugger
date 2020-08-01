#!/bin/bash
echo "run.sh"
gdb -x $2 -batch --args $1
