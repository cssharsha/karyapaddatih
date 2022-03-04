set(googlebenchmark_GIT_REPO "https://github.com/google/benchmark.git")
set(googlebenchmark_GIT_TAG "master")

if(CMAKE_VERSION VERSION_LESS 3.11)
    include(DownloadProject)
    download_project(
        PROJ googlebenchmark
        GIT_REPOSITORY ${googlebenchmark_GIT_REPO}
        GIT_TAG ${googlebenchmark_GIT_TAG})
    add_subdirectory(${googlebenchmark_SOURCE_DIR} ${googlebenchmark_BINARY_DIR})
else()
    include(FetchContent)
    FetchContent_Declare(googlebenchmark
        GIT_REPOSITORY ${googlebenchmark_GIT_REPO}
        GIT_TAG ${googlebenchmark_GIT_TAG})
    FetchContent_MakeAvailable(googlebenchmark)
endif()
