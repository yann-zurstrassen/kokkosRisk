cmake_minimum_required(VERSION 3.22)
project(KokkosRisk)


find_package(Kokkos CONFIG)
if(Kokkos_FOUND)
	messge(STATUS "Found Kokkos: ${Kokkos_DIR} (version \"${Kokkos_VERSION}\")")
else()
	message(STATUS "Kokkos not found externally. Fetching via FetchContent.")
	include(FetchContent)
	FetchContent_Declare(
		Kokkos
		URL https://github.com/kokkos/kokkos/archive/refs/tags/5.0.0.zip
	)
	FetchContent_MakeAvailable(Kokkos)
endif()


add_executable(HelloKokkos HelloKokkos.cpp)
target_link_libraries(HelloKokkos Kokkos::kokkos)
add_executable(Orstein OrnsteinUhlenbeck.cpp)
