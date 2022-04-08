#!/bin/bash

rm -f combined.ast

find . -type f -name '*.ast' -exec cat {} + >> combined.ast

./pars combined.ast

mv small_combined.ast $1

rm -f combined.ast