#!/bin/bash

# argon
project.py --xml ./argon_xml/prod_optical_dune_argon00.xml --stage gen --clean
project.py --xml ./argon_xml/prod_optical_dune_argon00.xml --stage gen --submit

project.py --xml ./argon_xml/prod_optical_dune_argon01.xml --stage gen --clean
project.py --xml ./argon_xml/prod_optical_dune_argon01.xml --stage gen --submit

project.py --xml ./argon_xml/prod_optical_dune_argon02.xml --stage gen --clean
project.py --xml ./argon_xml/prod_optical_dune_argon02.xml --stage gen --submit

project.py --xml ./argon_xml/prod_optical_dune_argon03.xml --stage gen --clean
project.py --xml ./argon_xml/prod_optical_dune_argon03.xml --stage gen --submit

project.py --xml ./argon_xml/prod_optical_dune_argon04.xml --stage gen --clean
project.py --xml ./argon_xml/prod_optical_dune_argon04.xml --stage gen --submit

project.py --xml ./argon_xml/prod_optical_dune_argon05.xml --stage gen --clean
project.py --xml ./argon_xml/prod_optical_dune_argon05.xml --stage gen --submit

# xenon
project.py --xml ./xenon_xml/prod_optical_dune_argon00.xml --stage gen --clean
project.py --xml ./xenon_xml/prod_optical_dune_argon00.xml --stage gen --submit

project.py --xml ./xenon_xml/prod_optical_dune_argon01.xml --stage gen --clean
project.py --xml ./xenon_xml/prod_optical_dune_argon01.xml --stage gen --submit

project.py --xml ./xenon_xml/prod_optical_dune_argon02.xml --stage gen --clean
project.py --xml ./xenon_xml/prod_optical_dune_argon02.xml --stage gen --submit

project.py --xml ./xenon_xml/prod_optical_dune_argon03.xml --stage gen --clean
project.py --xml ./xenon_xml/prod_optical_dune_argon03.xml --stage gen --submit

project.py --xml ./xenon_xml/prod_optical_dune_argon04.xml --stage gen --clean
project.py --xml ./xenon_xml/prod_optical_dune_argon04.xml --stage gen --submit

project.py --xml ./xenon_xml/prod_optical_dune_argon05.xml --stage gen --clean
project.py --xml ./xenon_xml/prod_optical_dune_argon05.xml --stage gen --submit