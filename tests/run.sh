#!/usr/bin/env bash
set -euo pipefail
cd "$(dirname "${BASH_SOURCE[0]}")" # Navigate to the /tests folder

### COLORING SCHEME ###
ORANGE='\033[0;33m'
RC='\033[0m' # Remove color

### SCRIPT PART ###
echo -e "${ORANGE}BUILDING BUILDMODE LIBRARY TESTS$RC"
if [ -d build ]; then 
		rm -r build 
fi
mkdir build

(
	cd build
	cmake ../.. -DTEST=ON
	echo
	cat ./CMakeFiles/isDebug.dir/flags.make
	echo 
	make VERBOSE=1
	echo -e "\\n${ORANGE}TESTING BUILDMODE LIBRARY$RC"
	make test 
)

result=$?
rm -r build
echo 
exit "$result"