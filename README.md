# DUNE-light-sim
This software package includes all files used for light simulation for DUNE-vd. 

## General idea/Background info (will be better written in the future)
The fast optical simulation in DUNE-vd are using so-called hybrid model, which is the combination of semi-analytcial model (active volume --inside of the field cage) and photon library (non-active volume -- outside of the field cage)
- Semi-analytical model, see this [publication](https://link.springer.com/article/10.1140/epjc/s10052-021-09119-3)
  - Tuturial: see this [website](https://cdcvs.fnal.gov/redmine/projects/sbn-analysis-group/wiki/Tutorial_3_Semi-Analytic_mode_How_to_generate_the_correction_curves). 
- Photon library:
  - It is a sheme to voxelise the LArTPC. In each voxel, you emit the photon bomb (a collection of photons) and use GEANT 4 full optical simulation to calculate the repsonse (visibility) for each Photon Detectors (PDs). Subsequently, the visibilites for each voxel for each PDs is saved in a table to be future called, thus this method is also called the look-up table method. 


