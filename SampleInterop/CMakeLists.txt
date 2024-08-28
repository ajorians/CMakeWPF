if (MSVC)
    # Use /clr option to enable C++/CLI
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /clr")

    # Replace /EHs with /EHa for exception handling
    string(REPLACE "/EHs" "/EHa" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

    # Remove /RTC1 as it is incompatible with /clr
    string(REPLACE "/RTC1" "" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

    # Ensure /RTC1 is not present in debug builds by modifying CMAKE_CXX_FLAGS_DEBUG
    string(REPLACE "/RTC1" "" CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG}")
else()
    message(FATAL_ERROR "C++/CLI is only supported with MSVC.")
endif()

add_library(SampleInterop SHARED
               Interop.cpp
               Interop.h)

target_include_directories(SampleInterop PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../)

set_target_properties(SampleInterop PROPERTIES COMMON_LANGUAGE_RUNTIME "")
set_property(TARGET SampleInterop PROPERTY CXX_STANDARD 20)

target_link_libraries(SampleInterop PRIVATE SampleCore)