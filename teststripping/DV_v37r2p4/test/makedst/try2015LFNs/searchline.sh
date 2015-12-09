#!/bin/bash
SAVEIFS=$IFS
IFS=$(echo -en "\n\b")

files="$(ls LHCb*)"
for file in $files
do
~/algorithms/./rr.sh $file | grep '.*LFN:.*' | grep -v '.*LFN:/lhcb/LHCb/Collision15/SEMILEPTONIC.DST/.*'
~/algorithms/./rr.sh $file | grep -c '.*LFN:.*'
done

IFS=$SAVEIFS