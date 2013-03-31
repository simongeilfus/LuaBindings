#pragma once

extern "C" {
#include <lua/lua.h>
}


namespace lua {

	namespace Bindings {
        
		void bindCinderResources( lua_State* state );
	
    };

}

