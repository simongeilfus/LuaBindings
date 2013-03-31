#include "BindCinderPerlin.h"

#include "cinder/Perlin.h"

#include <luabind/luabind.hpp>

using namespace ci;
using namespace std;
using namespace luabind;

namespace lua { namespace Bindings {
        
    static ci::Perlin perlin;
	
    static void	setSeed( int aSeed ){ perlin.setSeed( aSeed ); }
    static int	getOctaves() { return perlin.getOctaves(); }
    static void	setOctaves( int aOctaves ) { perlin.setOctaves( aOctaves ); }
    
    static float	fBm( float v ) { return perlin.fBm( v ); }
    static float	fBm( const ci::Vec2f &v ) { return perlin.fBm( v ); }
    static float	fBm( float x, float y )  { return perlin.fBm( x, y ); }
    static float	fBm( const ci::Vec3f &v )  { return perlin.fBm( v ); }
    static float	fBm( float x, float y, float z )  { return perlin.fBm( x, y, z ); }
    
    /// Derivative of fractal Brownian motion, corresponding with the values returned by fBm()
    static ci::Vec2f	dfBm( const ci::Vec2f &v )  { return perlin.dfBm( v ); }
    static ci::Vec2f	dfBm( float x, float y )  { return perlin.dfBm( x, y ); }
    static ci::Vec3f	dfBm( const ci::Vec3f &v )  { return perlin.dfBm( v ); }
    static ci::Vec3f	dfBm( float x, float y, float z )  { return perlin.dfBm( x, y, z ); }
    
    /// Calculates a single octave of noise
    static float	noise( float x ) { return perlin.noise( x ); }
    static float	noise( float x, float y ) { return perlin.noise( x, y ); }
    static float	noise( float x, float y, float z ) { return perlin.noise( x, y, z ); }
    
    /// Calculates the derivative of a single octave of noise
    static ci::Vec2f	dnoise( float x, float y ) { return perlin.dnoise( x, y ); }
    static ci::Vec3f	dnoise( float x, float y, float z ) { return perlin.dnoise( x, y, z ); }
    
    void bindCinderPerlin( lua_State* state ){
        
        module( state, "Perlin" ) [
                                             
                                             def( "setSeed", &setSeed ),
                                             def( "getOctaves", &getOctaves ),
                                             def( "setOctaves", &setOctaves ),
                                             def( "fBm", ( float(*)(float)  ) &fBm ),
                                             def( "fBm", ( float(*)(const Vec2f&)  ) &fBm ),
                                             def( "fBm", ( float(*)(float,float)  ) &fBm ),
                                             def( "fBm", ( float(*)(const Vec3f&)  ) &fBm ),
                                             def( "fBm", ( float(*)(float,float,float)  ) &fBm ),
                                             def( "dfBm", ( Vec2f(*)(const Vec2f&)  ) &dfBm ),
                                             def( "dfBm", ( Vec2f(*)(float,float)  ) &dfBm ),
                                             def( "dfBm", ( Vec3f(*)(const Vec3f&)  ) &dfBm ),
                                             def( "dfBm", ( Vec3f(*)(float,float,float)  ) &dfBm ),
                                             def( "noise", ( float(*)(float)  ) &noise ),
                                             def( "noise", ( float(*)(float,float)  ) &noise ),
                                             def( "noise", ( float(*)(float,float,float)  ) &noise ),
                                             def( "dnoise", ( Vec2f(*)(float,float)  ) &dnoise ),
                                             def( "dnoise", ( Vec3f(*)(float,float,float)  ) &dnoise )
                                             ];
    }
    
}}
