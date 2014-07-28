require("posix")
pid=posix.getpid("pid")

require("affinity")
print(affinity.getaffinity(pid))
print(affinity.setaffinity(pid,1))
print(affinity.getaffinity(pid))
