lua-affinity
============

A Lua module used for controlling processor affinity on linux

For more details, check out sample.lua.

API:
---

#### mask,err=affinity.getaffinity(pid)
Get the affinity mask of the process associate with the pid.

#### mask,err=affinity.setaffinity(pid,mask)
Set the affinity mask of the process associate with the pid.


License
---

This module is licensed under the Apache license.
