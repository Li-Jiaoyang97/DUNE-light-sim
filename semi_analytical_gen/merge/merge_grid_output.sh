#!/bin/bash
#
# Author: Jiaoyang Li (jiaoyang.li@ed.ac.uk)


setup_fnal_security
root -l -b <<EOF
.L grid_output_processing_real_geo.cc 
grid_output_processing_real_geo("xenon_lateral_without_annode_ref")
EOF