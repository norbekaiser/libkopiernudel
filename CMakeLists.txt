cmake_minimum_required(VERSION 3.0)
project(libkopiernudel)

set(CMAKE_CXX_STANDARD 14)


#add_compile_options()
#enable_testing()

file(GLOB_RECURSE PASTAS "kopiernudeln/*")
file(GLOB_RECURSE HEADERS "lib/inc/*")

list(LENGTH PASTAS PASTAS_SIZE)
message(STATUS "Found: ${PASTAS_SIZE} Kopiernudeln")

message(STATUS "Configuring Header Files")
foreach (header ${HEADERS})
    get_filename_component(header_filename "${header}" NAME)
    message(STATUS "Configuring" : ${header_filename})
    configure_file(${header} lib/inc/libkopiernudel/${header_filename})
endforeach ()

message(STATUS "Configuring CXX Files")
set(expression "")
foreach (pasta ${PASTAS})
    get_filename_component(pasta_name ${pasta} NAME_WE)
    message(STATUS "Kopiernudel verwusteln: " ${pasta_name})
    file(READ "${pasta}" kopiernudel)
    string(REPLACE "\"" "\\\"" kopiernudel "${kopiernudel}")
    string(REPLACE "\n" "\\n" kopiernudel "${kopiernudel}")
    string(APPEND expression ", kopiernudel(\"${pasta_name}\",\"${kopiernudel}\") \n")

endforeach ()
configure_file(lib/src/libkopiernudel/archive.cc.in lib/src/libkopiernudel/archive.cc @ONLY)


add_library(kopiernudel  ${CMAKE_CURRENT_BINARY_DIR}/lib/src/libkopiernudel/archive.cc)
#target_include_directories(kopiernudel PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/lib/inc)
target_include_directories(kopiernudel PUBLIC ${CMAKE_CURRENT_BINARY_DIR}/lib/inc)


add_subdirectory(src)



install(TARGETS kopiernudel EXPORT kopiernudelConfig
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
    RUNTIME DESTINATION lib
    INCLUDES DESTINATION include
        )

install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/lib/inc/libkopiernudel/kopiernudel.h DESTINATION include/libkopiernudel)
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/lib/inc/libkopiernudel/archive.hh DESTINATION include/libkopiernudel)
#install(EXPORT libkopiernudelnConfig DESTINATION share/libkopiernudel/cmake)

#export(TARGETS libkopiernudel FILE libkopiernudelnConfig.cmake)
