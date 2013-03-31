#include "BindCinderRand.h"

#include "cinder/Rand.h"

#include <luabind/luabind.hpp>

using namespace ci;
using namespace std;
using namespace luabind;

namespace lua { namespace Bindings {
    
    
    void bindCinderRand( lua_State* state ){
        
        module( state ) [
                                           
                                           def( "randSeed", Rand::randSeed ),
                                           def( "randBool", Rand::randBool ),
                                           def( "randInt", ( int(*) () ) Rand::randInt ),
                                           def( "randInt", ( int(*) (int) ) Rand::randInt ),
                                           def( "randInt", ( int(*) (int, int) ) Rand::randInt ),
                                           def( "randFloat", ( float(*) () ) Rand::randFloat ),
                                           def( "randFloat", ( float(*) (float) ) Rand::randFloat ),
                                           def( "randFloat", ( float(*) (float, float) ) Rand::randFloat ),
                                           def( "randPosNegFloat", Rand::randPosNegFloat ),
                                           def( "randVec3f", Rand::randVec3f),
                                           def( "randVec2f", Rand::randVec2f)
                                           ];
    }
    
}}
