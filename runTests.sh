### COLORING SCHEME ###
ORANGE='\033[0;33m'
RC='\033[0m' # Remove color

### SCRIPT PART ###

deleteBuildDirectory=0 # The build directory will be deleted if it has to be created

if [ ! -d "build" ]
then
	mkdir build
	deleteBuildDirectory=1
	printf "Creating a \"build\" directory.\n\n"
fi
cd build

printf "${ORANGE}STARTING CMAKE ${RC}\n"
cmake .. -DTEST=ON

printf "\n${ORANGE}STARTING MAKE ${RC}\n"
make

printf "\n${ORANGE}STARTING TESTING PHASE ${RC}\n"
make test

cd ..
if [ $deleteBuildDirectory ]
then
	rm -r build
	printf "\nDeleting \"build\" directory.\n"
fi