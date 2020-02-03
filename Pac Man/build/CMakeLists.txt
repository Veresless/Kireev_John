cmake_minimum_required (VERSION 2.6) 
 
project (pac_man) 
 
file (GLOB 
	HS "../Code/Headers/*.h"
	CPPS "../Code/Sources/*.cpp") 
 
add_executable (${PROJECT_NAME} ${HS} ${SPPS})