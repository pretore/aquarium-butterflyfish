cmake_minimum_required(VERSION 3.22)
project(aquarium-butterflyfish VERSION 1.0.0
        LANGUAGES C
        DESCRIPTION "Collection interfaces in C")

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
# Dependencies
set(CMAKE_THREAD_PREFER_PTHREAD TRUE)
set(THREADS_PREFER_PTHREAD_FLAG TRUE)
find_package(Threads REQUIRED)
find_package(Doxygen OPTIONAL_COMPONENTS dot mscgen dia)
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    include(cmake/FetchAquariumCMocka.cmake)
endif()
include(cmake/FetchAquariumSeaUrchin.cmake)
include(cmake/FetchAquariumSeaTurtle.cmake)
include(cmake/FetchAquariumTriggerfish.cmake)

# Sources
set(EXPORTED_HEADER_FILES
        include/butterflyfish/collection_i.h
        include/butterflyfish/collection_i_i.h
        include/butterflyfish/fixed_list_i.h
        include/butterflyfish/list_i.h
        include/butterflyfish/map_entry_i_i.h
        include/butterflyfish/map_i_i.h
        include/butterflyfish/ordered_map_i_i.h
        include/butterflyfish/ordered_set_i.h
        include/butterflyfish/queue_i.h
        include/butterflyfish/reducible_list_i.h
        include/butterflyfish/set_i.h
        include/butterflyfish/sorted_map_i_i.h
        include/butterflyfish/sorted_set_i.h
        include/butterflyfish/stack_i.h
        include/butterflyfish/stream_i.h
        include/butterflyfish/stream_i_i.h
        include/butterflyfish.h)
set(SOURCES
        ${EXPORTED_HEADER_FILES}
        src/butterflyfish.c
        src/collection_i.c
        src/collection_i_i.c
        src/fixed_list_i.c
        src/list_i.c
        src/map_entry_i_i.c
        src/map_i_i.c
        src/ordered_map_i_i.c
        src/ordered_set_i.c
        src/queue_i.c
        src/reducible_list_i.c
        src/set_i.c
        src/sorted_map_i_i.c
        src/sorted_set_i.c
        src/stack_i.c
        src/stream_i.c
        src/stream_i_i.c)

if (DOXYGEN_FOUND)
    set(DOXYGEN_EXTRACT_ALL YES)
    doxygen_add_docs(${PROJECT_NAME}-documentation
            ${EXPORTED_HEADER_FILES})
endif ()

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    include(CTest)
    add_library(${PROJECT_NAME} STATIC "")
    add_compile_definitions(TEST)
    target_sources(${PROJECT_NAME}
            PRIVATE
                ${SOURCES})
    target_link_libraries(${PROJECT_NAME}
            PUBLIC
                ${CMAKE_THREAD_LIBS_INIT}
                aquarium-cmocka
                aquarium-sea-urchin
                aquarium-sea-turtle
                aquarium-triggerfish)
    target_include_directories(${PROJECT_NAME}
            PUBLIC
                "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
                "$<INSTALL_INTERFACE:$<INSTALL_PREFIX>/${CMAKE_INSTALL_INCLUDEDIR}>")
    # Unit Tests
    enable_testing()
    # aquarium-butterflyfish-unit-test
    add_executable(${PROJECT_NAME}-unit-test test/test_butterflyfish.c)
    target_include_directories(${PROJECT_NAME}-unit-test
            PRIVATE
                "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>")
    target_link_libraries(${PROJECT_NAME}-unit-test
            PRIVATE
                ${PROJECT_NAME})
    add_test(${PROJECT_NAME}-unit-test ${PROJECT_NAME}-unit-test)
    # aquarium-butterflyfish-stream-i-unit-test
    add_executable(${PROJECT_NAME}-stream-i-unit-test test/test_stream_i.c)
    target_include_directories(${PROJECT_NAME}-stream-i-unit-test
            PRIVATE
                "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>")
    target_link_libraries(${PROJECT_NAME}-stream-i-unit-test
            PRIVATE
                ${PROJECT_NAME})
    add_test(${PROJECT_NAME}-stream-i-unit-test
            ${PROJECT_NAME}-stream-i-unit-test)
    # aquarium-butterflyfish-collection-i-unit-test
    add_executable(${PROJECT_NAME}-collection-i-unit-test
            test/test_collection_i.c)
    target_include_directories(${PROJECT_NAME}-collection-i-unit-test
            PRIVATE
                "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>")
    target_link_libraries(${PROJECT_NAME}-collection-i-unit-test
            PRIVATE
                ${PROJECT_NAME})
    add_test(${PROJECT_NAME}-collection-i-unit-test
            ${PROJECT_NAME}-collection-i-unit-test)
    # aquarium-butterflyfish-set-i-unit-test
    add_executable(${PROJECT_NAME}-set-i-unit-test test/test_set_i.c)
    target_include_directories(${PROJECT_NAME}-set-i-unit-test
            PRIVATE
                "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>")
    target_link_libraries(${PROJECT_NAME}-set-i-unit-test
            PRIVATE
                ${PROJECT_NAME})
    add_test(${PROJECT_NAME}-set-i-unit-test ${PROJECT_NAME}-set-i-unit-test)
    # aquarium-butterflyfish-ordered-set-i-unit-test
    add_executable(${PROJECT_NAME}-ordered-set-i-unit-test
            test/test_ordered_set_i.c)
    target_include_directories(${PROJECT_NAME}-ordered-set-i-unit-test
            PRIVATE
                "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>")
    target_link_libraries(${PROJECT_NAME}-ordered-set-i-unit-test
            PRIVATE
                ${PROJECT_NAME})
    add_test(${PROJECT_NAME}-ordered-set-i-unit-test
            ${PROJECT_NAME}-ordered-set-i-unit-test)
    # aquarium-butterflyfish-sorted-set-i-unit-test
    add_executable(${PROJECT_NAME}-sorted-set-i-unit-test
            test/test_sorted_set_i.c)
    target_include_directories(${PROJECT_NAME}-sorted-set-i-unit-test
            PRIVATE
                "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>")
    target_link_libraries(${PROJECT_NAME}-sorted-set-i-unit-test
            PRIVATE
                ${PROJECT_NAME})
    add_test(${PROJECT_NAME}-sorted-set-i-unit-test
            ${PROJECT_NAME}-sorted-set-i-unit-test)
    # aquarium-butterflyfish-fixed-list-i-unit-test
    add_executable(${PROJECT_NAME}-fixed-list-i-unit-test
            test/test_fixed_list_i.c)
    target_include_directories(${PROJECT_NAME}-fixed-list-i-unit-test
            PRIVATE
                "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>")
    target_link_libraries(${PROJECT_NAME}-fixed-list-i-unit-test
            PRIVATE
                ${PROJECT_NAME})
    add_test(${PROJECT_NAME}-fixed-list-i-unit-test
            ${PROJECT_NAME}-fixed-list-i-unit-test)
    # aquarium-butterflyfish-reducible-list-i-unit-test
    add_executable(${PROJECT_NAME}-reducible-list-i-unit-test
            test/test_reducible_list_i.c)
    target_include_directories(${PROJECT_NAME}-reducible-list-i-unit-test
            PRIVATE
                "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>")
    target_link_libraries(${PROJECT_NAME}-reducible-list-i-unit-test
            PRIVATE
                ${PROJECT_NAME})
    add_test(${PROJECT_NAME}-reducible-list-i-unit-test
            ${PROJECT_NAME}-reducible-list-i-unit-test)
    # aquarium-butterflyfish-list-i-unit-test
    add_executable(${PROJECT_NAME}-list-i-unit-test test/test_list_i.c)
    target_include_directories(${PROJECT_NAME}-list-i-unit-test
            PRIVATE
                "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>")
    target_link_libraries(${PROJECT_NAME}-list-i-unit-test
            PRIVATE
                ${PROJECT_NAME})
    add_test(${PROJECT_NAME}-list-i-unit-test ${PROJECT_NAME}-list-i-unit-test)
    # aquarium-butterflyfish-stream-i-i-unit-test
    add_executable(${PROJECT_NAME}-stream-i-i-unit-test
            test/test_stream_i_i.c)
    target_include_directories(${PROJECT_NAME}-stream-i-i-unit-test
            PRIVATE
                "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>")
    target_link_libraries(${PROJECT_NAME}-stream-i-i-unit-test
            PRIVATE
                ${PROJECT_NAME})
    add_test(${PROJECT_NAME}-stream-i-i-unit-test
            ${PROJECT_NAME}-stream-i-i-unit-test)
    # aquarium-butterflyfish-collection-i-i-unit-test
    add_executable(${PROJECT_NAME}-collection-i-i-unit-test
            test/test_collection_i_i.c)
    target_include_directories(${PROJECT_NAME}-collection-i-i-unit-test
            PRIVATE
                "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>")
    target_link_libraries(${PROJECT_NAME}-collection-i-i-unit-test
            PRIVATE
                ${PROJECT_NAME})
    add_test(${PROJECT_NAME}-collection-i-i-unit-test
            ${PROJECT_NAME}-collection-i-i-unit-test)
    # aquarium-butterflyfish-map-i-i-unit-test
    add_executable(${PROJECT_NAME}-map-i-i-unit-test
            test/test_map_i_i.c)
    target_include_directories(${PROJECT_NAME}-map-i-i-unit-test
            PRIVATE
                "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>")
    target_link_libraries(${PROJECT_NAME}-map-i-i-unit-test
            PRIVATE
                ${PROJECT_NAME})
    add_test(${PROJECT_NAME}-map-i-i-unit-test
            ${PROJECT_NAME}-map-i-i-unit-test)
    # aquarium-butterflyfish-map-entry-i-i-unit-test
    add_executable(${PROJECT_NAME}-map-entry-i-i-unit-test
            test/test_map_entry_i_i.c)
    target_include_directories(${PROJECT_NAME}-map-entry-i-i-unit-test
            PRIVATE
                "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>")
    target_link_libraries(${PROJECT_NAME}-map-entry-i-i-unit-test
            PRIVATE
                ${PROJECT_NAME})
    add_test(${PROJECT_NAME}-map-entry-i-i-unit-test
            ${PROJECT_NAME}-map-entry-i-i-unit-test)
    # aquarium-butterflyfish-ordered-map-i-i-unit-test
    add_executable(${PROJECT_NAME}-ordered-map-i-i-unit-test
            test/test_ordered_map_i_i.c)
    target_include_directories(${PROJECT_NAME}-ordered-map-i-i-unit-test
            PRIVATE
                "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>")
    target_link_libraries(${PROJECT_NAME}-ordered-map-i-i-unit-test
            PRIVATE
                ${PROJECT_NAME})
    add_test(${PROJECT_NAME}-ordered-map-i-i-unit-test
            ${PROJECT_NAME}-ordered-map-i-i-unit-test)
    # aquarium-butterflyfish-sorted-map-i-i-unit-test
    add_executable(${PROJECT_NAME}-sorted-map-i-i-unit-test
            test/test_sorted_map_i_i.c)
    target_include_directories(${PROJECT_NAME}-sorted-map-i-i-unit-test
            PRIVATE
                "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>")
    target_link_libraries(${PROJECT_NAME}-sorted-map-i-i-unit-test
            PRIVATE
                ${PROJECT_NAME})
    add_test(${PROJECT_NAME}-sorted-map-i-i-unit-test
            ${PROJECT_NAME}-sorted-map-i-i-unit-test)
    # aquarium-butterflyfish-queue-i-unit-test
    add_executable(${PROJECT_NAME}-queue-i-unit-test test/test_queue_i.c)
    target_include_directories(${PROJECT_NAME}-queue-i-unit-test
            PRIVATE
                "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>")
    target_link_libraries(${PROJECT_NAME}-queue-i-unit-test
            PRIVATE
                ${PROJECT_NAME})
    add_test(${PROJECT_NAME}-queue-i-unit-test
            ${PROJECT_NAME}-queue-i-unit-test)
    # aquarium-butterflyfish-stack-i-unit-test
    add_executable(${PROJECT_NAME}-stack-i-unit-test test/test_stack_i.c)
    target_include_directories(${PROJECT_NAME}-stack-i-unit-test
            PRIVATE
                "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>")
    target_link_libraries(${PROJECT_NAME}-stack-i-unit-test
            PRIVATE
                ${PROJECT_NAME})
    add_test(${PROJECT_NAME}-stack-i-unit-test
            ${PROJECT_NAME}-stack-i-unit-test)
else ()
    add_library(${PROJECT_NAME} "")
    target_sources(${PROJECT_NAME}
            PRIVATE
                ${SOURCES})
    target_include_directories(${PROJECT_NAME}
            PUBLIC
                "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
                "$<INSTALL_INTERFACE:$<INSTALL_PREFIX>/${CMAKE_INSTALL_INCLUDEDIR}>")
    target_link_libraries(${PROJECT_NAME}
            PUBLIC
                ${CMAKE_THREAD_LIBS_INIT}
                aquarium-sea-urchin
                aquarium-sea-turtle
                aquarium-triggerfish)
    set_target_properties(${PROJECT_NAME}
            PROPERTIES
                VERSION ${PROJECT_VERSION}
                SOVERSION ${PROJECT_VERSION_MAJOR})
    include(GNUInstallDirs)
    install(DIRECTORY include/
            DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
    install(TARGETS ${PROJECT_NAME}
            LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
    configure_file(${PROJECT_NAME}.pc.in ${PROJECT_NAME}.pc @ONLY)
    install(FILES ${CMAKE_BINARY_DIR}/${PROJECT_NAME}.pc
            DESTINATION ${CMAKE_INSTALL_LIBDIR}/pkgconfig)
endif ()
