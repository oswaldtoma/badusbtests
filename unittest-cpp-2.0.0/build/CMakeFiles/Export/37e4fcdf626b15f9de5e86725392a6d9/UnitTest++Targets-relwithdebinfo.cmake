#----------------------------------------------------------------
# Generated CMake target import file for configuration "RelWithDebInfo".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "UnitTest++" for configuration "RelWithDebInfo"
set_property(TARGET UnitTest++ APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(UnitTest++ PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELWITHDEBINFO "CXX"
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/UnitTest++.lib"
  )

list(APPEND _cmake_import_check_targets UnitTest++ )
list(APPEND _cmake_import_check_files_for_UnitTest++ "${_IMPORT_PREFIX}/lib/UnitTest++.lib" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
