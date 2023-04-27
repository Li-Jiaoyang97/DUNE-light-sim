#!/bin/bash
#
setup_fnal_security
root -l -b <<EOF
.L grid_output_processing_real_geo.cc 
grid_output_processing_real_geo("argon_cathode")
EOF

setup_fnal_security
root -l -b <<EOF
.L grid_output_processing_real_geo.cc 
grid_output_processing_real_geo("argon_lateral")
EOF

setup_fnal_security
root -l -b <<EOF
.L grid_output_processing_real_geo.cc 
grid_output_processing_real_geo("xenon_cathode_full_ref")
EOF

setup_fnal_security
root -l -b <<EOF
.L grid_output_processing_real_geo.cc 
grid_output_processing_real_geo("xenon_cathode_without_annode_ref")
EOF

setup_fnal_security
root -l -b <<EOF
.L grid_output_processing_real_geo.cc 
grid_output_processing_real_geo("xenon_lateral_full_ref")
EOF
setup_fnal_security
root -l -b <<EOF
.L grid_output_processing_real_geo.cc 
grid_output_processing_real_geo("xenon_lateral_without_annode_ref")
EOF