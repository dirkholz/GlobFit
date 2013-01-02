cmake_minimum_required (VERSION 2.6) 
project (globfit) 

set(CMAKE_BUILD_TYPE RelWithDebInfo)
# set(CMAKE_CXX_FLAGS "-pedantic -Wno-variadic-macros -Weffc++ -Wno-long-long")
# set(CMAKE_CXX_FLAGS "-Wno-variadic-macros -Weffc++ -Wno-long-long")
set(CMAKE_CXX_FLAGS "-W -Wall -Wno-unused-parameter -frounding-math ")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib) 
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin) 
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib) 

include_directories($(globfit_source_dirk)/include /usr/local/MATLAB/R2012a/extern/include)
link_directories(/usr/local/MATLAB/R2012a/bin/glnxa64)
link_libraries(osg osgText osgViewer osgGA CGAL eng mat mx boost_program_options boost_thread boost_filesystem boost_system)

add_library(globfit
  src/ColorMap.cpp
  src/Cone.cpp
  src/Cylinder.cpp
  src/EqualityAlignment.cpp
  src/GlobFit.cpp
  src/OrientationAlignment.cpp
  src/PlacementAlignment.cpp
  src/Plane.cpp
  src/Primitive.cpp
  src/Relation.cpp
  src/RelationEdge.cpp
  src/RelationGraph.cpp
  src/RelationVertex.cpp
  src/Sphere.cpp
  src/Solver.cpp
  src/Render.cpp
)

add_executable(gt
  src/main.cpp
  src/Viewer.cpp
)

target_link_libraries(gt globfit)
