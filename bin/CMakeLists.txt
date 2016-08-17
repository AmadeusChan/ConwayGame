INCLUDE_DIRECTORIES(../include)
ADD_EXECUTABLE(ConwayGame main.cpp)
TARGET_LINK_LIBRARIES(ConwayGame CellsImpl)
