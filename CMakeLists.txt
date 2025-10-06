cmake_minimum_required(VERSION 3.22)
project(MESS LANGUAGES C CXX Fortran)

find_package(BLAS REQUIRED)
find_package(LAPACK REQUIRED)
find_library(SLATEC REQUIRED NAMES slatec libslatec)
find_package(OpenMP REQUIRED)
message(STATUS "Found BLAS: ${BLAS_LIBRARIES}")
message(STATUS "Found LAPACK: ${LAPACK_LIBRARIES}")
message(STATUS "Found SLATEC: ${SLATEC}")

# Prevent GSL from linking to regular BLAS
find_package(GSL REQUIRED)
list(FILTER GSL_LIBRARIES EXCLUDE REGEX "blas")
set(GSL_LIBRARIES "${GSL_LIBRARIES};${BLAS_LIBRARIES};${LAPACK_LIBRARIES}")
message(STATUS "Found GSL: ${GSL_LIBRARIES}")

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

# Define the library
set(MESS_SOURCES
  src/libmess/atom.cc
  src/libmess/configuration.cc
  src/libmess/crossrate.cc
  src/libmess/d3.cc
  src/libmess/divsur.cc
  src/libmess/dynamic.cc
  src/libmess/dynlib.cc
  src/libmess/graph_common.cc
  src/libmess/graph_omp.cc
  src/libmess/io.cc
  src/libmess/key.cc
  src/libmess/lapack.cc
  src/libmess/limits.cc
  src/libmess/linpack.cc
  src/libmess/logical.cc
  src/libmess/math.cc
  src/libmess/mess.cc
  src/libmess/model.cc
  src/libmess/monom.cc
  src/libmess/mpack.cc
  src/libmess/multindex.cc
  src/libmess/permutation.cc
  src/libmess/potential.cc
  src/libmess/random.cc
  src/libmess/read.cc
  src/libmess/slatec.cc
  src/libmess/structure.cc
  src/libmess/symmetry.cc
  src/libmess/system.cc
  src/libmess/trajectory.cc
  src/libmess/units.cc
)

add_library(messlibs ${MESS_SOURCES})

add_executable(mess ${PROJECT_SOURCE_DIR}/src/mess_driver.cc)
add_executable(mess-v2 ${PROJECT_SOURCE_DIR}/src/mess_test.cc)
add_executable(messpf ${PROJECT_SOURCE_DIR}/src/partition_function.cc)
add_executable(messsym ${PROJECT_SOURCE_DIR}/src/gumbo.cc)

# Link executables
target_link_libraries(mess
    messlibs
    OpenMP::OpenMP_CXX
    ${BLAS_LIBRARIES}
    ${LAPACK_LIBRARIES}
    ${SLATEC}
    ${GSL_LIBRARIES}
    ${CMAKE_DL_LIBS}
)
target_link_libraries(mess-v2
    messlibs
    OpenMP::OpenMP_CXX
    ${BLAS_LIBRARIES}
    ${LAPACK_LIBRARIES}
    ${SLATEC}
    ${GSL_LIBRARIES}
    ${CMAKE_DL_LIBS}
)
target_link_libraries(messpf
    messlibs
    OpenMP::OpenMP_CXX
    ${BLAS_LIBRARIES}
    ${LAPACK_LIBRARIES}
    ${SLATEC}
    ${GSL_LIBRARIES}
    ${CMAKE_DL_LIBS}
)
target_link_libraries(messsym
    messlibs
    OpenMP::OpenMP_CXX
    ${BLAS_LIBRARIES}
    ${LAPACK_LIBRARIES}
    ${SLATEC}
    ${GSL_LIBRARIES}
    ${CMAKE_DL_LIBS}
)

install(TARGETS mess DESTINATION ${BINDIR})
install(TARGETS mess-v2 DESTINATION ${BINDIR})
install(TARGETS messpf DESTINATION ${BINDIR})
install(TARGETS messsym DESTINATION ${BINDIR})
install(TARGETS messlibs LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
