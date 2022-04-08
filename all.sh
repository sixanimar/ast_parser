#!/bin/bash

rm -f combined.ast

find . -type f -name '*.ast' | sort -n | xargs cat >> combined.ast

./pars combined.ast

mv small_combined.ast $1

rm -f combined.ast