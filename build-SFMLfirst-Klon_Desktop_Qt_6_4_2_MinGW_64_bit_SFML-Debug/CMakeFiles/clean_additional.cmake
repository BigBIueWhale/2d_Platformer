# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\SFMLfirst_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\SFMLfirst_autogen.dir\\ParseCache.txt"
  "SFMLfirst_autogen"
  )
endif()
