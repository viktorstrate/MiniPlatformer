project(MiniPlatformer)

set(SRCS
	Player.cpp
	Enemy.cpp
	Entity.cpp
	Test.cpp
	InputHandler.cpp
)

include_directories(".")

add_executable(MiniPlatformer ${SRCS})
target_link_libraries(MiniPlatformer ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARY})

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/game)

install(TARGETS MiniPlatformer DESTINATION game)
install(DIRECTORY ${CMAKE_SOURCE_DIR}/game/ DESTINATION game)

include(CPack)
