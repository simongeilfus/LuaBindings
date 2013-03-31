#pragma once

#include <luabind/luabind.hpp>
#include <luabind/detail/convert_to_lua.hpp>


extern "C" {
#include <lua/lua.h>
}


namespace lua {

	namespace Bindings {

		void bindStdVector( lua_State* state );
                
		template<class T>
		void stdVectorSet(std::vector<T>& vec, int i, T val){
			vec[i] = val;
		}
        
		template<class T>
		T stdVectorGet(std::vector<T>& vec, int i ){
			return vec[i];
		}
        
        
		template<class T>
		int stdVectorLast(std::vector<T>& vec ){
			return vec.size() - 1;
		}
        
        
		template<class T>
		int stdVectorErase(std::vector<T>& vec, int i ){
            if( i < vec.size() - 1 ){
                return std::distance( vec.begin(), vec.erase( vec.begin() + i ) );
            }
            
            return vec.size() + 1;
		}
        
        template<typename T>
        void bindStdVector( lua_State* state, const std::string& name )
        {
            luabind::module( state, "std" ) [
                                                       luabind::class_< std::vector<T> >( name.c_str() )
                                                       .def( luabind::constructor<>() )
                                                       .def( "push_back", ( void (std::vector<T>::*)(const T&) ) &std::vector<T>::push_back )
                                                       .def( "size", &std::vector<T>::size )
                                                       .def( "reserve", &std::vector<T>::reserve )
                                                       .def( "empty", &std::vector<T>::empty )
                                                       .def( "at", &stdVectorGet<T> )
                                                       .def( "set", &stdVectorSet<T> )
                                                       .def( "get", &stdVectorGet<T> )
                                                       .def( "last", &stdVectorLast<T> )
                                                       .def( "erase", &stdVectorErase<T> )
                                                       .def( "clear", &std::vector<T>::clear )
            ];
        }

	};

}

