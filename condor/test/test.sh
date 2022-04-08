#!/bin/bash
# file name: test.sh

command() {
    echo '>' $1
    $1
}

command "whoami"
command "hostname"
command "df -h"
command "pwd"
command "ls -l /cvmfs/oasis.opensciencegrid.org/gluex/group/halld/Software/builds/Linux_CentOS7-x86_64-gcc8.3.1-cntr"
command "which singularity"
command "cat /etc/redhat-release"
