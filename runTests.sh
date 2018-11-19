### COLORING SCHEME ###
ORANGE='\033[0;33m'
RC='\033[0m' # Remove color

### SCRIPT PART ###
mkdir buildTest	
mkdir buildTest/Debug
mkdir buildTest/Release

cd buildTest/Debug
printf "${ORANGE}RUNNING DEBUG TESTING${RC}\n"
cmake ../.. -DTEST=ON -DCMAKE_BUILD_TYPE=Debug >/dev/null &&
make &&
make test

cd ../Release
printf "\n${ORANGE}RUNNING RELEASE TESTING${RC}\n"
cmake ../.. -DTEST=ON -DCMAKE_BUILD_TYPE=Release >/dev/null &&
make &&
make test

cd ../..
rm -r buildTest