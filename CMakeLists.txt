cmake_minimum_required(VERSION 3.15)
project(Mi6_3)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(src)
include_directories(src/main)
include_directories(src/test)

add_executable(Mi6_3
        src/main/CocktailPro.cpp
        src/main/CocktailPro.h
        src/main/CocktailZubereiter.cpp
        src/main/CocktailZubereiter.h
        src/main/DeviceVerwalter.cpp
        src/main/DeviceVerwalter.h
        src/main/Dosierer.cpp
        src/main/Dosierer.h
        src/main/Entleerer.cpp
        src/main/Entleerer.h
        src/main/InternalDevice.cpp
        src/main/InternalDevice.h
        src/main/Main.cpp
        src/main/MischbaresRezeptbuch.cpp
        src/main/MischbaresRezeptbuch.h
        src/main/Mixer.cpp
        src/main/Mixer.h
        src/main/Observer.h
        src/main/Recipe.cpp
        src/main/Recipe.h
        src/main/RecipeBook.cpp
        src/main/RecipeBook.h
        src/main/RecipeStep.cpp
        src/main/RecipeStep.h
        src/main/Schuettler.cpp
        src/main/Schuettler.h
        src/main/Stampfer.cpp
        src/main/Stampfer.h
        src/main/Subject.cpp
        src/main/Subject.h
        src/main/Timer.cpp
        src/main/Timer.h
        src/main/VorhandeneZutaten.cpp
        src/main/VorhandeneZutaten.h
        src/main/Waage.cpp
        src/main/Waage.h
        src/test/Main.cpp
        src/test/RecipeBook_Test.cpp
        src/test/VorhandeneZutaten_Test.cpp)
