#pragma once

extern "C" {
#include <lua/lua.h>
}


namespace lua {

	namespace Bindings {
        
		void bindCinderArea( lua_State* state );
        
	};

}

