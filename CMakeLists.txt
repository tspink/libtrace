PROJECT(libtrace)

FIND_PACKAGE(Curses REQUIRED)

FILE(GLOB LIBTRACE_SOURCES lib/*.cpp)
ADD_LIBRARY(trace ${LIBTRACE_SOURCES})
TARGET_INCLUDE_DIRECTORIES(trace PUBLIC inc/ ${CURSES_INCLUDE_DIR})

SET_TARGET_PROPERTIES(trace
	PROPERTIES
		CXX_STANDARD 11
		CXX_STANDARD_REQUIRED YES
)

ADD_EXECUTABLE(TraceLess tools/RecordLess.cpp)
TARGET_LINK_LIBRARIES(TraceLess trace ${CURSES_LIBRARIES})

SET_TARGET_PROPERTIES(TraceLess
	PROPERTIES
		CXX_STANDARD 11
		CXX_STANDARD_REQUIRED YES
)

SET_PROPERTY(GLOBAL PROPERTY LIBTRACE_INCLUDES "${CMAKE_CURRENT_SOURCE_DIR}/inc")
