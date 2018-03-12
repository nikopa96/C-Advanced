find_library(gtest REQUIRED)

include_directories(${gtest_SOURCE_DIR}/include)

set(TESTS ../tests/testNumber.cpp ../tests/testPoint.cpp ../tests/testLine.cpp ../tests/testCircle.cpp ../tests/testVector.cpp)
set(SOURCES main.cpp number.cpp point.cpp line.cpp circle.cpp vector.cpp)
set(HEADERS number.hpp point.hpp line.hpp circle.hpp vector.hpp)

add_executable(Prax02 ${SOURCES} ${HEADERS} ${TESTS} )
target_link_libraries(Prax02 gtest)