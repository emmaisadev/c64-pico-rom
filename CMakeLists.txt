cmake_minimum_required(VERSION 3.13)

# Generate ROM source files from ext directory
#execute_process(
#  COMMAND xxd -i -n stock_rom ext/901227-03.bin > roms/stock.c
#  WORKING_DIRECTORY ..
#)

# initialize the SDK directly
include(/usr/share/pico-sdk/pico_sdk_init.cmake)

project(my_project)

# initialize the Raspberry Pi Pico SDK
pico_sdk_init()

# rest of your project

add_executable(romemu
  main.c
)

target_link_libraries(romemu pico_stdlib)

pico_add_extra_outputs(romemu)
