# Otreblan website
# Copyright © 2025 Otreblan
#
# aru-web is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# aru-web is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with aru-web.  If not, see <http://www.gnu.org/licenses/>.

cmake_minimum_required(VERSION 3.13.0)

project(aru-web
	VERSION 0.0.0
	DESCRIPTION "Otreblan website"
	HOMEPAGE_URL "https://github.com/otreblan/aru-web"
)

# Default build type
if(NOT CMAKE_BUILD_TYPE)
	set(CMAKE_BUILD_TYPE "Debug")
endif()

include(GNUInstallDirs)
include(FindPkgConfig)
include(CPack)

# The program itself
add_executable(${PROJECT_NAME})

# C++ version
set_target_properties(${PROJECT_NAME}
	PROPERTIES
		CXX_STANDARD 20
)

# Packages
find_package(bash-completion)
find_package(Drogon)

add_subdirectory(src) # Sources list
add_subdirectory(doc) # Documentation
add_subdirectory(pkg) # Packaging

## Shared libraries
#pkg_check_modules(libraries
#	REQUIRED IMPORTED_TARGET
#		libfoo1
#		libfoo2
#)

# Linking
target_link_libraries(${PROJECT_NAME}
	PRIVATE
		Drogon::Drogon
#		PkgConfig::libraries
)

# Default flags
target_compile_options(${PROJECT_NAME}
	PRIVATE
		$<$<NOT:$<CXX_COMPILER_ID:MSVC>>:-Wall -Wextra>
)

# Bash completion
file(WRITE ${CMAKE_BINARY_DIR}/bash-completion/${PROJECT_NAME}
	"complete -F _longopt ${PROJECT_NAME}"
)

install(FILES
	${CMAKE_BINARY_DIR}/bash-completion/${PROJECT_NAME}
	DESTINATION ${BASH_COMPLETION_COMPLETIONSDIR}/
)

# Install target
install(TARGETS ${PROJECT_NAME}
	DESTINATION ${CMAKE_INSTALL_BINDIR}
)
