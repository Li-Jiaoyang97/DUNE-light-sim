umask 0002
verbose=T

launchN=0
Njobs=1
NEWPROCESS=`echo "($launchN * $Njobs + $JOBSUBJOBSECTION - 1) " | bc`

process=${NEWPROCESS}
cluster=${CLUSTER}

# model building parameters

#------------------------------------------------------------
# dune_vd_laterals
# varying z. 
#x_=( 285.07 210.07 135.07 60.07 )
#y_=( 730. 720. 700. 680. 660. 650. 620. 600. 550. 500. 450. 400. 350. 300. 250. 200. 150. 100. 50. 0. )
#z_=( 1939.21 1935. 1925. 1915. 1641.41 1640. 1630. 1620. 1343.61 1330. 1320. 1310. 1045.81 1045. 1035. 1025. 748.005 740. 730. 720. 450.203 450. 440. 430. 152.401 150. 140. 130.)

# varying x. 
x_=( 285.07 295. 305. 315. 325. 210.07  220. 230. 240. 250. 135.07 145. 155. 165. 175. 60.07 70. 80. 90. 100.)
y_=( 670. 660. 650. 620. 610. 600. 550. 500. 450. 400. 350. 300. 250. 200. 150. 100. 50. 0. )
z_=( 2014.63 1716.27 1417.9 1119.53 821.162 522.794 224.426 )

contador=0
# A shell script to print each number five times.
for (( i = 0; i < 1; i++ ))     # 16 ### Outer for loop ###
do

    for (( j = 0 ; j < 1; j++ ))  #20 ### Inner for loop ###
    do

        for (( k = 0 ; k < 1; k++ )) # 7### Inner for loop ###
        do
            for (( l = 0; l < 1; l++ ))
            do
                x=${x_[$i]}
                y=${y_[$j]}
                z=${z_[$k]}

                #if [ "$contador" = "${NEWPROCESS}" ]
                #then
                    echo "  x      y     z      t      dx      dy      dz      dt      p         dp        n" >> myLightSourceSteering.txt
                    echo "  $x    $y     $z     0.0     0.0     0.0     0.0     0.0     9.69     0.25     100000" >> myLightSourceSteering.txt
                #echo "  $x    $y     $z     0.0     0.0     0.0     0.0     0.0     7.09     0.25     100000" >> myLightSourceSteering_$contador.txt
                #fi
                #contador=`expr $contador + 1`
            done
        done

    done

    echo "" #### print the new line ###
done

#------------------------------------------------------------


#chmod 755 myLightSourceSteering_${NEWPROCESS}.txt
#mv myLightSourceSteering_${NEWPROCESS}.txt myLightSourceSteering.txt


#echo $FHICL_FILE_PATH "fhicl file path"

# And then tell the user about it:
#echo "services.TFileService.fileName: \"${process}.root\"" >> $FCL