set(googlelog_GIT_REPO "https://github.com/google/glog.git")
set(googlelog_GIT_TAG "master")

if(CMAKE_VERSION VERSION_LESS 3.11)
    include(DownloadProject)
    download_project(
        PROJ googlebenchmark
        GIT_REPOSITORY ${googlelog_GIT_REPO}
        GIT_TAG ${googlelog_GIT_TAG})
    add_subdirectory(${google_SOURCE_DIR} ${google_BINARY_DIR})
else()
    include(FetchContent)
    FetchContent_Declare(googlelog
        GIT_REPOSITORY ${googlelog_GIT_REPO}
        GIT_TAG ${googlelog_GIT_TAG})
    FetchContent_MakeAvailable(googlelog)
endif()
