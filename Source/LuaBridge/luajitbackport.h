// 5.1 backport of 5.2 stuff

#include <lua.h>


#define lua_absindex(L, i) (((i) > 0 || (i) < LUA_REGISTRYINDEX) ? (i) : lua_gettop(L)+(i)+1)

inline LUA_API void lua_rawgetp (lua_State *L, int idx, const void *p) {

    idx = lua_absindex(L, idx);
    lua_pushlightuserdata(L, (void *) p);
    lua_rawget(L,idx);

}

inline LUA_API void lua_rawsetp (lua_State *L, int idx, const void *p) {

    idx = lua_absindex(L, idx);
    lua_pushlightuserdata(L, (void*) p);
    // put key behind value
    lua_insert(L, -2);
    lua_rawset(L,idx);
}