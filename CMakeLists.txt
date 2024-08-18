cmake_minimum_required(VERSION 3.10)

# Nombre del proyecto
project(GeoMadness)

# Establece el estándar de C++
set(CMAKE_CXX_STANDARD 17)

#Ruta a carpeta de SFML
set(SFML_DIR "${CMAKE_SOURCE_DIR}/libs/SFML")

# Agrega los directorios de encabezados
include_directories("${CMAKE_SOURCE_DIR}/include")
include_directories("${SFML_DIR}/include")


file(GLOB_RECURSE SOURCES "${CMAKE_SOURCE_DIR}/src/*.cpp")

# Configura el ejecutable
add_executable(${PROJECT_NAME} ${SOURCES})

# Vincula SFML
target_link_libraries(${PROJECT_NAME} 
    "${SFML_DIR}/lib/*.lib"
)

# Copia las DLLs necesarias
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    "${SFML_DIR}/bin" $<TARGET_FILE_DIR:${PROJECT_NAME}>
)