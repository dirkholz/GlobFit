GlobFit
=======

This is a fork of the original implementation of GlobFit_. The sources have been adapted to compile cleanly under recent Linux distributions such as the latest stable Ubuntu release 12.04 and to use cmake instead of VC++.
From the GlobFit_ website:
  
  Given a noisy and incomplete point set, we introduce a method that simultaneously recovers a set of locally fitted primitives along with their global mutual relations. 
  We operate under the assumption that the data corresponds to a man-made engineering object consisting of basic primitives, possibly repeated and globally aligned under common relations. 
  We introduce an algorithm to directly couple the local and global aspects of the problem. 
  The local fit of the model is determined by how well the inferred model agrees to the observed data, while the global relations are iteratively learned, and enforced through a constrained optimization. Starting with a set of initial RAN  SAC based locally fitted primitives, relations across the primitives such as orientation, placement, and equality are progressively learned, and conformed to. In each stage, a set of feasible relations are extracted among the candidate   relations, and then aligned, while best fitting to the input data. The global coupling corrects the primitives obtained in the local RANSAC stage, and brings them to precise global alignment. We test the robustness of our algorithm on a  range of synthesized and scanned data, with varying amount of noise, outliers, and non-uniform sampling, and validate the results against ground truth, where available.


Dependencies
------------
GlobFit depends on `Open Scene Graph`__ and CGAL_:: 

  sudo apt-get install libopenscenegraph-dev libcgal-dev

GlobFit is using Matlab's fmincon as optimizer, i.e., Matlab is required. 

 

Notes on getting it run
-----------------------

Matlab ships with older versions of libraries. If you encounter problems on newer systems you may need to replace them with those shipped with your Linux distribution.  
(in bin for compiling in bash, in sys/os for running Unix commands from within Matlab)::  

  sudo rm /usr/local/MATLAB/R2012a/bin/glnxa64/libstdc++.so.6 /usr/local/MATLAB/R2012a/sys/os/glnxa64/libstdc++.so.6
  sudo ln -sf /usr/lib/x86_64-linux-gnu/libstdc++.so.6 /usr/local/MATLAB/R2012a/bin/glnxa64/libstdc++.so.6
  sudo ln -sf /usr/lib/x86_64-linux-gnu/libstdc++.so.6 /usr/local/MATLAB/R2012a/sys/os/glnxa64/libstdc++.so.6

On newer Ubuntu systems you may encounter problems with missing libraries. You may need to::  

  sudo ln -s /lib/x86_64-linux-gnu/ld-2.15.so /lib64/ld-linux-x86-64.so.2 
  sudo ln -s /lib/x86_64-linux-gnu/libc.so.6 /lib64/libc.so.6

Matlab uses csh to call its engine. You may need to install it::

  sudo apt-get install csh

You need to run the globfit command from the globfit source directory (not build or bin, i.e., ./bin/gt ...) since it CDs into the ./matlab directory.

If you encounter problems with the provided data files, you may need to convert all files to have proper line endings, e.g., run dos2unix on all ascii data files


Deviations from the original GlobFit code
-----------------------------------------

I removed all VC++ files, and moved .h and .cpp files into include and src directories. 
In addition, I made some changes summarized (diff output) in changes_headers.txt and changes_source.txt (if you like to get patches from the original sources contact me). 
I added a cmake file to compile everything.
NOTE, the CMake file does not search for Matlab. Instead, include dir, library and library location are specified manually.


.. _GlobFit: http://vecg.cs.ucl.ac.uk/Projects/SmartGeometry/globFit/globFit_sigg11.html
.. _OSG: http://www.openscenegraph.org
__ OSG_ 
.. _CGAL: http://www.cgal.org/
