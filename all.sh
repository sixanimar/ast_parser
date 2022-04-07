#!/bin/bash

rm -rf combined.ast

find . -type f -name '*.ast' -exec cat {} + >> combined.ast

./pars combined.ast