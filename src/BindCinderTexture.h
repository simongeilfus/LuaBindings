#pragma once

extern "C" {
#include <lua/lua.h>
}


namespace lua {

	namespace Bindings {
        
		void bindCinderTexture( lua_State* state );
	
    };

}

