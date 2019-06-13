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
	if [[ ! -z ${CODECOV_TOKEN:-} ]]; then 
		COVERAGE_FLAG=-coverage		
	else
		COVERAGE_FLAG= 
	fi
	cmake ../.. -DBUILD_TESTING=ON -DCOVERAGE_FLAG="${COVERAGE_FLAG}"
	cmake --build .
	echo -e "\\n${ORANGE}TESTING BUILDMODE LIBRARY$RC"
	ctest -j2
	if [[ ! -z ${CODECOV_TOKEN:-} ]]; then 
		bash <(curl -s https://codecov.io/bash); 
	fi
)

result=$?
rm -r build
exit "$result"