#!/bin/bash
#
# Author: Jiaoyang Li (jiaoyang.li@ed.ac.uk)

#find /pnfs/dune/scratch/users/jiaoyang/light_generation_dunevd/argon/semi_analytic_hits_vd_cathode_full_refl_argon/out/*/*.root | pnfsToXRootD > List_of_Grid_files_argon_cathode
find /pnfs/dune/scratch/users/jiaoyang/light_generation_dunevd/argon/semi_analytic_hits_vd_laterals_full_refl_argon_varying_x/out/*/*.root | pnfsToXRootD > List_of_Grid_files_argon_lateral
find /pnfs/dune/scratch/users/jiaoyang/light_generation_dunevd/argon/semi_analytic_hits_vd_laterals_full_refl_argon_varying_z/out/*/*.root | pnfsToXRootD >> List_of_Grid_files_argon_lateral

#find /pnfs/dune/scratch/users/jiaoyang/light_generation_dunevd/xenon/semi_analytic_hits_vd_cathdoe_full_refl_xenon/out/*/*.root | pnfsToXRootD > List_of_Grid_files_xenon_cathode_full_ref
#find /pnfs/dune/scratch/users/jiaoyang/light_generation_dunevd/xenon/semi_analytic_hits_vd_cathode_without_anode_refl_xenon/out/*/*.root | pnfsToXRootD > List_of_Grid_files_xenon_cathode_without_annode_ref
find /pnfs/dune/scratch/users/jiaoyang/light_generation_dunevd/xenon/semi_analytic_hits_vd_laterals_full_refl_xenon_varying_x/out/*/*.root | pnfsToXRootD > List_of_Grid_files_xenon_lateral_full_ref
find /pnfs/dune/scratch/users/jiaoyang/light_generation_dunevd/xenon/semi_analytic_hits_vd_laterals_full_refl_xenon_varying_z/out/*/*.root | pnfsToXRootD >> List_of_Grid_files_xenon_lateral_full_ref
find /pnfs/dune/scratch/users/jiaoyang/light_generation_dunevd/xenon/semi_analytic_hits_vd_laterals_without_anode_refl_xenon_varing_x/out/*/*.root | pnfsToXRootD > List_of_Grid_files_xenon_lateral_without_annode_ref
find /pnfs/dune/scratch/users/jiaoyang/light_generation_dunevd/xenon/semi_analytic_hits_vd_laterals_without_anode_refl_xenon_varing_z/out/*/*.root | pnfsToXRootD >> List_of_Grid_files_xenon_lateral_without_annode_ref
