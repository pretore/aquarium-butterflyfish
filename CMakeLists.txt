cmake_minimum_required(VERSION 3.22)
project(aquarium-butterflyfish VERSION 3.1.0
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
        include/butterflyfish/collection_ni.h
        include/butterflyfish/collection_p.h
        include/butterflyfish/collection_s.h
        include/butterflyfish/collection_sr.h
        include/butterflyfish/collection_wr.h
        include/butterflyfish/collection_i_i.h
        include/butterflyfish/collection_ni_ni.h
        include/butterflyfish/collection_p_p.h
        include/butterflyfish/collection_s_s.h
        include/butterflyfish/collection_sr_sr.h
        include/butterflyfish/fixed_list_i.h
        include/butterflyfish/fixed_list_ni.h
        include/butterflyfish/fixed_list_p.h
        include/butterflyfish/fixed_list_s.h
        include/butterflyfish/fixed_list_sr.h
        include/butterflyfish/fixed_list_wr.h
        include/butterflyfish/list_i.h
        include/butterflyfish/list_ni.h
        include/butterflyfish/list_p.h
        include/butterflyfish/list_s.h
        include/butterflyfish/list_sr.h
        include/butterflyfish/list_wr.h
        include/butterflyfish/map_entry_i_i.h
        include/butterflyfish/map_entry_ni_ni.h
        include/butterflyfish/map_entry_p_p.h
        include/butterflyfish/map_entry_s_s.h
        include/butterflyfish/map_entry_sr_sr.h
        include/butterflyfish/map_i_i.h
        include/butterflyfish/map_ni_ni.h
        include/butterflyfish/map_p_p.h
        include/butterflyfish/map_s_s.h
        include/butterflyfish/map_sr_sr.h
        include/butterflyfish/ordered_map_i_i.h
        include/butterflyfish/ordered_map_ni_ni.h
        include/butterflyfish/ordered_map_p_p.h
        include/butterflyfish/ordered_map_s_s.h
        include/butterflyfish/ordered_map_sr_sr.h
        include/butterflyfish/ordered_set_i.h
        include/butterflyfish/ordered_set_ni.h
        include/butterflyfish/ordered_set_p.h
        include/butterflyfish/ordered_set_s.h
        include/butterflyfish/ordered_set_sr.h
        include/butterflyfish/queue_i.h
        include/butterflyfish/queue_ni.h
        include/butterflyfish/queue_p.h
        include/butterflyfish/queue_s.h
        include/butterflyfish/queue_sr.h
        include/butterflyfish/queue_wr.h
        include/butterflyfish/reducible_list_i.h
        include/butterflyfish/reducible_list_ni.h
        include/butterflyfish/reducible_list_p.h
        include/butterflyfish/reducible_list_s.h
        include/butterflyfish/reducible_list_sr.h
        include/butterflyfish/reducible_list_wr.h
        include/butterflyfish/reducible_queue_i.h
        include/butterflyfish/reducible_queue_ni.h
        include/butterflyfish/reducible_queue_p.h
        include/butterflyfish/reducible_queue_s.h
        include/butterflyfish/reducible_queue_sr.h
        include/butterflyfish/reducible_queue_wr.h
        include/butterflyfish/reducible_stack_i.h
        include/butterflyfish/reducible_stack_ni.h
        include/butterflyfish/reducible_stack_p.h
        include/butterflyfish/reducible_stack_s.h
        include/butterflyfish/reducible_stack_sr.h
        include/butterflyfish/reducible_stack_wr.h
        include/butterflyfish/set_i.h
        include/butterflyfish/set_ni.h
        include/butterflyfish/set_p.h
        include/butterflyfish/set_s.h
        include/butterflyfish/set_sr.h
        include/butterflyfish/sorted_map_i_i.h
        include/butterflyfish/sorted_map_ni_ni.h
        include/butterflyfish/sorted_map_p_p.h
        include/butterflyfish/sorted_map_s_s.h
        include/butterflyfish/sorted_map_sr_sr.h
        include/butterflyfish/sorted_set_i.h
        include/butterflyfish/sorted_set_ni.h
        include/butterflyfish/sorted_set_p.h
        include/butterflyfish/sorted_set_s.h
        include/butterflyfish/sorted_set_sr.h
        include/butterflyfish/stack_i.h
        include/butterflyfish/stack_ni.h
        include/butterflyfish/stack_p.h
        include/butterflyfish/stack_s.h
        include/butterflyfish/stack_sr.h
        include/butterflyfish/stack_wr.h
        include/butterflyfish/stream_i.h
        include/butterflyfish/stream_ni.h
        include/butterflyfish/stream_p.h
        include/butterflyfish/stream_s.h
        include/butterflyfish/stream_sr.h
        include/butterflyfish/stream_wr.h
        include/butterflyfish/stream_i_i.h
        include/butterflyfish/stream_ni_ni.h
        include/butterflyfish/stream_p_p.h
        include/butterflyfish/stream_s_s.h
        include/butterflyfish/stream_sr_sr.h
        include/butterflyfish.h)
set(SOURCES
        ${EXPORTED_HEADER_FILES}
        src/butterflyfish.c
        src/collection_i.c
        src/collection_ni.c
        src/collection_p.c
        src/collection_s.c
        src/collection_sr.c
        src/collection_wr.c
        src/collection_i_i.c
        src/collection_ni_ni.c
        src/collection_p_p.c
        src/collection_s_s.c
        src/collection_sr_sr.c
        src/fixed_list_i.c
        src/fixed_list_ni.c
        src/fixed_list_p.c
        src/fixed_list_s.c
        src/fixed_list_sr.c
        src/fixed_list_wr.c
        src/list_i.c
        src/list_ni.c
        src/list_p.c
        src/list_s.c
        src/list_sr.c
        src/list_wr.c
        src/map_i_i.c
        src/map_ni_ni.c
        src/map_p_p.c
        src/map_s_s.c
        src/map_sr_sr.c
        src/ordered_map_i_i.c
        src/ordered_map_ni_ni.c
        src/ordered_map_p_p.c
        src/ordered_map_s_s.c
        src/ordered_map_sr_sr.c
        src/ordered_set_i.c
        src/ordered_set_ni.c
        src/ordered_set_p.c
        src/ordered_set_s.c
        src/ordered_set_sr.c
        src/queue_i.c
        src/queue_ni.c
        src/queue_p.c
        src/queue_s.c
        src/queue_sr.c
        src/queue_wr.c
        src/reducible_list_i.c
        src/reducible_list_ni.c
        src/reducible_list_p.c
        src/reducible_list_s.c
        src/reducible_list_sr.c
        src/reducible_list_wr.c
        src/reducible_queue_i.c
        src/reducible_queue_ni.c
        src/reducible_queue_p.c
        src/reducible_queue_s.c
        src/reducible_queue_sr.c
        src/reducible_queue_wr.c
        src/reducible_stack_i.c
        src/reducible_stack_ni.c
        src/reducible_stack_p.c
        src/reducible_stack_s.c
        src/reducible_stack_sr.c
        src/reducible_stack_wr.c
        src/set_i.c
        src/set_ni.c
        src/set_p.c
        src/set_s.c
        src/set_sr.c
        src/sorted_map_i_i.c
        src/sorted_map_ni_ni.c
        src/sorted_map_p_p.c
        src/sorted_map_s_s.c
        src/sorted_map_sr_sr.c
        src/sorted_set_i.c
        src/sorted_set_ni.c
        src/sorted_set_p.c
        src/sorted_set_s.c
        src/sorted_set_sr.c
        src/stack_i.c
        src/stack_ni.c
        src/stack_p.c
        src/stack_s.c
        src/stack_sr.c
        src/stack_wr.c
        src/stream_i.c
        src/stream_ni.c
        src/stream_p.c
        src/stream_s.c
        src/stream_sr.c
        src/stream_wr.c
        src/stream_i_i.c
        src/stream_ni_ni.c
        src/stream_p_p.c
        src/stream_s_s.c
        src/stream_sr_sr.c)

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
    # aquarium-butterflyfish-reducible-queue-i-unit-test
    add_executable(${PROJECT_NAME}-reducible-queue-i-unit-test
            test/test_reducible_queue_i.c)
    target_include_directories(${PROJECT_NAME}-reducible-queue-i-unit-test
            PRIVATE
                "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>")
    target_link_libraries(${PROJECT_NAME}-reducible-queue-i-unit-test
            PRIVATE
                ${PROJECT_NAME})
    add_test(${PROJECT_NAME}-reducible-queue-i-unit-test
            ${PROJECT_NAME}-reducible-queue-i-unit-test)
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
    # aquarium-butterflyfish-reducible-stack-i-unit-test
    add_executable(${PROJECT_NAME}-reducible-stack-i-unit-test
            test/test_reducible_stack_i.c)
    target_include_directories(${PROJECT_NAME}-reducible-stack-i-unit-test
            PRIVATE
                "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>")
    target_link_libraries(${PROJECT_NAME}-reducible-stack-i-unit-test
            PRIVATE
            ${PROJECT_NAME})
    add_test(${PROJECT_NAME}-reducible-stack-i-unit-test
            ${PROJECT_NAME}-reducible-stack-i-unit-test)
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
    # aquarium-butterflyfish-stream-s-unit-test
    add_executable(${PROJECT_NAME}-stream-s-unit-test test/test_stream_s.c)
    target_include_directories(${PROJECT_NAME}-stream-s-unit-test
            PRIVATE
                "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>")
    target_link_libraries(${PROJECT_NAME}-stream-s-unit-test
            PRIVATE
                ${PROJECT_NAME})
    add_test(${PROJECT_NAME}-stream-s-unit-test
            ${PROJECT_NAME}-stream-s-unit-test)
    # aquarium-butterflyfish-collection-s-unit-test
    add_executable(${PROJECT_NAME}-collection-s-unit-test
            test/test_collection_s.c)
    target_include_directories(${PROJECT_NAME}-collection-s-unit-test
            PRIVATE
                "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>")
    target_link_libraries(${PROJECT_NAME}-collection-s-unit-test
            PRIVATE
                ${PROJECT_NAME})
    add_test(${PROJECT_NAME}-collection-s-unit-test
            ${PROJECT_NAME}-collection-s-unit-test)
    # aquarium-butterflyfish-set-s-unit-test
    add_executable(${PROJECT_NAME}-set-s-unit-test test/test_set_s.c)
    target_include_directories(${PROJECT_NAME}-set-s-unit-test
            PRIVATE
                "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>")
    target_link_libraries(${PROJECT_NAME}-set-s-unit-test
            PRIVATE
                ${PROJECT_NAME})
    add_test(${PROJECT_NAME}-set-s-unit-test ${PROJECT_NAME}-set-s-unit-test)
    # aquarium-butterflyfish-ordered-set-s-unit-test
    add_executable(${PROJECT_NAME}-ordered-set-s-unit-test
                test/test_ordered_set_s.c)
    target_include_directories(${PROJECT_NAME}-ordered-set-s-unit-test
            PRIVATE
                "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>")
    target_link_libraries(${PROJECT_NAME}-ordered-set-s-unit-test
            PRIVATE
                ${PROJECT_NAME})
    add_test(${PROJECT_NAME}-ordered-set-s-unit-test
            ${PROJECT_NAME}-ordered-set-s-unit-test)
    # aquarium-butterflyfish-sorted-set-s-unit-test
    add_executable(${PROJECT_NAME}-sorted-set-s-unit-test
            test/test_sorted_set_s.c)
    target_include_directories(${PROJECT_NAME}-sorted-set-s-unit-test
            PRIVATE
                "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>")
    target_link_libraries(${PROJECT_NAME}-sorted-set-s-unit-test
            PRIVATE
                ${PROJECT_NAME})
    add_test(${PROJECT_NAME}-sorted-set-s-unit-test
            ${PROJECT_NAME}-sorted-set-s-unit-test)
    # aquarium-butterflyfish-fixed-list-s-unit-test
    add_executable(${PROJECT_NAME}-fixed-list-s-unit-test
            test/test_fixed_list_s.c)
    target_include_directories(${PROJECT_NAME}-fixed-list-s-unit-test
            PRIVATE
                "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>")
    target_link_libraries(${PROJECT_NAME}-fixed-list-s-unit-test
            PRIVATE
                ${PROJECT_NAME})
    add_test(${PROJECT_NAME}-fixed-list-s-unit-test
            ${PROJECT_NAME}-fixed-list-s-unit-test)
    # aquarium-butterflyfish-reducible-list-s-unit-test
    add_executable(${PROJECT_NAME}-reducible-list-s-unit-test
            test/test_reducible_list_s.c)
    target_include_directories(${PROJECT_NAME}-reducible-list-s-unit-test
            PRIVATE
                "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>")
    target_link_libraries(${PROJECT_NAME}-reducible-list-s-unit-test
            PRIVATE
            ${PROJECT_NAME})
    add_test(${PROJECT_NAME}-reducible-list-s-unit-test
            ${PROJECT_NAME}-reducible-list-s-unit-test)
    # aquarium-butterflyfish-list-s-unit-test
    add_executable(${PROJECT_NAME}-list-s-unit-test test/test_list_s.c)
    target_include_directories(${PROJECT_NAME}-list-s-unit-test
            PRIVATE
                "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>")
    target_link_libraries(${PROJECT_NAME}-list-s-unit-test
            PRIVATE
                ${PROJECT_NAME})
    add_test(${PROJECT_NAME}-list-s-unit-test ${PROJECT_NAME}-list-s-unit-test)
    # aquarium-butterflyfish-stream-s-s-unit-test
    add_executable(${PROJECT_NAME}-stream-s-s-unit-test
            test/test_stream_s_s.c)
    target_include_directories(${PROJECT_NAME}-stream-s-s-unit-test
            PRIVATE
                "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>")
    target_link_libraries(${PROJECT_NAME}-stream-s-s-unit-test
            PRIVATE
                ${PROJECT_NAME})
    add_test(${PROJECT_NAME}-stream-s-s-unit-test
            ${PROJECT_NAME}-stream-s-s-unit-test)
    # aquarium-butterflyfish-collection-s-s-unit-test
    add_executable(${PROJECT_NAME}-collection-s-s-unit-test
            test/test_collection_s_s.c)
    target_include_directories(${PROJECT_NAME}-collection-s-s-unit-test
            PRIVATE
                "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>")
    target_link_libraries(${PROJECT_NAME}-collection-s-s-unit-test
            PRIVATE
                ${PROJECT_NAME})
    add_test(${PROJECT_NAME}-collection-s-s-unit-test
            ${PROJECT_NAME}-collection-s-s-unit-test)
    # aquarium-butterflyfish-map-s-s-unit-test
    add_executable(${PROJECT_NAME}-map-s-s-unit-test
            test/test_map_s_s.c)
    target_include_directories(${PROJECT_NAME}-map-s-s-unit-test
            PRIVATE
                "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>")
    target_link_libraries(${PROJECT_NAME}-map-s-s-unit-test
            PRIVATE
                ${PROJECT_NAME})
    add_test(${PROJECT_NAME}-map-s-s-unit-test
            ${PROJECT_NAME}-map-s-s-unit-test)
    # aquarium-butterflyfish-ordered-map-s-s-unit-test
    add_executable(${PROJECT_NAME}-ordered-map-s-s-unit-test
            test/test_ordered_map_s_s.c)
    target_include_directories(${PROJECT_NAME}-ordered-map-s-s-unit-test
            PRIVATE
            "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>")
    target_link_libraries(${PROJECT_NAME}-ordered-map-s-s-unit-test
            PRIVATE
                ${PROJECT_NAME})
    add_test(${PROJECT_NAME}-ordered-map-s-s-unit-test
            ${PROJECT_NAME}-ordered-map-s-s-unit-test)
    # aquarium-butterflyfish-sorted-map-s-s-unit-test
    add_executable(${PROJECT_NAME}-sorted-map-s-s-unit-test
            test/test_sorted_map_s_s.c)
    target_include_directories(${PROJECT_NAME}-sorted-map-s-s-unit-test
            PRIVATE
                "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>")
    target_link_libraries(${PROJECT_NAME}-sorted-map-s-s-unit-test
            PRIVATE
                ${PROJECT_NAME})
    add_test(${PROJECT_NAME}-sorted-map-s-s-unit-test
            ${PROJECT_NAME}-sorted-map-s-s-unit-test)
    # aquarium-butterflyfish-reducible-queue-s-unit-test
    add_executable(${PROJECT_NAME}-reducible-queue-s-unit-test
            test/test_reducible_queue_s.c)
    target_include_directories(${PROJECT_NAME}-reducible-queue-s-unit-test
            PRIVATE
                "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>")
    target_link_libraries(${PROJECT_NAME}-reducible-queue-s-unit-test
            PRIVATE
                ${PROJECT_NAME})
    add_test(${PROJECT_NAME}-reducible-queue-s-unit-test
            ${PROJECT_NAME}-reducible-queue-s-unit-test)
    # aquarium-butterflyfish-queue-s-unit-test
    add_executable(${PROJECT_NAME}-queue-s-unit-test test/test_queue_s.c)
    target_include_directories(${PROJECT_NAME}-queue-s-unit-test
            PRIVATE
                "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>")
    target_link_libraries(${PROJECT_NAME}-queue-s-unit-test
            PRIVATE
                ${PROJECT_NAME})
    add_test(${PROJECT_NAME}-queue-s-unit-test
            ${PROJECT_NAME}-queue-s-unit-test)
    # aquarium-butterflyfish-reducible-stack-s-unit-test
    add_executable(${PROJECT_NAME}-reducible-stack-s-unit-test
            test/test_reducible_stack_s.c)
    target_include_directories(${PROJECT_NAME}-reducible-stack-s-unit-test
            PRIVATE
            "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>")
    target_link_libraries(${PROJECT_NAME}-reducible-stack-s-unit-test
            PRIVATE
                ${PROJECT_NAME})
    add_test(${PROJECT_NAME}-reducible-stack-s-unit-test
            ${PROJECT_NAME}-reducible-stack-s-unit-test)
    # aquarium-butterflyfish-stack-s-unit-test
    add_executable(${PROJECT_NAME}-stack-s-unit-test test/test_stack_s.c)
    target_include_directories(${PROJECT_NAME}-stack-s-unit-test
            PRIVATE
                "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>")
    target_link_libraries(${PROJECT_NAME}-stack-s-unit-test
            PRIVATE
                ${PROJECT_NAME})
    add_test(${PROJECT_NAME}-stack-s-unit-test
            ${PROJECT_NAME}-stack-s-unit-test)
    # aquarium-butterflyfish-stream-ni-unit-test
    add_executable(${PROJECT_NAME}-stream-ni-unit-test test/test_stream_ni.c)
    target_include_directories(${PROJECT_NAME}-stream-ni-unit-test
            PRIVATE
                "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>")
    target_link_libraries(${PROJECT_NAME}-stream-ni-unit-test
            PRIVATE
                ${PROJECT_NAME})
    add_test(${PROJECT_NAME}-stream-ni-unit-test
            ${PROJECT_NAME}-stream-ni-unit-test)
    # aquarium-butterflyfish-collection-ni-unit-test
    add_executable(${PROJECT_NAME}-collection-ni-unit-test
            test/test_collection_ni.c)
    target_include_directories(${PROJECT_NAME}-collection-ni-unit-test
            PRIVATE
                "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>")
    target_link_libraries(${PROJECT_NAME}-collection-ni-unit-test
            PRIVATE
                ${PROJECT_NAME})
    add_test(${PROJECT_NAME}-collection-ni-unit-test
            ${PROJECT_NAME}-collection-ni-unit-test)
    # aquarium-butterflyfish-set-ni-unit-test
    add_executable(${PROJECT_NAME}-set-ni-unit-test test/test_set_ni.c)
    target_include_directories(${PROJECT_NAME}-set-ni-unit-test
            PRIVATE
                "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>")
    target_link_libraries(${PROJECT_NAME}-set-ni-unit-test
            PRIVATE
                ${PROJECT_NAME})
    add_test(${PROJECT_NAME}-set-ni-unit-test ${PROJECT_NAME}-set-ni-unit-test)
    # aquarium-butterflyfish-ordered-set-ni-unit-test
    add_executable(${PROJECT_NAME}-ordered-set-ni-unit-test
            test/test_ordered_set_ni.c)
    target_include_directories(${PROJECT_NAME}-ordered-set-ni-unit-test
            PRIVATE
                "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>")
    target_link_libraries(${PROJECT_NAME}-ordered-set-ni-unit-test
            PRIVATE
                ${PROJECT_NAME})
    add_test(${PROJECT_NAME}-ordered-set-ni-unit-test
            ${PROJECT_NAME}-ordered-set-ni-unit-test)
    # aquarium-butterflyfish-sorted-set-ni-unit-test
    add_executable(${PROJECT_NAME}-sorted-set-ni-unit-test
            test/test_sorted_set_ni.c)
    target_include_directories(${PROJECT_NAME}-sorted-set-ni-unit-test
            PRIVATE
                "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>")
    target_link_libraries(${PROJECT_NAME}-sorted-set-ni-unit-test
            PRIVATE
                ${PROJECT_NAME})
    add_test(${PROJECT_NAME}-sorted-set-ni-unit-test
            ${PROJECT_NAME}-sorted-set-ni-unit-test)
    # aquarium-butterflyfish-fixed-list-ni-unit-test
    add_executable(${PROJECT_NAME}-fixed-list-ni-unit-test
            test/test_fixed_list_ni.c)
    target_include_directories(${PROJECT_NAME}-fixed-list-ni-unit-test
            PRIVATE
                "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>")
    target_link_libraries(${PROJECT_NAME}-fixed-list-ni-unit-test
            PRIVATE
                ${PROJECT_NAME})
    add_test(${PROJECT_NAME}-fixed-list-ni-unit-test
            ${PROJECT_NAME}-fixed-list-ni-unit-test)
    # aquarium-butterflyfish-reducible-list-ni-unit-test
    add_executable(${PROJECT_NAME}-reducible-list-ni-unit-test
            test/test_reducible_list_ni.c)
    target_include_directories(${PROJECT_NAME}-reducible-list-ni-unit-test
            PRIVATE
                "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>")
    target_link_libraries(${PROJECT_NAME}-reducible-list-ni-unit-test
            PRIVATE
                ${PROJECT_NAME})
    add_test(${PROJECT_NAME}-reducible-list-ni-unit-test
            ${PROJECT_NAME}-reducible-list-ni-unit-test)
    # aquarium-butterflyfish-list-ni-unit-test
    add_executable(${PROJECT_NAME}-list-ni-unit-test test/test_list_ni.c)
    target_include_directories(${PROJECT_NAME}-list-ni-unit-test
            PRIVATE
                "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>")
    target_link_libraries(${PROJECT_NAME}-list-ni-unit-test
            PRIVATE
                ${PROJECT_NAME})
    add_test(${PROJECT_NAME}-list-ni-unit-test
            ${PROJECT_NAME}-list-ni-unit-test)
    # aquarium-butterflyfish-stream-ni-ni-unit-test
    add_executable(${PROJECT_NAME}-stream-ni-ni-unit-test
            test/test_stream_ni_ni.c)
    target_include_directories(${PROJECT_NAME}-stream-ni-ni-unit-test
            PRIVATE
                "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>")
    target_link_libraries(${PROJECT_NAME}-stream-ni-ni-unit-test
            PRIVATE
                ${PROJECT_NAME})
    add_test(${PROJECT_NAME}-stream-ni-ni-unit-test
            ${PROJECT_NAME}-stream-ni-ni-unit-test)
    # aquarium-butterflyfish-collection-ni-ni-unit-test
    add_executable(${PROJECT_NAME}-collection-ni-ni-unit-test
            test/test_collection_ni_ni.c)
    target_include_directories(${PROJECT_NAME}-collection-ni-ni-unit-test
            PRIVATE
                "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>")
    target_link_libraries(${PROJECT_NAME}-collection-ni-ni-unit-test
            PRIVATE
                ${PROJECT_NAME})
    add_test(${PROJECT_NAME}-collection-ni-ni-unit-test
            ${PROJECT_NAME}-collection-ni-ni-unit-test)
    # aquarium-butterflyfish-map-ni-ni-unit-test
    add_executable(${PROJECT_NAME}-map-ni-ni-unit-test
            test/test_map_ni_ni.c)
    target_include_directories(${PROJECT_NAME}-map-ni-ni-unit-test
            PRIVATE
                "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>")
    target_link_libraries(${PROJECT_NAME}-map-ni-ni-unit-test
            PRIVATE
                ${PROJECT_NAME})
    add_test(${PROJECT_NAME}-map-ni-ni-unit-test
            ${PROJECT_NAME}-map-ni-ni-unit-test)
    # aquarium-butterflyfish-ordered-map-ni-ni-unit-test
    add_executable(${PROJECT_NAME}-ordered-map-ni-ni-unit-test
            test/test_ordered_map_ni_ni.c)
    target_include_directories(${PROJECT_NAME}-ordered-map-ni-ni-unit-test
            PRIVATE
                "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>")
    target_link_libraries(${PROJECT_NAME}-ordered-map-ni-ni-unit-test
            PRIVATE
                ${PROJECT_NAME})
    add_test(${PROJECT_NAME}-ordered-map-ni-ni-unit-test
            ${PROJECT_NAME}-ordered-map-ni-ni-unit-test)
    # aquarium-butterflyfish-sorted-map-ni-ni-unit-test
    add_executable(${PROJECT_NAME}-sorted-map-ni-ni-unit-test
            test/test_sorted_map_ni_ni.c)
    target_include_directories(${PROJECT_NAME}-sorted-map-ni-ni-unit-test
            PRIVATE
                "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>")
    target_link_libraries(${PROJECT_NAME}-sorted-map-ni-ni-unit-test
            PRIVATE
                ${PROJECT_NAME})
    add_test(${PROJECT_NAME}-sorted-map-ni-ni-unit-test
            ${PROJECT_NAME}-sorted-map-ni-ni-unit-test)
    # aquarium-butterflyfish-reducible-queue-ni-unit-test
    add_executable(${PROJECT_NAME}-reducible-queue-ni-unit-test
            test/test_reducible_queue_ni.c)
    target_include_directories(${PROJECT_NAME}-reducible-queue-ni-unit-test
            PRIVATE
                "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>")
    target_link_libraries(${PROJECT_NAME}-reducible-queue-ni-unit-test
            PRIVATE
                ${PROJECT_NAME})
    add_test(${PROJECT_NAME}-reducible-queue-ni-unit-test
            ${PROJECT_NAME}-reducible-queue-ni-unit-test)
    # aquarium-butterflyfish-queue-ni-unit-test
    add_executable(${PROJECT_NAME}-queue-ni-unit-test test/test_queue_ni.c)
    target_include_directories(${PROJECT_NAME}-queue-ni-unit-test
            PRIVATE
                "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>")
    target_link_libraries(${PROJECT_NAME}-queue-ni-unit-test
            PRIVATE
                ${PROJECT_NAME})
    add_test(${PROJECT_NAME}-queue-ni-unit-test
            ${PROJECT_NAME}-queue-ni-unit-test)
    # aquarium-butterflyfish-reducible-stack-ni-unit-test
    add_executable(${PROJECT_NAME}-reducible-stack-ni-unit-test
            test/test_reducible_stack_ni.c)
    target_include_directories(${PROJECT_NAME}-reducible-stack-ni-unit-test
            PRIVATE
                "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>")
    target_link_libraries(${PROJECT_NAME}-reducible-stack-ni-unit-test
            PRIVATE
                ${PROJECT_NAME})
    add_test(${PROJECT_NAME}-reducible-stack-ni-unit-test
            ${PROJECT_NAME}-reducible-stack-ni-unit-test)
    # aquarium-butterflyfish-stack-ni-unit-test
    add_executable(${PROJECT_NAME}-stack-ni-unit-test test/test_stack_ni.c)
    target_include_directories(${PROJECT_NAME}-stack-ni-unit-test
            PRIVATE
                "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>")
    target_link_libraries(${PROJECT_NAME}-stack-ni-unit-test
            PRIVATE
                ${PROJECT_NAME})
    add_test(${PROJECT_NAME}-stack-ni-unit-test
            ${PROJECT_NAME}-stack-ni-unit-test)
    # aquarium-butterflyfish-stream-p-unit-test
    add_executable(${PROJECT_NAME}-stream-p-unit-test test/test_stream_p.c)
    target_include_directories(${PROJECT_NAME}-stream-p-unit-test
            PRIVATE
                "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>")
    target_link_libraries(${PROJECT_NAME}-stream-p-unit-test
            PRIVATE
                ${PROJECT_NAME})
    add_test(${PROJECT_NAME}-stream-p-unit-test
            ${PROJECT_NAME}-stream-p-unit-test)
    # aquarium-butterflyfish-collection-p-unit-test
    add_executable(${PROJECT_NAME}-collection-p-unit-test
            test/test_collection_p.c)
    target_include_directories(${PROJECT_NAME}-collection-p-unit-test
            PRIVATE
                "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>")
    target_link_libraries(${PROJECT_NAME}-collection-p-unit-test
            PRIVATE
                ${PROJECT_NAME})
    add_test(${PROJECT_NAME}-collection-p-unit-test
            ${PROJECT_NAME}-collection-p-unit-test)
    # aquarium-butterflyfish-set-p-unit-test
    add_executable(${PROJECT_NAME}-set-p-unit-test test/test_set_p.c)
    target_include_directories(${PROJECT_NAME}-set-p-unit-test
            PRIVATE
                "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>")
    target_link_libraries(${PROJECT_NAME}-set-p-unit-test
            PRIVATE
                ${PROJECT_NAME})
    add_test(${PROJECT_NAME}-set-p-unit-test ${PROJECT_NAME}-set-p-unit-test)
    # aquarium-butterflyfish-ordered-set-p-unit-test
    add_executable(${PROJECT_NAME}-ordered-set-p-unit-test
            test/test_ordered_set_p.c)
    target_include_directories(${PROJECT_NAME}-ordered-set-p-unit-test
            PRIVATE
            "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>")
    target_link_libraries(${PROJECT_NAME}-ordered-set-p-unit-test
            PRIVATE
                ${PROJECT_NAME})
    add_test(${PROJECT_NAME}-ordered-set-p-unit-test
            ${PROJECT_NAME}-ordered-set-p-unit-test)
    # aquarium-butterflyfish-sorted-set-p-unit-test
    add_executable(${PROJECT_NAME}-sorted-set-p-unit-test
            test/test_sorted_set_p.c)
    target_include_directories(${PROJECT_NAME}-sorted-set-p-unit-test
            PRIVATE
                "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>")
    target_link_libraries(${PROJECT_NAME}-sorted-set-p-unit-test
            PRIVATE
                ${PROJECT_NAME})
    add_test(${PROJECT_NAME}-sorted-set-p-unit-test
            ${PROJECT_NAME}-sorted-set-p-unit-test)
    # aquarium-butterflyfish-fixed-list-p-unit-test
    add_executable(${PROJECT_NAME}-fixed-list-p-unit-test
            test/test_fixed_list_p.c)
    target_include_directories(${PROJECT_NAME}-fixed-list-p-unit-test
            PRIVATE
                "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>")
    target_link_libraries(${PROJECT_NAME}-fixed-list-p-unit-test
            PRIVATE
                ${PROJECT_NAME})
    add_test(${PROJECT_NAME}-fixed-list-p-unit-test
            ${PROJECT_NAME}-fixed-list-p-unit-test)
    # aquarium-butterflyfish-reducible-list-p-unit-test
    add_executable(${PROJECT_NAME}-reducible-list-p-unit-test
            test/test_reducible_list_p.c)
    target_include_directories(${PROJECT_NAME}-reducible-list-p-unit-test
            PRIVATE
                "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>")
    target_link_libraries(${PROJECT_NAME}-reducible-list-p-unit-test
            PRIVATE
                ${PROJECT_NAME})
    add_test(${PROJECT_NAME}-reducible-list-p-unit-test
            ${PROJECT_NAME}-reducible-list-p-unit-test)
    # aquarium-butterflyfish-list-p-unit-test
    add_executable(${PROJECT_NAME}-list-p-unit-test test/test_list_p.c)
    target_include_directories(${PROJECT_NAME}-list-p-unit-test
            PRIVATE
                "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>")
    target_link_libraries(${PROJECT_NAME}-list-p-unit-test
            PRIVATE
                ${PROJECT_NAME})
    add_test(${PROJECT_NAME}-list-p-unit-test ${PROJECT_NAME}-list-p-unit-test)
    # aquarium-butterflyfish-stream-p-p-unit-test
    add_executable(${PROJECT_NAME}-stream-p-p-unit-test
            test/test_stream_p_p.c)
    target_include_directories(${PROJECT_NAME}-stream-p-p-unit-test
            PRIVATE
                "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>")
    target_link_libraries(${PROJECT_NAME}-stream-p-p-unit-test
            PRIVATE
                ${PROJECT_NAME})
    add_test(${PROJECT_NAME}-stream-p-p-unit-test
            ${PROJECT_NAME}-stream-p-p-unit-test)
    # aquarium-butterflyfish-collection-p-p-unit-test
    add_executable(${PROJECT_NAME}-collection-p-p-unit-test
            test/test_collection_p_p.c)
    target_include_directories(${PROJECT_NAME}-collection-p-p-unit-test
            PRIVATE
                "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>")
    target_link_libraries(${PROJECT_NAME}-collection-p-p-unit-test
            PRIVATE
                ${PROJECT_NAME})
    add_test(${PROJECT_NAME}-collection-p-p-unit-test
            ${PROJECT_NAME}-collection-p-p-unit-test)
    # aquarium-butterflyfish-map-p-p-unit-test
    add_executable(${PROJECT_NAME}-map-p-p-unit-test
            test/test_map_p_p.c)
    target_include_directories(${PROJECT_NAME}-map-p-p-unit-test
            PRIVATE
                "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>")
    target_link_libraries(${PROJECT_NAME}-map-p-p-unit-test
            PRIVATE
                ${PROJECT_NAME})
    add_test(${PROJECT_NAME}-map-p-p-unit-test
            ${PROJECT_NAME}-map-p-p-unit-test)
    # aquarium-butterflyfish-ordered-map-p-p-unit-test
    add_executable(${PROJECT_NAME}-ordered-map-p-p-unit-test
            test/test_ordered_map_p_p.c)
    target_include_directories(${PROJECT_NAME}-ordered-map-p-p-unit-test
            PRIVATE
                "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>")
    target_link_libraries(${PROJECT_NAME}-ordered-map-p-p-unit-test
            PRIVATE
                ${PROJECT_NAME})
    add_test(${PROJECT_NAME}-ordered-map-p-p-unit-test
            ${PROJECT_NAME}-ordered-map-p-p-unit-test)
    # aquarium-butterflyfish-sorted-map-p-p-unit-test
    add_executable(${PROJECT_NAME}-sorted-map-p-p-unit-test
            test/test_sorted_map_p_p.c)
    target_include_directories(${PROJECT_NAME}-sorted-map-p-p-unit-test
            PRIVATE
                "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>")
    target_link_libraries(${PROJECT_NAME}-sorted-map-p-p-unit-test
            PRIVATE
                ${PROJECT_NAME})
    add_test(${PROJECT_NAME}-sorted-map-p-p-unit-test
            ${PROJECT_NAME}-sorted-map-p-p-unit-test)
    # aquarium-butterflyfish-reducible-queue-p-unit-test
    add_executable(${PROJECT_NAME}-reducible-queue-p-unit-test
            test/test_reducible_queue_p.c)
    target_include_directories(${PROJECT_NAME}-reducible-queue-p-unit-test
            PRIVATE
                "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>")
    target_link_libraries(${PROJECT_NAME}-reducible-queue-p-unit-test
            PRIVATE
                ${PROJECT_NAME})
    add_test(${PROJECT_NAME}-reducible-queue-p-unit-test
            ${PROJECT_NAME}-reducible-queue-p-unit-test)
    # aquarium-butterflyfish-queue-p-unit-test
    add_executable(${PROJECT_NAME}-queue-p-unit-test test/test_queue_p.c)
    target_include_directories(${PROJECT_NAME}-queue-p-unit-test
            PRIVATE
                "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>")
    target_link_libraries(${PROJECT_NAME}-queue-p-unit-test
            PRIVATE
                ${PROJECT_NAME})
    add_test(${PROJECT_NAME}-queue-p-unit-test
            ${PROJECT_NAME}-queue-p-unit-test)
    # aquarium-butterflyfish-reducible-stack-p-unit-test
    add_executable(${PROJECT_NAME}-reducible-stack-p-unit-test
            test/test_reducible_stack_p.c)
    target_include_directories(${PROJECT_NAME}-reducible-stack-p-unit-test
            PRIVATE
                "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>")
    target_link_libraries(${PROJECT_NAME}-reducible-stack-p-unit-test
            PRIVATE
                ${PROJECT_NAME})
    add_test(${PROJECT_NAME}-reducible-stack-p-unit-test
            ${PROJECT_NAME}-reducible-stack-p-unit-test)
    # aquarium-butterflyfish-stack-p-unit-test
    add_executable(${PROJECT_NAME}-stack-p-unit-test test/test_stack_p.c)
    target_include_directories(${PROJECT_NAME}-stack-p-unit-test
            PRIVATE
                "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>")
    target_link_libraries(${PROJECT_NAME}-stack-p-unit-test
            PRIVATE
                ${PROJECT_NAME})
    add_test(${PROJECT_NAME}-stack-p-unit-test
            ${PROJECT_NAME}-stack-p-unit-test)
    # aquarium-butterflyfish-stream-sr-unit-test
    add_executable(${PROJECT_NAME}-stream-sr-unit-test test/test_stream_sr.c)
    target_include_directories(${PROJECT_NAME}-stream-sr-unit-test
            PRIVATE
                "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>")
    target_link_libraries(${PROJECT_NAME}-stream-sr-unit-test
            PRIVATE
                ${PROJECT_NAME})
    add_test(${PROJECT_NAME}-stream-sr-unit-test
            ${PROJECT_NAME}-stream-sr-unit-test)
    # aquarium-butterflyfish-collection-sr-unit-test
    add_executable(${PROJECT_NAME}-collection-sr-unit-test
            test/test_collection_sr.c)
    target_include_directories(${PROJECT_NAME}-collection-sr-unit-test
            PRIVATE
                "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>")
    target_link_libraries(${PROJECT_NAME}-collection-sr-unit-test
            PRIVATE
                ${PROJECT_NAME})
    add_test(${PROJECT_NAME}-collection-sr-unit-test
            ${PROJECT_NAME}-collection-sr-unit-test)
    # aquarium-butterflyfish-set-sr-unit-test
    add_executable(${PROJECT_NAME}-set-sr-unit-test test/test_set_sr.c)
    target_include_directories(${PROJECT_NAME}-set-sr-unit-test
            PRIVATE
                "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>")
    target_link_libraries(${PROJECT_NAME}-set-sr-unit-test
            PRIVATE
                ${PROJECT_NAME})
    add_test(${PROJECT_NAME}-set-sr-unit-test ${PROJECT_NAME}-set-sr-unit-test)
    # aquarium-butterflyfish-ordered-set-sr-unit-test
    add_executable(${PROJECT_NAME}-ordered-set-sr-unit-test
            test/test_ordered_set_sr.c)
    target_include_directories(${PROJECT_NAME}-ordered-set-sr-unit-test
            PRIVATE
                "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>")
    target_link_libraries(${PROJECT_NAME}-ordered-set-sr-unit-test
            PRIVATE
                ${PROJECT_NAME})
    add_test(${PROJECT_NAME}-ordered-set-sr-unit-test
            ${PROJECT_NAME}-ordered-set-sr-unit-test)
    # aquarium-butterflyfish-sorted-set-sr-unit-test
    add_executable(${PROJECT_NAME}-sorted-set-sr-unit-test
            test/test_sorted_set_sr.c)
    target_include_directories(${PROJECT_NAME}-sorted-set-sr-unit-test
            PRIVATE
                "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>")
    target_link_libraries(${PROJECT_NAME}-sorted-set-sr-unit-test
            PRIVATE
                ${PROJECT_NAME})
    add_test(${PROJECT_NAME}-sorted-set-sr-unit-test
            ${PROJECT_NAME}-sorted-set-sr-unit-test)
    # aquarium-butterflyfish-fixed-list-sr-unit-test
    add_executable(${PROJECT_NAME}-fixed-list-sr-unit-test
            test/test_fixed_list_sr.c)
    target_include_directories(${PROJECT_NAME}-fixed-list-sr-unit-test
            PRIVATE
                "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>")
    target_link_libraries(${PROJECT_NAME}-fixed-list-sr-unit-test
            PRIVATE
                ${PROJECT_NAME})
    add_test(${PROJECT_NAME}-fixed-list-sr-unit-test
            ${PROJECT_NAME}-fixed-list-sr-unit-test)
    # aquarium-butterflyfish-reducible-list-sr-unit-test
    add_executable(${PROJECT_NAME}-reducible-list-sr-unit-test
            test/test_reducible_list_sr.c)
    target_include_directories(${PROJECT_NAME}-reducible-list-sr-unit-test
            PRIVATE
                "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>")
    target_link_libraries(${PROJECT_NAME}-reducible-list-sr-unit-test
            PRIVATE
                ${PROJECT_NAME})
    add_test(${PROJECT_NAME}-reducible-list-sr-unit-test
            ${PROJECT_NAME}-reducible-list-sr-unit-test)
    # aquarium-butterflyfish-list-sr-unit-test
    add_executable(${PROJECT_NAME}-list-sr-unit-test test/test_list_sr.c)
    target_include_directories(${PROJECT_NAME}-list-sr-unit-test
            PRIVATE
                "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>")
    target_link_libraries(${PROJECT_NAME}-list-sr-unit-test
            PRIVATE
                ${PROJECT_NAME})
    add_test(${PROJECT_NAME}-list-sr-unit-test
            ${PROJECT_NAME}-list-sr-unit-test)
    # aquarium-butterflyfish-stream-sr-sr-unit-test
    add_executable(${PROJECT_NAME}-stream-sr-sr-unit-test
            test/test_stream_sr_sr.c)
    target_include_directories(${PROJECT_NAME}-stream-sr-sr-unit-test
            PRIVATE
                "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>")
    target_link_libraries(${PROJECT_NAME}-stream-sr-sr-unit-test
            PRIVATE
                ${PROJECT_NAME})
    add_test(${PROJECT_NAME}-stream-sr-sr-unit-test
            ${PROJECT_NAME}-stream-sr-sr-unit-test)
    # aquarium-butterflyfish-collection-sr-sr-unit-test
    add_executable(${PROJECT_NAME}-collection-sr-sr-unit-test
            test/test_collection_sr_sr.c)
    target_include_directories(${PROJECT_NAME}-collection-sr-sr-unit-test
            PRIVATE
                "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>")
    target_link_libraries(${PROJECT_NAME}-collection-sr-sr-unit-test
            PRIVATE
                ${PROJECT_NAME})
    add_test(${PROJECT_NAME}-collection-sr-sr-unit-test
            ${PROJECT_NAME}-collection-sr-sr-unit-test)
    # aquarium-butterflyfish-map-sr-sr-unit-test
    add_executable(${PROJECT_NAME}-map-sr-sr-unit-test
            test/test_map_sr_sr.c)
    target_include_directories(${PROJECT_NAME}-map-sr-sr-unit-test
            PRIVATE
                "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>")
    target_link_libraries(${PROJECT_NAME}-map-sr-sr-unit-test
            PRIVATE
                ${PROJECT_NAME})
    add_test(${PROJECT_NAME}-map-sr-sr-unit-test
            ${PROJECT_NAME}-map-sr-sr-unit-test)
    # aquarium-butterflyfish-ordered-map-sr-sr-unit-test
    add_executable(${PROJECT_NAME}-ordered-map-sr-sr-unit-test
            test/test_ordered_map_sr_sr.c)
    target_include_directories(${PROJECT_NAME}-ordered-map-sr-sr-unit-test
            PRIVATE
                "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>")
    target_link_libraries(${PROJECT_NAME}-ordered-map-sr-sr-unit-test
            PRIVATE
                ${PROJECT_NAME})
    add_test(${PROJECT_NAME}-ordered-map-sr-sr-unit-test
            ${PROJECT_NAME}-ordered-map-sr-sr-unit-test)
    # aquarium-butterflyfish-sorted-map-sr-sr-unit-test
    add_executable(${PROJECT_NAME}-sorted-map-sr-sr-unit-test
            test/test_sorted_map_sr_sr.c)
    target_include_directories(${PROJECT_NAME}-sorted-map-sr-sr-unit-test
            PRIVATE
                "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>")
    target_link_libraries(${PROJECT_NAME}-sorted-map-sr-sr-unit-test
            PRIVATE
                ${PROJECT_NAME})
    add_test(${PROJECT_NAME}-sorted-map-sr-sr-unit-test
            ${PROJECT_NAME}-sorted-map-sr-sr-unit-test)
    # aquarium-butterflyfish-reducible-queue-sr-unit-test
    add_executable(${PROJECT_NAME}-reducible-queue-sr-unit-test
            test/test_reducible_queue_sr.c)
    target_include_directories(${PROJECT_NAME}-reducible-queue-sr-unit-test
            PRIVATE
                "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>")
    target_link_libraries(${PROJECT_NAME}-reducible-queue-sr-unit-test
            PRIVATE
                ${PROJECT_NAME})
    add_test(${PROJECT_NAME}-reducible-queue-sr-unit-test
            ${PROJECT_NAME}-reducible-queue-sr-unit-test)
    # aquarium-butterflyfish-queue-sr-unit-test
    add_executable(${PROJECT_NAME}-queue-sr-unit-test test/test_queue_sr.c)
    target_include_directories(${PROJECT_NAME}-queue-sr-unit-test
            PRIVATE
                "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>")
    target_link_libraries(${PROJECT_NAME}-queue-sr-unit-test
            PRIVATE
                ${PROJECT_NAME})
    add_test(${PROJECT_NAME}-queue-sr-unit-test
            ${PROJECT_NAME}-queue-sr-unit-test)
    # aquarium-butterflyfish-reducible-stack-sr-unit-test
    add_executable(${PROJECT_NAME}-reducible-stack-sr-unit-test
            test/test_reducible_stack_sr.c)
    target_include_directories(${PROJECT_NAME}-reducible-stack-sr-unit-test
            PRIVATE
            "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>")
    target_link_libraries(${PROJECT_NAME}-reducible-stack-sr-unit-test
            PRIVATE
                ${PROJECT_NAME})
    add_test(${PROJECT_NAME}-reducible-stack-sr-unit-test
            ${PROJECT_NAME}-reducible-stack-sr-unit-test)
    # aquarium-butterflyfish-stack-sr-unit-test
    add_executable(${PROJECT_NAME}-stack-sr-unit-test test/test_stack_sr.c)
    target_include_directories(${PROJECT_NAME}-stack-sr-unit-test
            PRIVATE
                "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>")
    target_link_libraries(${PROJECT_NAME}-stack-sr-unit-test
            PRIVATE
                ${PROJECT_NAME})
    add_test(${PROJECT_NAME}-stack-sr-unit-test
            ${PROJECT_NAME}-stack-sr-unit-test)
    # aquarium-butterflyfish-stream-wr-unit-test
    add_executable(${PROJECT_NAME}-stream-wr-unit-test test/test_stream_wr.c)
    target_include_directories(${PROJECT_NAME}-stream-wr-unit-test
            PRIVATE
                "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>")
    target_link_libraries(${PROJECT_NAME}-stream-wr-unit-test
            PRIVATE
                ${PROJECT_NAME})
    add_test(${PROJECT_NAME}-stream-wr-unit-test
            ${PROJECT_NAME}-stream-wr-unit-test)
    # aquarium-butterflyfish-collection-wr-unit-test
    add_executable(${PROJECT_NAME}-collection-wr-unit-test
            test/test_collection_wr.c)
    target_include_directories(${PROJECT_NAME}-collection-wr-unit-test
            PRIVATE
                "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>")
    target_link_libraries(${PROJECT_NAME}-collection-wr-unit-test
            PRIVATE
                ${PROJECT_NAME})
    add_test(${PROJECT_NAME}-collection-wr-unit-test
            ${PROJECT_NAME}-collection-wr-unit-test)
    # aquarium-butterflyfish-fixed-list-wr-unit-test
    add_executable(${PROJECT_NAME}-fixed-list-wr-unit-test
            test/test_fixed_list_wr.c)
    target_include_directories(${PROJECT_NAME}-fixed-list-wr-unit-test
            PRIVATE
                "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>")
    target_link_libraries(${PROJECT_NAME}-fixed-list-wr-unit-test
            PRIVATE
                ${PROJECT_NAME})
    add_test(${PROJECT_NAME}-fixed-list-wr-unit-test
            ${PROJECT_NAME}-fixed-list-wr-unit-test)
    # aquarium-butterflyfish-reducible-list-wr-unit-test
    add_executable(${PROJECT_NAME}-reducible-list-wr-unit-test
            test/test_reducible_list_wr.c)
    target_include_directories(${PROJECT_NAME}-reducible-list-wr-unit-test
            PRIVATE
                "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>")
    target_link_libraries(${PROJECT_NAME}-reducible-list-wr-unit-test
            PRIVATE
                ${PROJECT_NAME})
    add_test(${PROJECT_NAME}-reducible-list-wr-unit-test
            ${PROJECT_NAME}-reducible-list-wr-unit-test)
    # aquarium-butterflyfish-list-wr-unit-test
    add_executable(${PROJECT_NAME}-list-wr-unit-test test/test_list_wr.c)
    target_include_directories(${PROJECT_NAME}-list-wr-unit-test
            PRIVATE
                "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>")
    target_link_libraries(${PROJECT_NAME}-list-wr-unit-test
            PRIVATE
                ${PROJECT_NAME})
    add_test(${PROJECT_NAME}-list-wr-unit-test
            ${PROJECT_NAME}-list-wr-unit-test)
    # aquarium-butterflyfish-reducible-queue-wr-unit-test
    add_executable(${PROJECT_NAME}-reducible-queue-wr-unit-test
            test/test_reducible_queue_wr.c)
    target_include_directories(${PROJECT_NAME}-reducible-queue-wr-unit-test
            PRIVATE
                "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>")
    target_link_libraries(${PROJECT_NAME}-reducible-queue-wr-unit-test
            PRIVATE
                ${PROJECT_NAME})
    add_test(${PROJECT_NAME}-reducible-queue-wr-unit-test
            ${PROJECT_NAME}-reducible-queue-wr-unit-test)
    # aquarium-butterflyfish-queue-wr-unit-test
    add_executable(${PROJECT_NAME}-queue-wr-unit-test test/test_queue_wr.c)
    target_include_directories(${PROJECT_NAME}-queue-wr-unit-test
            PRIVATE
                "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>")
    target_link_libraries(${PROJECT_NAME}-queue-wr-unit-test
            PRIVATE
                ${PROJECT_NAME})
    add_test(${PROJECT_NAME}-queue-wr-unit-test
            ${PROJECT_NAME}-queue-wr-unit-test)
    # aquarium-butterflyfish-reducible-stack-wr-unit-test
    add_executable(${PROJECT_NAME}-reducible-stack-wr-unit-test
            test/test_reducible_stack_wr.c)
    target_include_directories(${PROJECT_NAME}-reducible-stack-wr-unit-test
            PRIVATE
                "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>")
    target_link_libraries(${PROJECT_NAME}-reducible-stack-wr-unit-test
            PRIVATE
                ${PROJECT_NAME})
    add_test(${PROJECT_NAME}-reducible-stack-wr-unit-test
            ${PROJECT_NAME}-reducible-stack-wr-unit-test)
    # aquarium-butterflyfish-stack-wr-unit-test
    add_executable(${PROJECT_NAME}-stack-wr-unit-test test/test_stack_wr.c)
    target_include_directories(${PROJECT_NAME}-stack-wr-unit-test
            PRIVATE
                "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>")
    target_link_libraries(${PROJECT_NAME}-stack-wr-unit-test
            PRIVATE
                ${PROJECT_NAME})
    add_test(${PROJECT_NAME}-stack-wr-unit-test
            ${PROJECT_NAME}-stack-wr-unit-test)
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
