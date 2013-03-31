#pragma once

extern "C" {
#include <lua/lua.h>
}


namespace lua {

	namespace Bindings {
        
		void bindCinderRand( lua_State* state );
	
    };

}

