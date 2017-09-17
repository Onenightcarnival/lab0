cmake_minimum_required(VERSION 3.8)
project(lab0_student)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        gtest/include/gtest/internal/custom/gtest-port.h
        gtest/include/gtest/internal/custom/gtest-printers.h
        gtest/include/gtest/internal/custom/gtest.h
        gtest/include/gtest/internal/gtest-death-test-internal.h
        gtest/include/gtest/internal/gtest-filepath.h
        gtest/include/gtest/internal/gtest-internal.h
        gtest/include/gtest/internal/gtest-linked_ptr.h
        gtest/include/gtest/internal/gtest-param-util-generated.h
        gtest/include/gtest/internal/gtest-param-util.h
        gtest/include/gtest/internal/gtest-port-arch.h
        gtest/include/gtest/internal/gtest-port.h
        gtest/include/gtest/internal/gtest-string.h
        gtest/include/gtest/internal/gtest-tuple.h
        gtest/include/gtest/internal/gtest-type-util.h
        gtest/include/gtest/gtest-death-test.h
        gtest/include/gtest/gtest-message.h
        gtest/include/gtest/gtest-param-test.h
        gtest/include/gtest/gtest-printers.h
        gtest/include/gtest/gtest-spi.h
        gtest/include/gtest/gtest-test-part.h
        gtest/include/gtest/gtest-typed-test.h
        gtest/include/gtest/gtest.h
        gtest/include/gtest/gtest_pred_impl.h
        gtest/include/gtest/gtest_prod.h
        gtest/src/gtest-all.cc
        gtest/src/gtest-death-test.cc
        gtest/src/gtest-filepath.cc
        gtest/src/gtest-internal-inl.h
        gtest/src/gtest-port.cc
        gtest/src/gtest-printers.cc
        gtest/src/gtest-test-part.cc
        gtest/src/gtest-typed-test.cc
        gtest/src/gtest.cc
        gtest/src/gtest_main.cc
        src/inverter.cpp
        src/inverter.h
        src/main.cpp
        test/inverter_tests.cpp)

add_executable(lab0_student ${SOURCE_FILES})