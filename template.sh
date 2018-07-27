#!/bin/bash
new_dir="$(echo $1 | sed 's/ /_/g')"
echo $new_dir
mkdir $new_dir
cd $new_dir
touch README.md
touch solution.cc
echo "#include <bits/stdc++.h>" >> solution.cc
echo "using namespace std;" >> solution.cc
