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
# dune_vd_laterals
# varying z. 
x_=( 285.05 210.05 135.05 60.05 )
y_=( 670. 660. 650. 620. 610. 600. 550. 500. 450. 400. 350. 300. 250. 200. 150. 100. 50. 0. )
z_=( 1945.45 1940. 1930. 1920. 1646.15 1640. 1630. 1620. 1346.85 1340. 1330. 1320. 1047.55 1040. 1030. 1020. 748.25 740. 730. 720. 448.95 440. 430. 420. 149.65 140. 130. 120. 50. 0.)


contador=0
# A shell script to print each number five times.
for (( i = 0; i < 4; i++ ))   # 16 ### Outer for loop ###
do
    
    for (( j = 0 ; j < 18; j++ ))  #20 ### Inner for loop ###
    do
	
        for (( k = 0 ; k < 30; k++ )) # 7### Inner for loop ###
		do
		    for (( l = 0; l < 1; l++ ))
		    do            
				x=${x_[$i]}
				y=${y_[$j]}
				z=${z_[$k]}
			    
				if [ "$contador" = "${NEWPROCESS}" ]
				then
				    echo "  x      y     z      t      dx      dy      dz      dt      p         dp        n" >> myLightSourceSteering_$contador.txt
		            echo "  $x    $y     $z     0.0     0.0     0.0     0.0     0.0     9.69     0.25     100000" >> myLightSourceSteering_$contador.txt
		           	#echo "  $x    $y     $z     0.0     0.0     0.0     0.0     0.0     7.09     0.25     100000" >> myLightSourceSteering_$contador.txt
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




