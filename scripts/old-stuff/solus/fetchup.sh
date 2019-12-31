#!/bin/bash

packagename=$1
version=$2
url=$3

if [[ $# -lt 1 ]] ; then
  echo "Usage: fcub [packagename] [version] [url]"
else
  git clone https://dev.getsol.us/source/${packagename}.git

  cd ${packagename}
  yupdate ${version} ${url}
fi
