#!/bin/bash

# argon
project.py --xml ./argon_xml/prod_optical_dune_argon_makeup.xml --stage gen --clean
project.py --xml ./argon_xml/prod_optical_dune_argon_makeup.xml --stage gen --submit

# xenon
project.py --xml ./xenon_xml/prod_optical_dune_xenon_makeup.xml --stage gen --clean
project.py --xml ./xenon_xml/prod_optical_dune_xenon_makeup.xml --stage gen --submit