cmake_minimum_required(VERSION 2.6)
PROJECT(hell_rush_purgatory_etape1)

ADD_EXECUTABLE(
	test_dynamic_fsa
	Edge.cpp
	Edge.h
	State.cpp
	State.h
	FSA.cpp
	FSA.h
	Matcher.cpp
	Matcher.h
	main.cpp
)
#SET(EXECUTABLE_OUTPUT_PATH ..)
