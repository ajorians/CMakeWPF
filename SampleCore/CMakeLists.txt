add_library(SampleCore STATIC
               Sample.cpp
               Sample.h
               ISample.h)

set_property(TARGET SampleCore PROPERTY CXX_STANDARD 20)