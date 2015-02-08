if(MSVC)
    set(CMAKE_C_FLAGS_DEBUG_INIT          "/D_DEBUG /MTd /Zi /Ob0 /Od /RTC1")
    set(CMAKE_C_FLAGS_MINSIZEREL_INIT     "/MT /O1 /Ob1 /D NDEBUG")
    set(CMAKE_C_FLAGS_RELEASE_INIT        "/MT /O2 /Ob2 /D NDEBUG")
    set(CMAKE_C_FLAGS_RELWITHDEBINFO_INIT "/MT /Zi /O2 /Ob1 /D NDEBUG")
endif()

if(MINGW)
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -static-libgcc -static")
endif()

