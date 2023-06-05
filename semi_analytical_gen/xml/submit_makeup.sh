#!/bin/bash

# xenon
#project.py --xml ./xenon_xml/prod_optical_dune_vd_laterals_full_ref_varyingz.xml --stage gen --check
#setup_fnal_security
#project.py --xml ./xenon_xml/prod_optical_dune_vd_laterals_full_ref_varyingz.xml --stage gen --makeup
project.py --xml ./xenon_xml/prod_optical_dune_vd_laterals_without_anode_ref_varyingx.xml --stage gen --check
setup_fnal_security
project.py --xml ./xenon_xml/prod_optical_dune_vd_laterals_without_anode_ref_varyingx.xml --stage gen --makeup

project.py --xml ./xenon_xml/prod_optical_dune_vd_laterals_without_anode_ref_varyingz.xml --stage gen --check
setup_fnal_security
project.py --xml ./xenon_xml/prod_optical_dune_vd_laterals_without_anode_ref_varyingz.xml --stage gen --makeup

#project.py --xml ./xenon_xml/prod_optical_dune_vd_cathode_full_ref.xml --stage gen --check
#setup_fnal_security
#project.py --xml ./xenon_xml/prod_optical_dune_vd_cathode_full_ref.xml --stage gen --makeup
#project.py --xml ./xenon_xml/prod_optical_dune_vd_cathode_without_anode_ref.xml --stage gen --check
#setup_fnal_security
#project.py --xml ./xenon_xml/prod_optical_dune_vd_cathode_without_anode_ref.xml --stage gen --makeup
project.py --xml ./xenon_xml/prod_optical_dune_vd_laterals_full_ref_varyingx.xml --stage gen --check
setup_fnal_security
project.py --xml ./xenon_xml/prod_optical_dune_vd_laterals_full_ref_varyingx.xml --stage gen --makeup

setup_fnal_security
project.py --xml ./xenon_xml/prod_optical_dune_vd_laterals_full_ref_varyingz.xml --stage gen --check
setup_fnal_security
project.py --xml ./xenon_xml/prod_optical_dune_vd_laterals_full_ref_varyingz.xml --stage gen --makeup


# argon
#project.py --xml ./argon_xml/prod_optical_dune_vd_cathode_full_ref.xml --stage gen --check
#setup_fnal_security
#project.py --xml ./argon_xml/prod_optical_dune_vd_cathode_full_ref.xml --stage gen --makeup
project.py --xml ./argon_xml/prod_optical_dune_vd_laterals_full_ref_varyingx.xml --stage gen --check
setup_fnal_security
project.py --xml ./argon_xml/prod_optical_dune_vd_laterals_full_ref_varyingx.xml --stage gen --makeup
#project.py --xml ./argon_xml/prod_optical_dune_vd_laterals_full_ref_varyingz.xml --stage gen --check
#setup_fnal_security
#project.py --xml ./argon_xml/prod_optical_dune_vd_laterals_full_ref_varyingz.xml --stage gen --makeup
