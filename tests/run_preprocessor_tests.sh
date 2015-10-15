#!/bin/bash

MSYS=""
shopt -s nocasematch
if [[ "$(uname -o)" == "msys" ]]; then
  MSYS=1
fi
shopt -u nocasematch

DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
if [[ $MSYS ]]; then
  DIR=$(echo $DIR | sed 's_^\([a-zA-Z]\):_/\1_')
fi

INC_DIR="${DIR}/../include"

GREEN='\033[1;32m'
RED='\033[1;31m'
PURPLE='\033[0;35m'
NC='\033[0m'

pattern=$1
if [[ -z $pattern ]]; then
  pattern="*.test"
fi
pattern="${DIR}/preprocessor_tests/${pattern}"


function echo_src {
  echo "#include <pp_mage.h>"
  echo -n "$1"
}

function trim_lines {
  sed -e's/#.*$//' -e's/^[ \t]*//' -e'/^$/d'
}

function run_test {
  local src="$1"

  src=$(echo "$src" | awk '
    BEGIN { FS="[ \t]*==[ \t]*"; OFS=" @@@ "; }
    NF == 1 && $1 ~ /^\[/ { print "\"" $1 "\""; next; }
    NF == 1 { print $1; next; }
    NF == 2 { print "\"" $1 "\"", $1, $2 }
  ')

  local result=$(echo_src "$src" | $CC -E -I $INC_DIR - | trim_lines)

  echo "$result" | awk -v GREEN=$GREEN -v RED=$RED -v NC=$NC '
    function unstr(x) { gsub(/^"|"$/, "", x); return x; }
    function stats() {
      if (group) {
        if (failed > 0) {
          print "Succeeded: " succeed ". Failed: " failed ".";
        }
        print "";
        total_failed += failed;
        succeed = 0;
        failed = 0;
      }
    }

    BEGIN {
      FS="[ \t]*@@@[ \t]*";
      succeed = 0;
      failed = 0;
      group = 0;
      total_failed = 0;
    }
    $1 ~ /^"\[/ { stats(); group = unstr($1); print GREEN group NC; next; }
    $2 == $3 && group { print unstr($1), GREEN "succeed" NC; succeed++; }
    $2 != $3 && group { print unstr($1), RED "failed" NC, $2 " != " $3; failed++; }
    END { stats(); exit(total_failed); }
  '

  return $?
}

total_failed=0
for test_name in $pattern; do
  printf "${PURPLE}TEST SUITE${NC} ${test_name##*/}\n"

  run_test "$(cat $test_name)"

  total_failed=$((total_failed + $?))
done

if [[ $total_failed == 0 ]]; then
  echo "SUCCEED"
  exit 0
fi

if [[ $total_failed != 0 ]]; then
  echo "FAILED ${total_failed} TESTS"
  exit 1
fi