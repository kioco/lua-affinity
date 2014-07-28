#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>

#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <unistd.h>

#define _GNU_SOURCE
#include <sched.h>

#define DSERR() \
    lua_pushnil(L); \
    lua_pushstring(L,strerror(errno)); \
    return 2

static int getaffinity(lua_State *L){
    pid_t pid;
    pid=luaL_checknumber(L,1);

    unsigned long mask;
    unsigned int len = sizeof(mask);

    if((sched_getaffinity(pid, len, (cpu_set_t *)&mask))==-1){
        DSERR();
    }
    lua_pushnumber(L,mask);
    return 1;
}

static int setaffinity(lua_State *L){
    pid_t pid;
    pid=luaL_checknumber(L,1);

    unsigned long mask;
    unsigned int len = sizeof(mask);

    mask=luaL_checknumber(L,2);

    if((sched_setaffinity(pid, len, (cpu_set_t *)&mask))==-1){
        DSERR();
    }

    lua_pushnumber(L,mask);
    return 1;
}

static const struct luaL_Reg affinity[]={
    {"getaffinity",getaffinity},
    {"setaffinity",setaffinity},
    {NULL,NULL},
};

int luaopen_affinity(lua_State *L){
    luaL_register(L,"affinity",affinity);

    return 1;
}
