cmake_minimum_required (VERSION 2.6) 
 
project (pac_man) 
 
file (GLOB 
	HS "src/*.h"
	CPPS "scr/*.cpp") 
 
add_executable (${PROJECT_NAME} ${HS} ${SPPS})
