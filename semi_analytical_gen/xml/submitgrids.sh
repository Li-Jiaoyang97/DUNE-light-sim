#!/bin/bash

# argon
project.py --xml ./argon_xml/prod_optical_dune_vd_cathode_full_ref.xml --stage gen --clean
project.py --xml ./argon_xml/prod_optical_dune_vd_cathode_full_ref.xml --stage gen --submit
#project.py --xml ./argon_xml/prod_optical_dune_vd_laterals_full_ref_varyingx.xml --stage gen --clean
#project.py --xml ./argon_xml/prod_optical_dune_vd_laterals_full_ref_varyingx.xml --stage gen --submit
#project.py --xml ./argon_xml/prod_optical_dune_vd_laterals_full_ref_varyingz.xml --stage gen --clean
#project.py --xml ./argon_xml/prod_optical_dune_vd_laterals_full_ref_varyingz.xml --stage gen --submit

# xenon
#project.py --xml ./xenon_xml/prod_optical_dune_vd_cathode_full_ref.xml --stage gen --clean
#project.py --xml ./xenon_xml/prod_optical_dune_vd_cathode_full_ref.xml --stage gen --submit
#project.py --xml ./xenon_xml/prod_optical_dune_vd_cathode_without_anode_ref.xml --stage gen --clean
#project.py --xml ./xenon_xml/prod_optical_dune_vd_cathode_without_anode_ref.xml --stage gen --submit
project.py --xml ./xenon_xml/prod_optical_dune_vd_laterals_full_ref_varyingx.xml --stage gen --clean
project.py --xml ./xenon_xml/prod_optical_dune_vd_laterals_full_ref_varyingx.xml --stage gen --submit
project.py --xml ./xenon_xml/prod_optical_dune_vd_laterals_full_ref_varyingz.xml --stage gen --clean
project.py --xml ./xenon_xml/prod_optical_dune_vd_laterals_full_ref_varyingz.xml --stage gen --submit
project.py --xml ./xenon_xml/prod_optical_dune_vd_laterals_without_anode_ref_varyingx.xml --stage gen --clean
project.py --xml ./xenon_xml/prod_optical_dune_vd_laterals_without_anode_ref_varyingx.xml --stage gen --submit
project.py --xml ./xenon_xml/prod_optical_dune_vd_laterals_without_anode_ref_varyingz.xml --stage gen --clean
project.py --xml ./xenon_xml/prod_optical_dune_vd_laterals_without_anode_ref_varyingz.xml --stage gen --submit