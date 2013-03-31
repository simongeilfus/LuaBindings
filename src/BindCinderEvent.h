#pragma once

extern "C" {
#include <lua/lua.h>
}


namespace lua {
    
	namespace Bindings {
        
		void bindCinderEvents( lua_State* state );
        
	};
    
}

