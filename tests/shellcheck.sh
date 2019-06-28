#!/bin/sh
set -euf

### NAVIGATE TO THE TESTS FOLDER ###
cd "$(dirname "$0")"

### COLORING SCHEME ###
GREEN=$(tput setaf 2)
ORANGE=$(tput setaf 3)
NOCOLOR=$(tput sgr0)

### SCRIPT CORE ###
printf "%sCHECKING SCRIPTS VALIDITY%s\\n" "${ORANGE}" "${NOCOLOR}"
shellcheck setup.sh
shellcheck build.sh
shellcheck run.sh
printf "%sSCRIPTS ARE OK%s\\n" "${GREEN}" "${NOCOLOR}"
