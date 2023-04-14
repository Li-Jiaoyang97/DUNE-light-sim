#!/bin/bash
#
# Author: bjpjones@fnal.gov from echurch@fnal.gov from dbox@fnal.gov
#
# Small subset of a script to run the optical library building job on the grid within larbatch infrastructure, modified by pkryczyn@fnal.gov
#
#
# To run this job:
#
# jobsub -X509_USER_PROXY /scratch/[user]/grid/[user].uboone.proxy -N [NoOfJobs] -q OpticalLibraryBuild_Grid.sh `whoami` `pwd`
#
# You will get outputs in the area specified by the "outstage" variable 
# which is specified below.
#
# The form of the output is one file for each few voxels. These then need 
# stitching together, which is done after all jobs are done, with a
# dedicated stitching script.
#

umask 0002
verbose=T

launchN=0
Njobs=1
NEWPROCESS=`echo "($launchN * $Njobs + $JOBSUBJOBSECTION) " | bc`

process=${NEWPROCESS}
cluster=${CLUSTER}

# model building parameters

#------------------------------------------------------------
# dune_vd_full
x_=( -320. -300. -275. -250. -225. -200. -150. -100. -50.  0. 50. 100. 150. 200. 250. 300. 320. )
y_=( 44.45 135. 201. 291.55 380.45 471. 537. 627.55 )
z_=( 46.571 50. 60. 70. 80. 187.001 190. 200. 210. 220. 484.803 485. 495. 505. 515. 644.954 650. 660. 670. 680. 782.605 785. 790. 800. 810. 942.756 945. 955. 965. 975. 1148.86 1165. 1175. 1185. 1195.)

contador=0
# A shell script to print each number five times.
for (( i = 0; i < 17; i++ ))      ### Outer for loop ###
do
    
    for (( j = 0 ; j < 8; j++ )) ### Inner for loop ###
    do
	
        for (( k = 0 ; k < 35; k++ )) ### Inner for loop ###
	do
	    for (( l = 0; l < 1; l++ ))
	    do            
		x=${x_[$i]}
		y=${y_[$j]}
		z=${z_[$k]}
	    
		if [ "$contador" = "${NEWPROCESS}" ]
		then
		    echo "x      y     z      t      dx      dy      dz      dt      p         dp        n" >> myLightSourceSteering_$contador.txt
            #echo "  $x    $y     $z     0.0     0.0     0.0     0.0     0.0     9.69     0.25     100000" >> myLightSourceSteering_$contador.txt
            echo "$x    $y     $z     0.0     0.0     0.0     0.0     0.0     7.09     0.25     100000" >> myLightSourceSteering_$contador.txt
		fi
		contador=`expr $contador + 1`
	    done
	done
	
    done
    
    echo "" #### print the new line ###
done

#------------------------------------------------------------
chmod 755 myLightSourceSteering_${NEWPROCESS}.txt

echo "==============================================="
ls myLightSourceSteering_${NEWPROCESS}.txt

mv myLightSourceSteering_${NEWPROCESS}.txt myLightSourceSteering.txt

ls myLightSourceSteering.txt
echo "==============================================="

echo $FHICL_FILE_PATH "fhicl file path"

# And then tell the user about it:
echo "services.TFileService.fileName: \"${process}.root\"" >> $FCL
