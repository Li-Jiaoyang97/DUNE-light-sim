# DUNE-light-sim
This software package includes all files used for generating the training sample for fast optical simulation in DUNE-VD geometry. 

## General idea/Background info (will be better written in the future)
The fast optical simulation in DUNE-vd are using so-called hybrid model, which is the combination of semi-analytcial model (active volume --inside of the field cage) and photon library (non-active volume -- outside of the field cage)
- Semi-analytical model, see this [publication](https://link.springer.com/article/10.1140/epjc/s10052-021-09119-3)
  - Tuturial: see this [website](https://cdcvs.fnal.gov/redmine/projects/sbn-analysis-group/wiki/Tutorial_3_Semi-Analytic_mode_How_to_generate_the_correction_curves). 
- Photon library:
  - It is a sheme to voxelise the LArTPC. In each voxel, you emit the photon bomb (a collection of photons) and use GEANT 4 full optical simulation to calculate the repsonse (visibility) for each Photon Detectors (PDs). Subsequently, the visibilites for each voxel for each PDs is saved in a table to be future called, thus this method is also called the look-up table method. 

- The DUNE-VD is xenon-doped argon, and with the current setup for LArSoft would not allow us to have simulation directly on xenon-doped argon. Thus we are doing simulation for argon and xenon separately and combined them together in detsim stage. 

## Descriptions of the code in this repo: 
- semi-analytical traning sample generations:
  - The used fcl are under `/semi_analytical_gen/fcls`, there are two of them: 
    - `dunevd10kt_3view_v5_1x8x14_full_ref.fcl` --> This fcl include all information needed for the full optical simulation, geometry information, Refractive index spectrum, Rayleigh scattering spectrum, absoprtion length spectrum...
      - You are more than welcome to ask me questions (Jiaoyang Li) if there is anything in the fhicl you are unsure. 
      - Tips: always run `fhicl-dump` on your modified fhicl to see whether you changed everything you want to. 
    -  `dunevd10kt_3view_v5_1x8x14_full_ref.fcl` --> This fcl include all same information expect for the anode reflection. This is the legacy fcl we have when the anode is designed to be super reflective and we were asked to enable the functionality to include/not-include the anode reflections in xenon case. However, since the current reflectivity of anode is only ~12 %, we decided to absorb this reflections into the border effect (as how we handle the field-cage reflection and the anode reflectivity in argon-case) **This decision of course can be remaded with further study.**
 - The bash scripts we used to generate points for shotting photons are under `/semi_analytical_gen/bash_script`
   - `argon_sh` and `xenon_sh` essentially contains the same points expect for the momentum `p` of the photon are different (argon -- 9.69 and xenon -- 7.09, these are calculated by their wavelength)
- folder: `/semi_analytical_gen/xml` --> we are using `project.py` to submit grid jobs, for such command, we need to have `xml` files
  - please revisit this folder to change everything to your own directory. 


## How to: 
- Semi-analytical model: 
  - There is a bash script `submitgrid.sh` under `/semi_analytical_gen/bash_script`, which would submit all grid jobs for the training sample. 
