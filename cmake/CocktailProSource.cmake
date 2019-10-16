# Add all main sources excluding the file holding the main function
add_library(CocktailProSource STATIC
        ../src/main/CocktailPro.cpp
        ../src/main/CocktailPro.h
        ../src/main/CocktailZubereiter.cpp
        ../src/main/CocktailZubereiter.h
        ../src/main/DeviceVerwalter.cpp
        ../src/main/DeviceVerwalter.h
        ../src/main/Dosierer.cpp
        ../src/main/Dosierer.h
        ../src/main/Entleerer.cpp
        ../src/main/Entleerer.h
        ../src/main/InternalDevice.cpp
        ../src/main/InternalDevice.h
        ../src/main/MischbaresRezeptbuch.cpp
        ../src/main/MischbaresRezeptbuch.h
        ../src/main/Mixer.cpp
        ../src/main/Mixer.h
        ../src/main/Observer.h
        ../src/main/Recipe.cpp
        ../src/main/Recipe.h
        ../src/main/RecipeBook.cpp
        ../src/main/RecipeBook.h
        ../src/main/RecipeStep.cpp
        ../src/main/RecipeStep.h
        ../src/main/Schuettler.cpp
        ../src/main/Schuettler.h
        ../src/main/Stampfer.cpp
        ../src/main/Stampfer.h
        ../src/main/Subject.cpp
        ../src/main/Subject.h
        ../src/main/Timer.cpp
        ../src/main/Timer.h
        ../src/main/VorhandeneZutaten.cpp
        ../src/main/VorhandeneZutaten.h
        ../src/main/Waage.cpp
        ../src/main/Waage.h
        )

# Adds a bunch of flags, enabling some compiler warnings
addCompilerWarningFlags(CocktailProSource)
# Link CocktailProSource against TinyXML2
# linkTinyXML2(CocktailProSource)

# Resources will be copied before building CocktailProSource
add_dependencies(CocktailProSource CocktailProResource)
