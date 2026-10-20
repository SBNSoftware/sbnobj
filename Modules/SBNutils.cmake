#
# File:    SBNmacros.cmake
# Purpose: Helpers for CMake actions in SBN.
# Author:  Gianluca Petrillo (petrillo@slac.stanford.edu)
# Date:    January 17, 2025
#

include_guard()

cmake_minimum_required(VERSION 3.27 FATAL_ERROR)

function(GetGITrepoName OutputVariableName)
  #
  # Gets the name of the current repository from the remote source `origin `URL.
  # 
  # In case of failure from GIT call, the project name will be returned.
  #
  set(RepoDir ${CMAKE_CURRENT_SOURCE_DIR})
  
  execute_process(COMMAND git -C "${RepoDir}" remote get-url origin
    OUTPUT_VARIABLE GITrepoURL OUTPUT_STRIP_TRAILING_WHITESPACE
    ERROR_QUIET RESULT_VARIABLE ErrorCode
    )
  if(ErrorCode)
    message(WARNING "Failed to retrieve GIT repository name for ${CMAKE_PROJECT_NAME} (error code ${ErrorCode})")
    set(${OutputVariableName} "${CMAKE_PROJECT_NAME}")
  else()
    cmake_path(GET GITrepoURL STEM ${OutputVariableName})
  endif()
  
  return(PROPAGATE ${OutputVariableName})
  
endfunction(GetGITrepoName)


function(GetGITrepoVersion OutputVariableName)
  #
  # Gets the version/tag of the current branch in the current repository
  # using `git describe`.
  #
  # In case of failure from GIT call, a error code will be returned in the
  # variable.
  #
  set(RepoDir ${CMAKE_CURRENT_SOURCE_DIR})
  
  execute_process(COMMAND git -C "${RepoDir}" describe --tags --dirty
    OUTPUT_VARIABLE ${OutputVariableName} OUTPUT_STRIP_TRAILING_WHITESPACE
    ERROR_QUIET RESULT_VARIABLE ErrorCode
    )
  
  if(ErrorCode)
    set(${OutputVariableName} "n/a (GIT error code: ${ErrorCode})")
  endif()
  
  return(PROPAGATE ${OutputVariableName})
  
endfunction(GetGITrepoVersion)


function(GenerateRepoVersionSource OutputPrefix)
  #
  # GenerateRepoVersionSource [OUTPUT_PREFIX prefix]
  #   * OUTPUT_PREFIX: prefix to the output variable names; default: ${CMAKE_PROJECT_NAME}
  #
  # Will generate a C++ header and source with the GIT repository describe
  # string stored in a constant, using the `GITrepoVersion.{h,cxx}.in` template.
  # The resulting code is written into ${CMAKE_CURRENT_BINARY_DIR} directory.
  # In addition, it will set three variables:
  #   <prefix>_GIT_REPO_NAME (typically matches the project name)
  #   <prefix>_GIT_REPO_VERSION (GIT describe output)
  #   <prefix>_GIT_REPO_VERSION_SOURCE (stem of the generated source code name);
  #     the actual files have the suffixes `.h` and `.cxx`
  #
  
  if(NOT OutputPrefix)
    set(OutputPrefix ${CMAKE_PROJECT_NAME})
  endif()
  
  if(OutputPrefix)
    set(OutputPrefix "${OutputPrefix}_")
  endif()
  
  # we could use `${CMAKE_PROJECT_NAME}`, provided that is up to date
  GetGITrepoName(gitRepoName)
  
  GetGITrepoVersion(gitRepoVersion)
  
  set(gitRepoVersionSourceStem "RepositoryVersion_${gitRepoName}")
  message(STATUS "GIT reported repository: ${gitRepoName} ${gitRepoVersion} (=> '${gitRepoVersionSourceStem}{.h,.cxx}')")
  configure_file("GITrepoVersion.h.in" "${gitRepoVersionSourceStem}.h")
  configure_file("GITrepoVersion.cxx.in" "${gitRepoVersionSourceStem}.cxx")
  
  # these are the output variables
  set("${OutputPrefix}GIT_REPO_NAME"           "${gitRepoName}"              PARENT_SCOPE)
  set("${OutputPrefix}GIT_REPO_VERSION"        "${gitRepoVersion}"           PARENT_SCOPE)
  set("${OutputPrefix}GIT_REPO_VERSION_SOURCE" "${gitRepoVersionSourceStem}" PARENT_SCOPE)
  
endfunction(GenerateRepoVersionSource)
