#!/bin/bash
DIR=/pnfs/dune/scratch/users/jiaoyang/build_optical_0411

TYPE=$1

find $DIR/$TYPE/b0{0,1}/v09_72_00d00/gen/*/*hist*.root  | pnfsToXRootD > ./List_of_Grid_files_temp_${TYPE}_01
find $DIR/$TYPE/b0{2,3}/v09_72_00d00/gen/*/*hist*.root  | pnfsToXRootD > ./List_of_Grid_files_temp_${TYPE}_02
find $DIR/$TYPE/b0{4,5}/v09_72_00d00/gen/*/*hist*.root  | pnfsToXRootD > ./List_of_Grid_files_temp_${TYPE}_03
find $DIR/$TYPE/makeup/v09_72_00d00/gen/*/*hist*.root   | pnfsToXRootD > ./List_of_Grid_files_temp_${TYPE}_04
find $DIR/$TYPE/makeup2/v09_72_00d00/gen/*/*hist*.root  | pnfsToXRootD > ./List_of_Grid_files_temp_${TYPE}_05

cat ./List_of_Grid_files_temp_${TYPE}_* >> ./List_of_Grid_files_$TYPE
rm ./List_of_Grid_files_temp_${TYPE}_*