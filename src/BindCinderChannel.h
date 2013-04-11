#pragma once

extern "C" {
#include <lua/lua.h>
}


namespace lua {
    
	namespace Bindings {
        
		void bindCinderChannel( lua_State* state );
        
    };
    
}

